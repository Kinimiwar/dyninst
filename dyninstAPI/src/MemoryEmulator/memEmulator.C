/*
 * Copyright (c) 1996-2009 Barton P. Miller
 * 
 * We provide the Paradyn Parallel Performance Tools (below
 * described as "Paradyn") on an AS IS basis, and do not warrant its
 * validity or performance.  We reserve the right to update, modify,
 * or discontinue this software at any time.  We shall have no
 * obligation to supply such updates or modifications or any other
 * form of support to you.
 * 
 * By your use of Paradyn, you understand and agree that we (or any
 * other person or entity with proprietary rights in Paradyn) are
 * under no obligation to provide either maintenance services,
 * update services, notices of latent defects, or correction of
 * defects for Paradyn.
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include "parseAPI/h/CodeObject.h"
#include "dyninstAPI/src/addressSpace.h"
#include "memEmulator.h"
#include "dyninstAPI/src/mapped_object.h"
#include "dyninstAPI/src/symtab.h"
#include "symtabAPI/h/Symtab.h"
#include "symtabAPI/h/Region.h"
#include "dyninstAPI/src/process.h"
#include "dyninstAPI/src/function.h"

using namespace Dyninst;
using namespace SymtabAPI;

bool MemoryEmulator::findMutateeTable() {
   if (mutateeBase_ != 0) return true;

   std::vector<int_variable *> memoryMapperTable;
   if (!aS_->findVarsByAll("RTmemoryMapper", memoryMapperTable)) {
      return false;
   }

   if (memoryMapperTable.size() > 1) {
      // ???
      return false;
   }
   mutateeBase_ = memoryMapperTable[0]->getAddress();
   return true;
}

void MemoryEmulator::update() {
   if (!findMutateeTable()) return;

   // 1) Create shadow copies for any MappedObject we
   // have modified.
   // 2) Update the runtime's MemoryMapper structure
   // to correspond to this.

   // First step: nonblocking synchro.
   int guardValue;
   aS_->readDataSpace((void *)mutateeBase_,
                      sizeof(int),
                      &guardValue,
                      false);
   guardValue++;
   aS_->writeDataSpace((void *)mutateeBase_,
                       sizeof(int),
                       &guardValue);
   
   sensitivity_cerr << "UpdateMemEmulator: writing guard value " << guardValue << endl;
      // 64->32 bit is annoying...
   if (addrWidth() == 4) {
      struct MemoryMapper32 newMapper;
      
      aS_->readDataSpace((void *)mutateeBase_,
                         sizeof(newMapper),
                         &newMapper,
                         false);
      
      // First step: 
      newMapper.guard1 = guardValue;
      newMapper.guard2 = guardValue;
      newMapper.size = memoryMap_.size();
      sensitivity_cerr << "\t new values: " << newMapper.guard1 << "/" << newMapper.guard2 << "/" << newMapper.size << endl;
      std::vector<MemoryMapTree::Entry> elements;
      memoryMap_.elements(elements);
      for (unsigned i = 0; i < elements.size(); ++i) {
         newMapper.elements[i].lo = elements[i].first.first;
         newMapper.elements[i].hi = elements[i].first.second;
         assert(newMapper.elements[i].hi > newMapper.elements[i].lo);
         newMapper.elements[i].shift = elements[i].second;
         sensitivity_cerr << "\t\t Element: " << hex << newMapper.elements[i].lo << "->" << newMapper.elements[i].hi << ": " << newMapper.elements[i].shift << dec << endl;
      }
      aS_->writeDataSpace((void *)mutateeBase_,
                          sizeof(newMapper),
                          &newMapper);
   }
   else {
      // TODO copy
      //assert(0);
   }
}

void MemoryEmulator::addAllocatedRegion(Address start, unsigned size) {
   addRegion(start, size, -1);
}

void MemoryEmulator::addRegion(mapped_object *obj) {
   cerr << "addRegion for " << obj->fileName() << endl;

   // Add each code region
   std::vector<Region *> codeRegions;
   obj->parse_img()->getObject()->getCodeRegions(codeRegions);

   for (unsigned i = 0; i < codeRegions.size(); ++i) {
      Region *reg = codeRegions[i];

      addRegion(reg, obj->codeBase());
   }         
}

void MemoryEmulator::removeRegion(mapped_object *obj) {
	cerr << "Removing region " << obj->fileName() << endl;
	cerr << "\t Before: " << endl;
	debug();
	// Remove each code region
	std::vector<Region *> codeRegions;
	obj->parse_img()->getObject()->getCodeRegions(codeRegions);

	for (unsigned i = 0; i < codeRegions.size(); ++i) {
		Region *reg = codeRegions[i];

		removeRegion(reg, obj->codeBase());
	}
	cerr << "\t After: " << endl;
	debug();
}

void MemoryEmulator::addRegion(Region *reg, Address base) {
   
   cerr << "\t\t Region " << hex
   << reg->getMemOffset() << " -> " 
   << reg->getMemOffset() + reg->getMemSize() << endl;
   
   if (addedRegions_.find(reg) != addedRegions_.end()) return;
      
   process *proc = dynamic_cast<process *>(aS_);
   char *buffer = (char *)malloc(reg->getMemSize());
   if (proc) {
       if (!proc->readDataSpace((void*)(base + reg->getMemOffset()), 
                               reg->getMemSize(), buffer, false)) {
           assert(0);
       }
   } else {
       memset(buffer, 0, reg->getMemSize());
       memcpy(buffer, reg->getPtrToRawData(), reg->getDiskSize());
   }
   
   unsigned long allocSize = reg->getMemSize();
   if (proc) {
      allocSize += proc->getMemoryPageSize();
   }
   
   Address mutateeBase = aS_->inferiorMalloc(allocSize);
   assert(mutateeBase);
   
   // "Upcast" it to align with a page boundary - Kevin's request
   if (proc) {         
      mutateeBase += proc->getMemoryPageSize();
      mutateeBase -= mutateeBase % proc->getMemoryPageSize();
   }
   
   
   aS_->writeDataSpace((void *)mutateeBase,
                       reg->getMemSize(),
                       (void *)buffer);
   if (aS_->proc() && BPatch_defensiveMode == aS_->proc()->getHybridMode()) {
#if defined (os_windows)
       using namespace SymtabAPI;
       unsigned winrights = 0;
       Region::perm_t reg_rights = reg->getRegionPermissions();
       switch (reg_rights) {
       case Region::RP_R:
           winrights = PAGE_READONLY;
           break;
       case Region::RP_RW: 
           winrights = PAGE_READWRITE;
           break;
       case Region::RP_RX:
           winrights = PAGE_EXECUTE_READ;
           break;
       case Region::RP_RWX:
           winrights = PAGE_EXECUTE_READWRITE;
           break;
       default:
           assert(0);
       }
       dyn_lwp *stoppedlwp = aS_->proc()->query_for_stopped_lwp();
       assert(stoppedlwp);
       stoppedlwp->changeMemoryProtections(mutateeBase, reg->getMemSize(), winrights, false);
#endif
   }
   
    Address regionBase = base + reg->getMemOffset();

    sensitivity_cerr << hex << " Adding region with base " << base << " and mem offset " << reg->getMemOffset()
        << ", allocated buffer base " << mutateeBase << " and so shift " << mutateeBase - regionBase << dec << endl;

   addRegion(regionBase,
             reg->getMemSize(),
             mutateeBase - regionBase);
   
   cerr << "Added region: first " << hex << base + reg->getMemOffset() <<  ", second " << mutateeBase << dec << endl;
   addedRegions_[reg] = std::make_pair(base + reg->getMemOffset(), mutateeBase);
   free(buffer);
}

void MemoryEmulator::removeRegion(Region *reg, Address base) {
   
   //cerr << "\t\t Region " << i << ": " << hex
   //<< codeRegions[i]->getMemOffset() + obj->codeBase() << " -> " 
   //<< codeRegions[i]->getMemOffset() + codeRegions[i]->getMemSize() + obj->codeBase() << endl;
   
	RegionMap::iterator iter = addedRegions_.find(reg);
	if (iter == addedRegions_.end()) return;

	// First, nuke our track of the springboards
	springboards_.erase(reg);

    // Second, nuke it from the list of regions to copy on a sync
    addedRegions_.erase(reg);

   // Deallocate the shadow pages in the mutatee
   //  -- this is TODO; we mangle the allocation base and therefore can't
   //     really call inferiorfree on it. 

   // Remove the region from the translation map
   removeRegion(base + reg->getMemOffset(), reg->getMemSize());
}

void MemoryEmulator::addRegion(Address start, unsigned size, Address shift) {
   if (size == 0) return;
   //cerr << "MemoryEmulator: adding region " << hex << start << " : " << size << " /w/ shift " << shift << dec << endl;
   //debug();
   //cerr << endl;
   Address end = start + size;
   assert(end > start);

   // Okay. For efficiency, we want to merge this if possible with an existing
   // range. We do this because our allocation tends to be contiguous.
   // Two options: we're immediately above an existing range or we're immediately
   // below. Check both. 


   Address lb, ub;
   unsigned long val;
   if (memoryMap_.find(start, lb, ub, val)) {
      // This is possibly very bad. 
      if (start != ub) {
         if ((start == lb) &&
             (end == ub) &&
             (val == shift)) {
            return;
         }
         // Yeah, data inconsistency == bad
         assert(0);
      }
      if (val == shift) {
         // Accumulate
         memoryMap_.remove(lb);
         memoryMap_.insert(lb, end, shift);
         return;
      }
      else {
         memoryMap_.insert(start, end, shift);
      }
   }
   else if (memoryMap_.find(end, lb, ub, val)) {
      // See the above
      if (end != ub) {
         fprintf(stderr, "ERROR: adding range 0x%lx -> 0x%lx (0x%lx), found range 0x%lx -> 0x%lx (0x%lx)\n",
                 start, end, shift, lb, ub, val);

         assert(0);
      }
      if (val == shift) {
         memoryMap_.remove(lb);
         memoryMap_.insert(start, ub, shift);
      }
      else {
         memoryMap_.insert(start, end, shift);
      }
   }
   else {
      memoryMap_.insert(start, end, shift);
   }

   if (shift != (unsigned long) -1) {
      reverseMemoryMap_.insert(start + shift, end + shift, shift);
   }
   //debug();
   return;   
}

void MemoryEmulator::removeRegion(Address addr, unsigned size) {
	Address lb = 0, ub = 0;
	unsigned long shiftVal;

	//cerr << "MemoryEmulator: removing region " << hex << addr << " : " << size << dec << endl;

   //debug();
   //cerr << endl;

	Address lowLB = 0, lowUB = 0, hiLB = 0, hiUB = 0;

	// We are guaranteed to be either our own allocated range or
	// coalesced with another range. 
	if (!memoryMap_.find(addr, lb, ub, shiftVal)) {
		return;
	}

	if ((lb != 0) && (lb < addr)) {
		lowLB = lb;
		lowUB = addr;
	}
	if ((ub != 0) && (ub > (addr + size))) {
		hiLB = (addr + size);
		hiUB = ub;
	}
	memoryMap_.remove(lb);
	if (lowLB || lowUB) {
		memoryMap_.insert(lowLB, lowUB, shiftVal);
	}
	if (hiLB || hiUB) {
		memoryMap_.insert(hiLB, hiUB, shiftVal);
	}
	
	reverseMemoryMap_.remove(addr + shiftVal);
	//debug();
}

unsigned MemoryEmulator::addrWidth() {
   return aS_->getAddressWidth();
}

std::pair<bool, Address> MemoryEmulator::translate(Address orig) {
   // Mimic the translation performed in the RT library
   Address lb, ub;
   unsigned long val;
   if (!memoryMap_.find(orig, lb, ub, val)) {
      return std::make_pair(false, 0);
   }
   if (val == (unsigned long) -1) {
      return std::make_pair(true, orig);
   }
   return std::make_pair(true, orig + val);
}

std::pair<bool, Address> MemoryEmulator::translateBackwards(Address addr) {
   // Mimic the translation performed in the RT library
   Address lb, ub;
   unsigned long val;
   if (!reverseMemoryMap_.find(addr, lb, ub, val)) {
      return std::make_pair(false, 0);
   }
   if (val == (unsigned long) -1) {
      return std::make_pair(true, addr);
   }
   return std::make_pair(true, addr - val);
}

void MemoryEmulator::synchShadowOrig(bool toOrig) 
{
    if (toOrig) {
        malware_cerr << "Syncing shadow to orig" << endl;
    }
    else {
        malware_cerr << "Syncing orig to shadow" << endl;
    }

    using namespace SymtabAPI;

    for (RegionMap::iterator iter = addedRegions_.begin();
        iter != addedRegions_.end(); ++iter) {
        Region * reg = iter->first;
        unsigned char* regbuf = (unsigned char*) malloc(reg->getMemSize());
        Address from = 0;
        Address toBase = 0;
        if (toOrig) {
            from = iter->second.second;
            toBase = iter->second.first;
        } else {
            from = iter->second.first;
            toBase = iter->second.second;
        }
        if (!aS_->readDataSpace((void *)from,
                                reg->getMemSize(),
                                regbuf,
                                false)) 
        {
            assert(0);
        }
        if (toOrig) {
            if (saved[reg]) {
                free(saved[reg]);
            }
            saved[reg] = regbuf;
        }

        Address cp_start = 0;

        std::map<Address,int>::const_iterator sit = springboards_[reg].begin();
        for (; sit != springboards_[reg].end(); sit++) {
            // We purposefully have an overlapping datastructure, so this assert is 
            // commented out.
            //assert(cp_start <= sit->first);

            if ((sit->first + sit->second) < cp_start) continue;

            //cerr << "\t Start @ " << hex << cp_start << " and next springboard " << sit->first << dec << endl;
            int cp_size = sit->first - cp_start;

            //cerr << "\t Write [" << hex << toBase + cp_start << "," << toBase + cp_start + cp_size  << ")" << dec << endl;
            if (cp_size > 0) {
                if (!toOrig && saved[reg]) {
                    // Consistency check
                    for (unsigned i = cp_start; i < cp_start + cp_size; ++i) {
                        if (regbuf[i] != saved[reg][i]) {
                            cerr << "Warning: difference at addr " << hex << from + i << ": cached " << (int) saved[reg][i] << " and current " << (int)regbuf[i] << dec << endl;
                        }
                    }
                }
                if (!aS_->writeDataSpace((void *)(toBase + cp_start),
                    cp_size,
                    regbuf + cp_start)) assert(0);

            }
            cp_start = sit->first + sit->second;
        }
        //cerr << "\t Finishing write " << hex << toBase + cp_start << " -> " << toBase + cp_start + reg->getMemSize() - cp_start << dec << endl;

        if (cp_start < reg->getMemSize())
        {
            if (!toOrig && saved[reg]) {
                // Consistency check
                for (unsigned i = cp_start; i < reg->getMemSize(); ++i) {
                    if (regbuf[i] != saved[reg][i]) {
                        cerr << "Warning: difference at addr " << hex << from + i << ": cached " << (int) saved[reg][i] << " and current " << (int)regbuf[i] << dec << endl;
                    }
                }
            }
            if (!aS_->writeDataSpace((void *)(toBase + cp_start),
                reg->getMemSize() - cp_start,
                regbuf + cp_start)) assert(0);
        }
    }
}


void MemoryEmulator::addSpringboard(Region *reg, Address offset, int size) 
{
    // Look up whether there is a previous springboard that overlaps with us; 
    // clearly, it's getting removed. 

    std::map<SymtabAPI::Region *, std::map<Address, int> >::iterator s_iter = springboards_.find(reg);
    if (s_iter == springboards_.end()) {
        springboards_[reg][offset] = size;
        return;
    }
    std::map<Address, int> &smap = s_iter->second;

    //cerr << "Inserting SB [" << hex << offset << "," << offset + size << "]" << dec << endl;

    std::map<Address, int>::iterator iter = smap.find(offset);
    if (iter == smap.end()) {
        smap[offset] = size;
    }
    else if (size > iter->second) {
        smap[offset] = size;
    }
    // Otherwise keep the current value
    //cerr << "\t New value: " << hex << offset << " -> " << smap[offset] + offset << dec << endl;

#if 0
    // We don't want to delete these, actually, because we can conflict between a springboard
    // addition and a synchronization operation.

    while (true)
    {
        std::map<Address, int>::iterator lb = smap.lower_bound(offset);
        if (lb != smap.end()) {
            // Found a legal lower bound
            if (lb->first >= offset &&
                lb->first < (offset + size)) 
            {
                //cerr << "Erasing SB [" << hex << lb->first << "," << lb->first + lb->second << "]" << dec << endl;
                smap.erase(lb);
                continue;
            }
            if ((lb->first + lb->second) >= offset &&
                (lb->first + lb->second) < (offset + size))
            {
                //cerr << "Erasing SB [" << hex << lb->first << "," << lb->first + lb->second << "]" << dec << endl;
                smap.erase(lb);
                continue;
            }
        }
        // Lower bound is "first entry that is greater than the search term",
        // so we need to try and back it up to check that one too
        if (lb != smap.begin()) {
            lb--;
            if (lb->first >= offset &&
                lb->first < (offset + size)) 
            {
                //cerr << "Erasing SB [" << hex << lb->first << "," << lb->first + lb->second << "]" << dec << endl;
                smap.erase(lb);
                continue;
            }
            if ((lb->first + lb->second) >= offset &&
                (lb->first + lb->second) < (offset + size))
            {
                //cerr << "Erasing SB [" << hex << lb->first << "," << lb->first + lb->second << "]" << dec << endl;
                smap.erase(lb);
                continue;
            }
        }
        break;
    }
#endif


}

void MemoryEmulator::removeSpringboards(int_function * func) 
{
    malware_cerr << "untracking springboards from deadfunc " << hex << func->getAddress() << dec << endl;

    const set<int_block*,int_block::compare> & blocks = func->blocks();
    set<int_block*,int_block::compare>::const_iterator bit = blocks.begin();
    for (; bit != blocks.end(); bit++) {
        removeSpringboards((*bit));
    }
}

void MemoryEmulator::removeSpringboards(const int_block *bbi) 
{
    malware_cerr << "  untracking springboards from deadblock [" << hex 
         << bbi->start() << " " << bbi->end() << ")" << dec <<endl;
    SymtabAPI::Region * reg = 
        ((ParseAPI::SymtabCodeRegion*)bbi->func()->ifunc()->region())->symRegion();
    if (springboards_[reg].find((bbi->llb()->start() - reg->getMemOffset())) == springboards_[reg].end()) {
        cerr << "ERROR IN DELETING SPRINGBOARD!" << endl; // could just mean that the block is shared
    }
    springboards_[reg].erase(bbi->llb()->start() - reg->getMemOffset());
    if (springboards_[reg].empty()) springboards_.erase(reg);
}

void  MemoryEmulator::debug() const {
	std::vector<MemoryMapTree::Entry> elements;
	memoryMap_.elements(elements);
	cerr << "\t Forward map: " << endl;
	for (std::vector<MemoryMapTree::Entry>::iterator iter = elements.begin(); iter != elements.end(); ++iter)
	{
		cerr << "\t\t " << hex << "[" << iter->first.first << "," << iter->first.second << "]: " << iter->second << dec << endl;
	}
	elements.clear();
	cerr << "\t Backwards map: " << endl;
	reverseMemoryMap_.elements(elements);
	for (std::vector<MemoryMapTree::Entry>::iterator iter = elements.begin(); iter != elements.end(); ++iter)
	{
		cerr << "\t\t " << hex << "[" << iter->first.first << "," << iter->first.second << "]: " << iter->second << dec << endl;
	}
	elements.clear();

}