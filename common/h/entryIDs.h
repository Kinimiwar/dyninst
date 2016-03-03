/*
 * See the dyninst/COPYRIGHT file for copyright information.
 *
 * We provide the Paradyn Tools (below described as "Paradyn")
 * on an AS IS basis, and do not warrant its validity or performance.
 * We reserve the right to update, modify, or discontinue this
 * software at any time.  We shall have no obligation to supply such
 * updates or modifications or any other form of support to you.
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

#if !defined(ENTRYIDS_IA32_H)
#define ENTRYIDS_IA32_H

#include "dyntypes.h"

enum entryID {
  e_jb = 0,
  e_jb_jnaej_j,
  e_jbe,
  e_jcxz_jec,
  e_jl,
  e_jle,
  e_jmp,
  e_jmpe,
  e_jnb,
  e_jnb_jae_j,
  e_jnbe,
  e_jnl,
  e_jnle,
  e_jno,
  e_jnp,
  e_jns,
  e_jnz,
  e_jo,
  e_jp,
  e_js,
  e_jz,
  e_loop,
  e_loope,
  e_loopn,
  e_call,
  e_cmp,
  e_cmppd,
  e_cmpps,
  e_cmpsb,
  e_cmpsd,
  e_cmpsd_sse,
  e_cmpss,
  e_cmpsw,
  e_cmpxch,
  e_cmpxch8b,
  e_ret_far,
  e_ret_near,
  e_prefetch,
  e_prefetchNTA,
  e_prefetchT0,
  e_prefetchT1,
  e_prefetchT2,
  e_prefetch_w,
  e_prefetchw,
  e_No_Entry,
  e_aaa,
  e_aad,
  e_aam,
  e_aas,
  e_adc,
  e_add,
  e_addpd,
  e_addps,
  e_addsd,
  e_addss,
  e_addsubpd,
  e_addsubps,
  e_and,
  e_andnpd,
  e_andnps,
  e_andpd,
  e_andps,
  e_arpl,
  e_blendpd,  // SSE 4.1
  e_blendps,  // SSE 4.1
  e_blendvpd, // SSE 4.1
  e_blendvps, // SSE 4.1
  e_bound,
  e_bsf,
  e_bsr,
  e_bswap,
  e_bt,
  e_btc,
  e_btr,
  e_bts,
  e_cbw,
  e_cdq,
  e_clc,
  e_cld,
  e_clflush,
  e_cli,
  e_clts,
  e_cmc,
  e_cmovbe,
  e_cmove,
  e_cmovnae,
  e_cmovnb,
  e_cmovnbe,
  e_cmovne,
  e_cmovng,
  e_cmovnge,
  e_cmovnl,
  e_cmovno,
  e_cmovns,
  e_cmovo,
  e_cmovpe,
  e_cmovpo,
  e_cmovs,
  e_comisd,
  e_comiss,
  e_cpuid,
  e_crc32,		// SSE 4.2
  e_cvtdq2pd,
  e_cvtdq2ps,
  e_cvtpd2dq,
  e_cvtpd2pi,
  e_cvtpd2ps,
  e_cvtpi2pd,
  e_cvtpi2ps,
  e_cvtps2dq,
  e_cvtps2pd,
  e_cvtps2pi,
  e_cvtsd2si,
  e_cvtsd2ss,
  e_cvtsi2sd,
  e_cvtsi2ss,
  e_cvtss2sd,
  e_cvtss2si,
  e_cvttpd2dq,
  e_cvttpd2pi,
  e_cvttps2dq,
  e_cvttps2pi,
  e_cvttsd2si,
  e_cvttss2si,
  e_cwd,
  e_cwde,
  e_daa,
  e_das,
  e_dec,
  e_div,
  e_divpd,
  e_divps,
  e_divsd,
  e_divss,
  e_dppd,	// SSE 4.1
  e_dpps,	// SSE 4.1
  e_emms,
  e_enter,
  e_extractps,	// SSE 4.1
  e_extrq,
  e_fadd,
  e_faddp,
  e_f2xm1,
  e_fbld,
  e_fbstp,
  e_fchs,
  e_fcmovb,
  e_fcmovbe,
  e_fcmove,
  e_fcmovne,
  e_fcmovu,
  e_fcmovnu,
  e_fcmovnb,
  e_fcmovnbe,
  e_fcom,
  e_fcomi,
  e_fcomip,
  e_fcomp,
  e_fcompp,
  e_fdiv,
  e_fdivp,
  e_fdivr,
  e_fdivrp,
  e_femms,
  e_ffree,
  e_ffreep,
  e_fiadd,
  e_ficom,
  e_ficomp,
  e_fidiv,
  e_fidivr,
  e_fild,
  e_fimul,
  e_fist,
  e_fistp,
  e_fisttp,
  e_fisub,
  e_fisubr,
  e_fld,
  e_fld1, // note: numeral '1', as in load the constant
  e_fldcw,
  e_fldenv,
  e_fmul,
  e_fmulp,
  e_fnop,
  e_fprem,
  e_frstor,
  e_fsave,
  e_fst,
  e_fstcw,
  e_fstenv,
  e_fstp,
  e_fstsw,
  e_fsub,
  e_fsubp,
  e_fsubr,
  e_fsubrp,
  e_fucom,
  e_fucomp,
  e_fucomi,
  e_fucomip,
  e_fucompp,
  e_fxch,
  e_fxrstor,
  e_fxsave,
  e_haddpd,
  e_haddps,
  e_hlt,
  e_hsubpd,
  e_hsubps,
  e_idiv,
  e_imul,
  e_in,
  e_inc,
  e_insb,
  e_insd,
  e_insertps,	// SSE 4.1
  e_insertq,
  e_insw,
  e_int,
  e_int3,
  e_int1,
  e_int80,
  e_into,
  e_invd,
  e_invlpg,
  e_iret,
  e_lahf,
  e_lar,
  e_lddqu,
  e_ldmxcsr,
  e_lds,
  e_lea,
  e_leave,
  e_les,
  e_lfence,
  e_lfs,
  e_lgdt,
  e_lgs,
  e_lidt,
  e_lldt,
  e_lmsw,
  e_lodsb,
  e_lodsd,
  e_lodsw,
  e_lsl,
  e_lss,
  e_ltr,
  e_maskmovdqu,
  e_maskmovq,
  e_maxpd,
  e_maxps,
  e_maxsd,
  e_maxss,
  e_mfence,
  e_minpd,
  e_minps,
  e_minsd,
  e_minss,
  e_mmxud,
  e_mov,
  e_movapd,
  e_movaps,
  e_movd,
  e_movddup,
  e_movdq2q,
  e_movdqa,
  e_movdqu,
  e_movhpd,
  e_movhps,
  e_movhps_movlhps,
  e_movlpd,
  e_movlps,
  e_movlps_movhlps,
  e_movmskpd,
  e_movmskps,
  e_movntdq,
  e_movntdqa, 	// SSE 4.1
  e_movnti,
  e_movntpd,
  e_movntps,
  e_movntq,
  e_movntsd,
  e_movntss,
  e_movq,
  e_movq2dq,
  e_movsb,
  e_movsd,
  e_movsd_sse,
  e_movshdup,
  e_movsldup,
  e_movss,
  e_movsw,
  e_movsx,
  e_movsxd,
  e_movupd,
  e_movups,
  e_movzx,
  e_mpsadbw,	// SSE 4.1
  e_mul,
  e_mulpd,
  e_mulps,
  e_mulsd,
  e_mulss,
  e_neg,
  e_nop,
  e_not,
  e_or,
  e_orpd,
  e_orps,
  e_out,
  e_outsb,
  e_outsd,
  e_outsw,
  e_pabsb, // SSSE3
  e_pabsd, // SSSE3
  e_pabsw, // SSSE3
  e_packssdw,
  e_packsswb,
  e_packusdw,	// SSE 4.1
  e_packuswb,
  e_paddb,
  e_paddd,
  e_paddq,
  e_paddsb,
  e_paddsw,
  e_paddusb,
  e_paddusw,
  e_paddw,
  e_palignr, // SSSE3
  e_pand,
  e_pandn,
  e_pavgb,
  e_pavgw,
  e_pblendvb,	// SSE 4.1
  e_pblendw,	// SSE 4.1
  e_pcmpeqb,
  e_pcmpeqd,
  e_pcmpeqq,	// SSE 4.1
  e_pcmpeqw,
  e_pcmpestri,	// SSE 4.2
  e_pcmpestrm,	// SSE 4.2
  e_pcmpgdt,
  e_pcmpgtb,
  e_pcmpgtq,	// SSE 4.2
  e_pcmpgtw,
  e_pcmpistri,	// SSE 4.2
  e_pcmpistrm,	// SSE 4.2
  e_pextrb,		// SSE 4.1
  e_pextrd_pextrq,		// SSE 4.1
  e_pextrw,		// SSE 4.1
  e_phaddd, // SSSE3
  e_phaddw, // SSSE3
  e_phaddsw, // SSSE3
  e_phminposuw,	// SSE 4.1
  e_phsubd, // SSSE3
  e_phsubw, // SSSE3
  e_phsubsw, // SSSE3
  e_pinsrb,		// SSE 4.1
  e_pinsrd_pinsrq,		// SSE 4.1
  e_pinsrw,
  e_pmaddwd,
  e_pmaddubsw, // SSSE3
  e_pmaxsb,		// SSE 4.1
  e_pmaxsd,		// SSE 4.1
  e_pmaxud,		// SSE 4.1
  e_pmaxuw,		// SSE 4.1
  e_pmaxsw,
  e_pmaxub,
  e_pminsb,		// SSE 4.1
  e_pminsd,		// SSE 4.1
  e_pminud,		// SSE 4.1
  e_pminuw,		// SSE 4.1
  e_pminsw,
  e_pminub,
  e_pmovmskb,
  e_pmovntdqa, 	// SSE 4.1
  e_pmovsxbd,	// SSE 4.1
  e_pmovsxbq,	// SSE 4.1
  e_pmovsxbw,	// SSE 4.1
  e_pmovsxwd,	// SSE 4.1
  e_pmovsxwq,	// SSE 4.1
  e_pmovsxdq,	// SSE 4.1
  e_pmovzxbd,	// SSE 4.1
  e_pmovzxbq,	// SSE 4.1
  e_pmovzxbw,	// SSE 4.1
  e_pmovzxwd,	// SSE 4.1
  e_pmovzxwq,	// SSE 4.1
  e_pmovzxdq,	// SSE 4.1
  e_pmuldq,		// SSE 4.1
  e_pmulhrsw, 	// SSSE3
  e_pmulhuw,
  e_pmulhw,
  e_pmulld,		// SSE 4.1
  e_pmullw,
  e_pmuludq,
  e_pop,
  e_popa,
  e_popad,
  e_popf,
  e_popfd,
  e_popcnt,
  e_por,
  e_psadbw,
  e_pshufb, // SSSE3
  e_pshufd,
  e_pshufhw,
  e_pshuflw,
  e_pshufw,
  e_psignd, // SSSE3
  e_psignw, // SSSE3
  e_psignb, // SSSE3
  e_pslld,
  e_pslldq,
  e_psllq,
  e_psllw,
  e_psrad,
  e_psraw,
  e_psrld,
  e_psrldq,
  e_psrlq,
  e_psrlw,
  e_psubb,
  e_psubd,
  e_psubsb,
  e_psubsw,
  e_psubusb,
  e_psubusw,
  e_psubw,
  e_ptest,	// SSE 4.1
  e_punpckhbw,
  e_punpckhdq,
  e_punpckhqd,
  e_punpckhwd,
  e_punpcklbw,
  e_punpcklqd,
  e_punpcklqld,
  e_punpcklwd,
  e_push,
  e_pusha,
  e_pushad,
  e_pushf,
  e_pushfd,
  e_pxor,
  e_rcl,
  e_rcpps,
  e_rcpss,
  e_rcr,
  e_rdmsr,
  e_rdpmc,
  e_rdtsc,
  e_rol,
  e_ror,
  e_roundpd,	// SSE 4.1
  e_roundps,	// SSE 4.1
  e_roundsd,	// SSE 4.1
  e_roundss,	// SSE 4.1
  e_rsm,
  e_rsqrtps,
  e_rsqrtss,
  e_sahf,
  e_salc,
  e_sar,
  e_sbb,
  e_scasb,
  e_scasd,
  e_scasw,
  e_setb,
  e_setbe,
  e_setl,
  e_setle,
  e_setnb,
  e_setnbe,
  e_setnl,
  e_setnle,
  e_setno,
  e_setnp,
  e_setns,
  e_setnz,
  e_seto,
  e_setp,
  e_sets,
  e_setz,
  e_sfence,
  e_sgdt,
  e_shl_sal,
  e_shld,
  e_shr,
  e_shrd,
  e_shufpd,
  e_shufps,
  e_sidt,
  e_sldt,
  e_smsw,
  e_sqrtpd,
  e_sqrtps,
  e_sqrtsd,
  e_sqrtss,
  e_stc,
  e_std,
  e_sti,
  e_stmxcsr,
  e_stosb,
  e_stosd,
  e_stosw,
  e_str,
  e_sub,
  e_subpd,
  e_subps,
  e_subsd,
  e_subss,
  e_syscall,
  e_sysenter,
  e_sysexit,
  e_sysret,
  e_test,
  e_ucomisd,
  e_ucomiss,
  e_ud,
  e_ud2,
  e_ud2grp10,
  e_unpckhpd,
  e_unpckhps,
  e_unpcklpd,
  e_unpcklps,
  e_verr,
  e_verw,

  e_vaddpd,
  e_vaddps,
  e_vaddsd,
  e_vaddss,
  e_vandnpd,
  e_vandnps,
  e_vandpd,
  e_vandps,
  e_valignd,
  e_valignq,
  e_vbroadcastf128,
  e_vbroadcasti128,
  e_vbroadcastsd,
  e_vbroadcastss,
  e_vblendmps,
  e_vblendmpd,
  e_vpblendmw,
  e_vpblendmb,
  e_vcmppd,
  e_vcmpps,
  e_vcmpsd,
  e_vcmpss,
  e_vcomisd,
  e_vcomiss,
  e_vexpandpd,
  e_vexpandps,
  e_vcvtpd2qq,
  e_vcvtdq2pd,
  e_vcvtdq2ps,
  e_vcvtpd2dq,
  e_vcvtpd2ps,
  e_vcvtph2ps,
  e_vcvtps2dq,
  e_vcvtps2pd,
  e_vcvtps2ph,
  e_vcvtsd2si,
  e_vcvtsd2ss,
  e_vcvtsi2sd,
  e_vcvtsi2ss,
  e_vcvtss2sd,
  e_vcvtss2si,
  e_vcvttpd2dq,
  e_vcvttps2dq,
  e_vcvttsd2si,
  e_vcvttss2si,
  e_vdivpd,
  e_vdivps,
  e_vdivsd,
  e_vdivss,
  e_vextractf128, 
  e_vextracti128, 
  e_vextractf32x4,
  e_vextractf64x2,
  e_vextractf32x8,
  e_vextractf64x4,
  e_vextracti32x4, 
  e_vextracti64x2, 
  e_vextracti32x8, 
  e_vextracti64x4, 
  e_vextractps,
  e_vfixupimmpd,
  e_vfixupimmps,
  e_vfixupimmsd,
  e_vfixupimmss,
  e_vfmadd132pd,
  e_vfmadd132ps,
  e_vfmadd132sd,
  e_vfmadd132ss,
  e_vfmadd213pd,
  e_vfmadd213ps,
  e_vfmadd213sd,
  e_vfmadd213ss,
  e_vfmadd231pd,
  e_vfmadd231ps,
  e_vfmadd231sd,
  e_vfmadd231ss,
  e_vfmaddsub132pd,
  e_vfmaddsub132ps,
  e_vfmaddsub213pd,
  e_vfmaddsub213ps,
  e_vfmaddsub231pd,
  e_vfmaddsub231ps,
  e_vfmsub132pd,
  e_vfmsub132ps,
  e_vfmsub132sd,
  e_vfmsub132ss,
  e_vfmsub213pd,
  e_vfmsub213ps,
  e_vfmsub213sd,
  e_vfmsub213ss,
  e_vfmsub231pd,
  e_vfmsub231ps,
  e_vfmsub231sd,
  e_vfmsub231ss,
  e_vfmsubadd132pd,
  e_vfmsubadd132ps,
  e_vfmsubadd213pd,
  e_vfmsubadd213ps,
  e_vfmsubadd231pd,
  e_vfmsubadd231ps,
  e_vfnmadd132pd,
  e_vfnmadd132ps,
  e_vfnmadd132sd,
  e_vfnmadd132ss,
  e_vfnmadd213pd,
  e_vfnmadd213ps,
  e_vfnmadd213sd,
  e_vfnmadd213ss,
  e_vfnmadd231pd,
  e_vfnmadd231ps,
  e_vfnmadd231sd,
  e_vfnmadd231ss,
  e_vfnmsub132pd,
  e_vfnmsub132ps,
  e_vfnmsub132sd,
  e_vfnmsub132ss,
  e_vfnmsub213pd,
  e_vfnmsub213ps,
  e_vfnmsub213sd,
  e_vfnmsub213ss,
  e_vfnmsub231pd,
  e_vfnmsub231ps,
  e_vfnmsub231sd,
  e_vfnmsub231ss,
  e_vfpclassps,
  e_vfpclasspd,
  e_vfpclasssd,
  e_vfpclassss,
  e_vgatherdpd,
  e_vgatherdps,
  e_vgatherqpd,
  e_vgatherqps,
  e_vgetexpps,
  e_vgetexppd,
  e_vgetexpsd,
  e_vgetexpss,
  e_vgetmantps,
  e_vgetmantpd,
  e_vgetmantss,
  e_vgetmantsd,
  e_vinsertf128,
  e_vinserti128,
  e_vinsertps,
  e_vinsertf32x4,
  e_vinsertf64x2,
  e_vinsertf32x8,
  e_vinsertf64x4,
  e_vinserti32x4,
  e_vinserti64x2,
  e_vinserti32x8,
  e_vinserti64x4,
  e_vmaskmovpd,
  e_vmaskmovps,
  e_vmaxpd,
  e_vmaxps,
  e_vmaxsd,
  e_vmaxss,
  e_vminpd,
  e_vminps,
  e_vminsd,
  e_vminss,
  e_vmovapd,
  e_vmovaps,
  e_vmovddup,
  e_vmovdqa,
  e_vmovdqa32,
  e_vmovdqa64,
  e_vmovdqu32,
  e_vmovdqu64,
  e_vmovdqu8,
  e_vmovdqu16,
  e_vmovdqu,
  e_vmovhlps,
  e_vmovhpd,
  e_vmovhps,
  e_vmovlhps,
  e_vmovlpd,
  e_vmovlps,
  e_vmovntps,
  e_vmovq,
  e_vmovsd,
  e_vmovshdup,
  e_vmovsldup,
  e_vmovss,
  e_vmovupd,
  e_vmovups,
  e_vmulpd,
  e_vmulps,
  e_vmulsd,
  e_vmulss,
  e_vorpd,
  e_vorps,
  e_vpabsb,
  e_vpabsd,
  e_vpabsw,
  e_vpackssdw,
  e_vpacksswb,
  e_vpackusdw,
  e_vpackuswb,
  e_vpaddb,
  e_vpaddd,
  e_vpaddq,
  e_vpaddsb,
  e_vpaddsw,
  e_vpaddusb,
  e_vpaddusw,
  e_vpaddw,
  e_vpalignr,
  e_vpandn,
  e_vpandd,
  e_vpandq,
  e_vpandnd,
  e_vpandnq,
  e_vpavgb,
  e_vpavgw,
  e_vpblendd,
  e_vpbroadcastb,
  e_vpbroadcastd,
  e_vpbroadcastq,
  e_vpbroadcastw,
  e_vpcmpeqb,
  e_vpcmpeqd,
  e_vpcmpeqq,
  e_vpcmpeqw,
  e_vpcmpgtb,
  e_vpcmpgtd,
  e_vpcmpgtq,
  e_vpcmpgtw,
  e_vpcompressd,
  e_vpcompressq,
  e_vpconflictd,
  e_vpconflictq,
  e_vperm2f128,
  e_vperm2i128,
  e_vpermd,
  e_vpermilpd,
  e_vpermilps,
  e_vpermpd,
  e_vpermps,
  e_vpermq,
  e_vpextrb,
  e_vpextrd,
  e_vpextrq,
  e_vpextrw,
  e_vpgatherdd,
  e_vpgatherdq,
  e_vpgatherqd,
  e_vpgatherqq,
  e_vpinsrb,
  e_vpinsrd,
  e_vpinsrq,
  e_vpinsrw,
  e_vpmaddubsw,
  e_vpmaddwd,
  e_vpmaskmovd,
  e_vpmaskmovq,
  e_vpmaxsb,
  e_vpmaxsd,
  e_vpmaxsw,
  e_vpmaxub,
  e_vpmaxud,
  e_vpmaxuw,
  e_vpminsb,
  e_vpminsd,
  e_vpminsw,
  e_vpminub,
  e_vpminud,
  e_vpminuw,
  e_vpmovsdb,
  e_vpmovsdw,
  e_vpmovsqb,
  e_vpmovsqd,
  e_vpmovsqw,
  e_vpmovswb,
  e_vpmovsxbd,
  e_vpmovsxbq,
  e_vpmovsxbw,
  e_vpmovsxdq,
  e_vpmovsxwd,
  e_vpmovsxwq,
  e_vpmovzxbd,
  e_vpmovzxbq,
  e_vpmovzxbw,
  e_vpmovzxdq,
  e_vpmovzxwd,
  e_vpmovzxwq,
  e_vpmuldq,
  e_vpmulhrsw,
  e_vpmulhuw,
  e_vpmulhw,
  e_vpmulld,
  e_vpmullw,
  e_vpmuludq,
  e_vpor,
  e_vpsadbw,
  e_vpshufb,
  e_vpshufd,
  e_vpshufhw,
  e_vpshuflw,
  e_vpslld,
  e_vpslldq,
  e_vpsllq,
  e_vpsllvd,
  e_vpsllvq,
  e_vpsllw,
  e_vpsrad,
  e_vpsravd,
  e_vpsraw,
  e_vpsrld,
  e_vpsrldq,
  e_vpsrlq,
  e_vpsrlvd,
  e_vpsrlvq,
  e_vpsrlw,
  e_vpsubb,
  e_vpsubd,
  e_vpsubq,
  e_vpsubsb,
  e_vpsubsw,
  e_vpsubusb,
  e_vpsubusw,
  e_vpsubw,
  e_vpunpckhbw,
  e_vpunpckhdq,
  e_vpunpckhqdq,
  e_vpunpckhwd,
  e_vpunpcklbw,
  e_vpunpckldq,
  e_vpunpcklqdq,
  e_vpunpcklwd,
  e_vpxor,
  e_vshufpd,
  e_vshufps,
  e_vsqrtpd,
  e_vsqrtps,
  e_vsqrtsd,
  e_vsqrtss,
  e_vsubpd,
  e_vsubps,
  e_vsubsd,
  e_vsubss,
  e_vtestpd,
  e_vtestps,
  e_vucomisd,
  e_vucomiss,
  e_vunpckhpd,
  e_vunpckhps,
  e_vunpcklpd,
  e_vunpcklps,
  e_vxorpd,
  e_vxorps,
  e_vzeroall,
  e_vzeroupper,
  e_vmovntpd,
  e_vcvttsd2usi,
  e_vcvttss2usi,
  e_vcvtsd2usi,
  e_vcvtss2usi,
  e_vcvtusi2sd,
  e_vcvtusi2ss,
  e_vmovntdq,
  e_vpsrlvw,
  e_vpmovuswb,
  e_vpsravw,
  e_vpmovusdb,
  e_vpsllvw,
  e_vpmovusqb,
  e_vpmovusdw,
  e_vpmovusqw,
  e_vpmovusqd,
  e_vbroadcastf32x4,
  e_vpabsq,
  e_vmovntdqa,
  e_vpbroadcastmb2q,
  e_vpmovwb,
  e_vpmovdb,
  e_vpmovqb,
  e_vpmovdw,
  e_vpmovqw,
  e_vpmovqd,
  e_vpmultishiftqb,
  e_vpmadd52luq,
  e_vpmadd52huq,
  e_vrndscaleps,
  e_vrndscalepd,
  e_vrndscaless,
  e_vrndscalesd,
  e_vdbpsadbw,

  e_vcvtsi2sdl,
  e_vcvtsi2ssl,
  e_kandb,
  e_kandd,
  e_kandw,
  e_kandq,
  e_kandnb,
  e_kandnd,
  e_kandnw,
  e_kandnq,
  e_knotb,
  e_knotd,
  e_knotw,
  e_knotq,
  e_korb,
  e_kord,
  e_korw,
  e_korq,
  e_kxnorb,
  e_kxnord,
  e_kxnorw,
  e_kxnorq,
  e_kxorb,
  e_kxord,
  e_kxorw,
  e_kxorq,
  e_kaddb,
  e_kaddd,
  e_kaddw,
  e_kaddq,
  e_kunpckbw,
  e_kunpckwd,
  e_kunpckdq,
  e_kmovb,
  e_kmovd,
  e_kmovw,
  e_kmovq,
  e_kortestd,
  e_ktestb,
  e_ktestd,
  e_ktestw,
  e_ktestq,
  e_vcmpeqpd,
  e_vcmpeqsd,
  e_vcmpeqss,
  e_vcmpeqps,
  e_kortestb,
  e_kortestw,
  e_kortestq,

  e_vmread,
  e_vmwrite,
  e_vsyscall,
  e_wait,
  e_wbinvd,
  e_wrmsr,
  e_xadd,
  e_xchg,
  e_xlat,
  e_xor,
  e_xorpd,
  e_xorps,
  e_fp_generic,
  e_3dnow_generic,
  e_getsec,

  power_op_INVALID,
  power_op_extended,
  power_op_stfdu,
  power_op_fadd,
  power_op_xoris,
  power_op_mulhwu,
  power_op_stbux,
  power_op_cmpl,
  power_op_subf,
  power_op_svcs,
  power_op_fmuls,
  power_op_subfic,
  power_op_mcrfs,
  power_op_divs,
  power_op_lwzx,
  power_op_fctiw,
  power_op_mtcrf,
  power_op_srq,
  power_op_sraw,
  power_op_lfdx,
  power_op_stdcx_rc,
  power_op_nor,
  power_op_crandc,
  power_op_stdu,
  power_op_addme,
  power_op_fmul,
  power_op_sthbrx,
  power_op_mtspr,
  power_op_lfsx,
  power_op_lbzx,
  power_op_nand,
  power_op_fnmadds,
  power_op_fnmadd,
  power_op_mulhw,
  power_op_sradi,
  power_op_fnmsubs,
  power_op_addze,
  power_op_mulld,
  power_op_addic,
  power_op_lfs,
  power_op_andc,
  power_op_eciwx,
  power_op_rfid,
  power_op_divw,
  power_op_creqv,
  power_op_fctiwz,
  power_op_crnor,
  power_op_lbzux,
  power_op_td,
  power_op_dcbi,
  power_op_cli,
  power_op_div,
  power_op_add,
  power_op_extsh,
  power_op_divd,
  power_op_fmsub,
  power_op_stbx,
  power_op_nabs,
  power_op_isync,
  power_op_mfsri,
  power_op_stfdx,
  power_op_fsqrt,
  power_op_dcbz,
  power_op_dcbst,
  power_op_stswi,
  power_op_mulli,
  power_op_stfs,
  power_op_clf,
  power_op_fnmsub,
  power_op_lhz,
  power_op_ecowx,
  power_op_fres,
  power_op_stwu,
  power_op_lhau,
  power_op_slq,
  power_op_srawi,
  power_op_divwu,
  power_op_addis,
  power_op_mfmsr,
  power_op_mulhd,
  power_op_fdivs,
  power_op_abs,
  power_op_lwzu,
  power_op_tlbli,
  power_op_orc,
  power_op_mtfsf,
  power_op_lswx,
  power_op_stb,
  power_op_andis_rc,
  power_op_fsel,
  power_op_xori,
  power_op_lwax,
  power_op_tdi,
  power_op_rlwimi,
  power_op_stw,
  power_op_rldcr,
  power_op_sraq,
  power_op_fmr,
  power_op_tlbld,
  power_op_doz,
  power_op_lbz,
  power_op_stdux,
  power_op_mtfsfi,
  power_op_srea,
  power_op_lscbx,
  power_op_rlwinm,
  power_op_sld,
  power_op_addc,
  power_op_lfqux,
  power_op_sleq,
  power_op_extsb,
  power_op_ld,
  power_op_ldu,
  power_op_fctidz,
  power_op_lfq,
  power_op_lwbrx,
  power_op_fsqrts,
  power_op_srd,
  power_op_lfdu,
  power_op_stfsux,
  power_op_lhzu,
  power_op_crnand,
  power_op_icbi,
  power_op_rlwnm,
  power_op_rldcl,
  power_op_stwcx_rc,
  power_op_lhzx,
  power_op_stfsx,
  power_op_rlmi,
  power_op_twi,
  power_op_srliq,
  power_op_tlbie,
  power_op_mfcr,
  power_op_tlbsync,
  power_op_extsw,
  power_op_rldicl,
  power_op_bclr,
  power_op_rfsvc,
  power_op_mcrxr,
  power_op_clcs,
  power_op_srad,
  power_op_subfc,
  power_op_mfsrin,
  power_op_rfi,
  power_op_sreq,
  power_op_frsqrte,
  power_op_mffs,
  power_op_lwz,
  power_op_lfqu,
  power_op_and,
  power_op_stswx,
  power_op_stfd,
  power_op_fmsubs,
  power_op_bcctr,
  power_op_lhaux,
  power_op_ldux,
  power_op_fctid,
  power_op_frsp,
  power_op_slw,
  power_op_cmpli,
  power_op_sync,
  power_op_cntlzw,
  power_op_maskg,
  power_op_divdu,
  power_op_xor,
  power_op_fadds,
  power_op_fneg,
  power_op_lwaux,
  power_op_fsub,
  power_op_stfqux,
  power_op_srlq,
  power_op_lfqx,
  power_op_dcbt,
  power_op_sliq,
  power_op_fcmpo,
  power_op_lhax,
  power_op_cror,
  power_op_dozi,
  power_op_crand,
  power_op_stfsu,
  power_op_lha,
  power_op_mcrf,
  power_op_fdiv,
  power_op_ori,
  power_op_fmadd,
  power_op_stmw,
  power_op_lwarx,
  power_op_sle,
  power_op_fsubs,
  power_op_stdx,
  power_op_stwx,
  power_op_sthux,
  power_op_stwbrx,
  power_op_sthu,
  power_op_dclst,
  power_op_fcmpu,
  power_op_subfme,
  power_op_stfiwx,
  power_op_mul,
  power_op_bc,
  power_op_stwux,
  power_op_sllq,
  power_op_mullw,
  power_op_cmpi,
  power_op_rldicr,
  power_op_sth,
  power_op_sre,
  power_op_slliq,
  power_op_rldic,
  power_op_fnabs,
  power_op_sc,
  power_op_addic_rc,
  power_op_rldimi,
  power_op_stfqu,
  power_op_neg,
  power_op_oris,
  power_op_lfsux,
  power_op_mtfsb1,
  power_op_dcbtst,
  power_op_subfe,
  power_op_b,
  power_op_lwzux,
  power_op_rac,
  power_op_lfdux,
  power_op_lbzu,
  power_op_lhzux,
  power_op_lhbrx,
  power_op_lfsu,
  power_op_srw,
  power_op_crxor,
  power_op_stfdux,
  power_op_lmw,
  power_op_adde,
  power_op_mfsr,
  power_op_sraiq,
  power_op_rrib,
  power_op_addi,
  power_op_sthx,
  power_op_stfqx,
  power_op_andi_rc,
  power_op_or,
  power_op_dcbf,
  power_op_fcfid,
  power_op_fmadds,
  power_op_mtfsb0,
  power_op_lswi,
  power_op_mulhdu,
  power_op_ldarx,
  power_op_eieio,
  power_op_cntlzd,
  power_op_subfze,
  power_op_fabs,
  power_op_tw,
  power_op_eqv,
  power_op_stfq,
  power_op_maskir,
  power_op_sriq,
  power_op_mfspr,
  power_op_ldx,
  power_op_crorc,
  power_op_lfd,
  power_op_cmp,
  power_op_stbu,
  power_op_stfpdux,
  power_op_stfpdx,
  power_op_stfpsux,
  power_op_stfpsx,
  power_op_stfxdux,
  power_op_stfxdx,
  power_op_stfxsux,
  power_op_stfxsx,
  power_op_stfsdux,
  power_op_stfsdx,
  power_op_stfssux,
  power_op_stfssx,
  power_op_stfpiwx,
  power_op_lfpdux,
  power_op_lfpdx,
  power_op_lfpsux,
  power_op_lfpsx,
  power_op_lfxdux,
  power_op_lfxdx,
  power_op_lfxsux,
  power_op_lfxsx,
  power_op_lfsdux,
  power_op_lfsdx,
  power_op_lfssux,
  power_op_lfssx,
  power_op_qvfcfids,
  power_op_qvlfsx,
  power_op_qvlfsux,
  power_op_qvlfcsx,
  power_op_qvlfcsux,
  power_op_qvlfdx,
  power_op_qvlfdux,
  power_op_qvlfcdx,
  power_op_qvlfcdux,
  power_op_qvlfiwax,
  power_op_qvlfiwzx,
  power_op_qvlpcldx,
  power_op_qvlpclsx,
  power_op_qvlpcrdx,
  power_op_qvlpcrsx,
  power_op_qvstfsx,
  power_op_qvstfsux,
  power_op_qvstfsxi,
  power_op_qvstfsuxi,
  power_op_qvstfdx,
  power_op_qvstfdux,
  power_op_qvstfdxi,
  power_op_qvstfduxi,
  power_op_qvstfcsx,
  power_op_qvstfcsux,
  power_op_qvstfcsxi,
  power_op_qvstfcsuxi,
  power_op_qvstfcdx,
  power_op_qvstfcdux,
  power_op_qvstfcdxi,
  power_op_qvstfcduxi,
  power_op_qvstfiwx,
  power_op_qvfmr,
  power_op_qvfcpsgn,
  power_op_qvfneg,
  power_op_qvfabs,
  power_op_qvfnabs,
  power_op_qvfadd,
  power_op_qvfadds,
  power_op_qvfsub,
  power_op_qvfsubs,
  power_op_qvfmul,
  power_op_qvfmuls,
  power_op_qvfre,
  power_op_qvfres,
  power_op_qvfrsqrte,
  power_op_qvfrsqrtes,
  power_op_qvfmadd,
  power_op_qvfmadds,
  power_op_qvfmsub,
  power_op_qvfmsubs,
  power_op_qvfnmadd,
  power_op_qvfnmadds,
  power_op_qvfnmsub,
  power_op_qvfnmsubs,
  power_op_qvfxmadd,
  power_op_qvfxmadds,
  power_op_qvfxxnpmadd,
  power_op_qvfxxnpmadds,
  power_op_qvfxxmadd,
  power_op_qvfxxmadds,
  power_op_qvfxxcpnmadd,
  power_op_qvfxxcpnmadds,
  power_op_qvfxmul,
  power_op_qvfxmuls,
  power_op_qvfrsp,
  power_op_qvfctid,
  power_op_qvfctidz,
  power_op_qvfctidu,
  power_op_qvfctiduz,
  power_op_qvfctiw,
  power_op_qvfctiwu,
  power_op_qvfctiwz,
  power_op_qvfctiwuz,
  power_op_qvfcfid,
  power_op_qvfcfidu,
  power_op_qvfcfidus,
  power_op_qvfrin,
  power_op_qvfriz,
  power_op_qvfrip,
  power_op_qvfrim,
  power_op_qvfcmpgt,
  power_op_qvftstnan,
  power_op_qvfcmplt,
  power_op_qvfcmpeq,
  power_op_qvfsel,
  power_op_qvfaligni,
  power_op_qvfperm,
  power_op_qvesplati,
  power_op_qvgpci,
  power_op_qvflogical,
  power_op_qvlstdux,
  power_op_qvlstduxi,
  power_op_fxcxnms,
  power_op_fxcxma,
  power_op_fxcxnsma,
  power_op_fxcxnpma,
  power_op_fxcsnsma,
  power_op_fxcpnsma,
  power_op_fxcsnpma,
  power_op_fxcpnpma,
  power_op_fsmtp,
  power_op_fsmfp,
  power_op_fpctiwz,
  power_op_fpctiw,
  power_op_fxmr,
  power_op_fpsel,
  power_op_fpmul,
  power_op_fxmul,
  power_op_fxpmul,
  power_op_fxsmul,
  power_op_fpadd,
  power_op_fpsub,
  power_op_fpre,
  power_op_fprsqrte,
  power_op_fpmadd,
  power_op_fxmadd,
  power_op_fxcpmadd,
  power_op_fxcsmadd,
  power_op_fpnmadd,
  power_op_fxnmadd,
  power_op_fxcpnmadd,
  power_op_fxcsnmadd,
  power_op_fpmsub,
  power_op_fxmsub,
  power_op_fxcpmsub,
  power_op_fxcsmsub,
  power_op_fpnmsub,
  power_op_fxnmsub,
  power_op_fxcpnmsub,
  power_op_fxcsnmsub,
  power_op_fpmr,
  power_op_fpabs,
  power_op_fpneg,
  power_op_fprsp,
  power_op_fpnabs,
  power_op_fsmr,
  power_op_fscmp,
  power_op_fsabs,
  power_op_fsneg,
  power_op_fsnabs,
  power_op_lwa,

  // ***********
  // Steve note:
  // aarch64 opcode IDs.
  // These are generated by the script in instructionAPI dir
  // ***********
  aarch64_op_INVALID,
  aarch64_op_extended,
  aarch64_op_abs_advsimd,
  aarch64_op_adc,
  aarch64_op_adcs,
  aarch64_op_add_addsub_ext,
  aarch64_op_add_addsub_imm,
  aarch64_op_add_addsub_shift,
  aarch64_op_add_advsimd,
  aarch64_op_addhn_advsimd,
  aarch64_op_addp_advsimd_pair,
  aarch64_op_addp_advsimd_vec,
  aarch64_op_adds_addsub_ext,
  aarch64_op_adds_addsub_imm,
  aarch64_op_adds_addsub_shift,
  aarch64_op_addv_advsimd,
  aarch64_op_adr,
  aarch64_op_adrp,
  aarch64_op_aesd_advsimd,
  aarch64_op_aese_advsimd,
  aarch64_op_aesimc_advsimd,
  aarch64_op_aesmc_advsimd,
  aarch64_op_and_advsimd,
  aarch64_op_and_log_imm,
  aarch64_op_and_log_shift,
  aarch64_op_ands_log_imm,
  aarch64_op_ands_log_shift,
  aarch64_op_asr_asrv,
  aarch64_op_asr_sbfm,
  aarch64_op_asrv,
  aarch64_op_at_sys,
  aarch64_op_b_cond,
  aarch64_op_b_uncond,
  aarch64_op_bfi_bfm,
  aarch64_op_bfm,
  aarch64_op_bfxil_bfm,
  aarch64_op_bic_advsimd_imm,
  aarch64_op_bic_advsimd_reg,
  aarch64_op_bic_log_shift,
  aarch64_op_bics,
  aarch64_op_bif_advsimd,
  aarch64_op_bit_advsimd,
  aarch64_op_bl,
  aarch64_op_blr,
  aarch64_op_br,
  aarch64_op_brk,
  aarch64_op_bsl_advsimd,
  aarch64_op_cbnz,
  aarch64_op_cbz,
  aarch64_op_ccmn_imm,
  aarch64_op_ccmn_reg,
  aarch64_op_ccmp_imm,
  aarch64_op_ccmp_reg,
  aarch64_op_cinc_csinc,
  aarch64_op_cinv_csinv,
  aarch64_op_clrex,
  aarch64_op_cls_advsimd,
  aarch64_op_cls_int,
  aarch64_op_clz_advsimd,
  aarch64_op_clz_int,
  aarch64_op_cmeq_advsimd_reg,
  aarch64_op_cmeq_advsimd_zero,
  aarch64_op_cmge_advsimd_reg,
  aarch64_op_cmge_advsimd_zero,
  aarch64_op_cmgt_advsimd_reg,
  aarch64_op_cmgt_advsimd_zero,
  aarch64_op_cmhi_advsimd,
  aarch64_op_cmhs_advsimd,
  aarch64_op_cmle_advsimd,
  aarch64_op_cmlt_advsimd,
  aarch64_op_cmn_adds_addsub_ext,
  aarch64_op_cmn_adds_addsub_imm,
  aarch64_op_cmn_adds_addsub_shift,
  aarch64_op_cmp_subs_addsub_ext,
  aarch64_op_cmp_subs_addsub_imm,
  aarch64_op_cmp_subs_addsub_shift,
  aarch64_op_cmtst_advsimd,
  aarch64_op_cneg_csneg,
  aarch64_op_cnt_advsimd,
  aarch64_op_crc32,
  aarch64_op_crc32c,
  aarch64_op_csel,
  aarch64_op_cset_csinc,
  aarch64_op_csetm_csinv,
  aarch64_op_csinc,
  aarch64_op_csinv,
  aarch64_op_csneg,
  aarch64_op_dc_sys,
  aarch64_op_dcps1,
  aarch64_op_dcps2,
  aarch64_op_dcps3,
  aarch64_op_dmb,
  aarch64_op_drps,
  aarch64_op_dsb,
  aarch64_op_dup_advsimd_elt,
  aarch64_op_dup_advsimd_gen,
  aarch64_op_eon,
  aarch64_op_eor_advsimd,
  aarch64_op_eor_log_imm,
  aarch64_op_eor_log_shift,
  aarch64_op_eret,
  aarch64_op_ext_advsimd,
  aarch64_op_extr,
  aarch64_op_fabd_advsimd,
  aarch64_op_fabs_advsimd,
  aarch64_op_fabs_float,
  aarch64_op_facge_advsimd,
  aarch64_op_facgt_advsimd,
  aarch64_op_fadd_advsimd,
  aarch64_op_fadd_float,
  aarch64_op_faddp_advsimd_pair,
  aarch64_op_faddp_advsimd_vec,
  aarch64_op_fccmp_float,
  aarch64_op_fccmpe_float,
  aarch64_op_fcmeq_advsimd_reg,
  aarch64_op_fcmeq_advsimd_zero,
  aarch64_op_fcmge_advsimd_reg,
  aarch64_op_fcmge_advsimd_zero,
  aarch64_op_fcmgt_advsimd_reg,
  aarch64_op_fcmgt_advsimd_zero,
  aarch64_op_fcmle_advsimd,
  aarch64_op_fcmlt_advsimd,
  aarch64_op_fcmp_float,
  aarch64_op_fcmpe_float,
  aarch64_op_fcsel_float,
  aarch64_op_fcvt_float,
  aarch64_op_fcvtas_advsimd,
  aarch64_op_fcvtas_float,
  aarch64_op_fcvtau_advsimd,
  aarch64_op_fcvtau_float,
  aarch64_op_fcvtl_advsimd,
  aarch64_op_fcvtms_advsimd,
  aarch64_op_fcvtms_float,
  aarch64_op_fcvtmu_advsimd,
  aarch64_op_fcvtmu_float,
  aarch64_op_fcvtn_advsimd,
  aarch64_op_fcvtns_advsimd,
  aarch64_op_fcvtns_float,
  aarch64_op_fcvtnu_advsimd,
  aarch64_op_fcvtnu_float,
  aarch64_op_fcvtps_advsimd,
  aarch64_op_fcvtps_float,
  aarch64_op_fcvtpu_advsimd,
  aarch64_op_fcvtpu_float,
  aarch64_op_fcvtxn_advsimd,
  aarch64_op_fcvtzs_advsimd_fix,
  aarch64_op_fcvtzs_advsimd_int,
  aarch64_op_fcvtzs_float_fix,
  aarch64_op_fcvtzs_float_int,
  aarch64_op_fcvtzu_advsimd_fix,
  aarch64_op_fcvtzu_advsimd_int,
  aarch64_op_fcvtzu_float_fix,
  aarch64_op_fcvtzu_float_int,
  aarch64_op_fdiv_advsimd,
  aarch64_op_fdiv_float,
  aarch64_op_fmadd_float,
  aarch64_op_fmax_advsimd,
  aarch64_op_fmax_float,
  aarch64_op_fmaxnm_advsimd,
  aarch64_op_fmaxnm_float,
  aarch64_op_fmaxnmp_advsimd_pair,
  aarch64_op_fmaxnmp_advsimd_vec,
  aarch64_op_fmaxnmv_advsimd,
  aarch64_op_fmaxp_advsimd_pair,
  aarch64_op_fmaxp_advsimd_vec,
  aarch64_op_fmaxv_advsimd,
  aarch64_op_fmin_advsimd,
  aarch64_op_fmin_float,
  aarch64_op_fminnm_advsimd,
  aarch64_op_fminnm_float,
  aarch64_op_fminnmp_advsimd_pair,
  aarch64_op_fminnmp_advsimd_vec,
  aarch64_op_fminnmv_advsimd,
  aarch64_op_fminp_advsimd_pair,
  aarch64_op_fminp_advsimd_vec,
  aarch64_op_fminv_advsimd,
  aarch64_op_fmla_advsimd_elt,
  aarch64_op_fmla_advsimd_vec,
  aarch64_op_fmls_advsimd_elt,
  aarch64_op_fmls_advsimd_vec,
  aarch64_op_fmov_advsimd,
  aarch64_op_fmov_float,
  aarch64_op_fmov_float_gen,
  aarch64_op_fmov_float_imm,
  aarch64_op_fmsub_float,
  aarch64_op_fmul_advsimd_elt,
  aarch64_op_fmul_advsimd_vec,
  aarch64_op_fmul_float,
  aarch64_op_fmulx_advsimd_elt,
  aarch64_op_fmulx_advsimd_vec,
  aarch64_op_fneg_advsimd,
  aarch64_op_fneg_float,
  aarch64_op_fnmadd_float,
  aarch64_op_fnmsub_float,
  aarch64_op_fnmul_float,
  aarch64_op_frecpe_advsimd,
  aarch64_op_frecps_advsimd,
  aarch64_op_frecpx_advsimd,
  aarch64_op_frinta_advsimd,
  aarch64_op_frinta_float,
  aarch64_op_frinti_advsimd,
  aarch64_op_frinti_float,
  aarch64_op_frintm_advsimd,
  aarch64_op_frintm_float,
  aarch64_op_frintn_advsimd,
  aarch64_op_frintn_float,
  aarch64_op_frintp_advsimd,
  aarch64_op_frintp_float,
  aarch64_op_frintx_advsimd,
  aarch64_op_frintx_float,
  aarch64_op_frintz_advsimd,
  aarch64_op_frintz_float,
  aarch64_op_frsqrte_advsimd,
  aarch64_op_frsqrts_advsimd,
  aarch64_op_fsqrt_advsimd,
  aarch64_op_fsqrt_float,
  aarch64_op_fsub_advsimd,
  aarch64_op_fsub_float,
  aarch64_op_hint,
  aarch64_op_hlt,
  aarch64_op_hvc,
  aarch64_op_ic_sys,
  aarch64_op_ins_advsimd_elt,
  aarch64_op_ins_advsimd_gen,
  aarch64_op_isb,
  aarch64_op_ld1_advsimd_mult,
  aarch64_op_ld1_advsimd_sngl,
  aarch64_op_ld1r_advsimd,
  aarch64_op_ld2_advsimd_mult,
  aarch64_op_ld2_advsimd_sngl,
  aarch64_op_ld2r_advsimd,
  aarch64_op_ld3_advsimd_mult,
  aarch64_op_ld3_advsimd_sngl,
  aarch64_op_ld3r_advsimd,
  aarch64_op_ld4_advsimd_mult,
  aarch64_op_ld4_advsimd_sngl,
  aarch64_op_ld4r_advsimd,
  aarch64_op_ldar,
  aarch64_op_ldarb,
  aarch64_op_ldarh,
  aarch64_op_ldaxp,
  aarch64_op_ldaxr,
  aarch64_op_ldaxrb,
  aarch64_op_ldaxrh,
  aarch64_op_ldnp_fpsimd,
  aarch64_op_ldnp_gen,
  aarch64_op_ldp_fpsimd,
  aarch64_op_ldp_gen,
  aarch64_op_ldpsw,
  aarch64_op_ldr_imm_fpsimd,
  aarch64_op_ldr_imm_gen,
  aarch64_op_ldr_lit_fpsimd,
  aarch64_op_ldr_lit_gen,
  aarch64_op_ldr_reg_fpsimd,
  aarch64_op_ldr_reg_gen,
  aarch64_op_ldrb_imm,
  aarch64_op_ldrb_reg,
  aarch64_op_ldrh_imm,
  aarch64_op_ldrh_reg,
  aarch64_op_ldrsb_imm,
  aarch64_op_ldrsb_reg,
  aarch64_op_ldrsh_imm,
  aarch64_op_ldrsh_reg,
  aarch64_op_ldrsw_imm,
  aarch64_op_ldrsw_lit,
  aarch64_op_ldrsw_reg,
  aarch64_op_ldtr,
  aarch64_op_ldtrb,
  aarch64_op_ldtrh,
  aarch64_op_ldtrsb,
  aarch64_op_ldtrsh,
  aarch64_op_ldtrsw,
  aarch64_op_ldur_fpsimd,
  aarch64_op_ldur_gen,
  aarch64_op_ldurb,
  aarch64_op_ldurh,
  aarch64_op_ldursb,
  aarch64_op_ldursh,
  aarch64_op_ldursw,
  aarch64_op_ldxp,
  aarch64_op_ldxr,
  aarch64_op_ldxrb,
  aarch64_op_ldxrh,
  aarch64_op_lsl_lslv,
  aarch64_op_lsl_ubfm,
  aarch64_op_lslv,
  aarch64_op_lsr_lsrv,
  aarch64_op_lsr_ubfm,
  aarch64_op_lsrv,
  aarch64_op_madd,
  aarch64_op_mla_advsimd_elt,
  aarch64_op_mla_advsimd_vec,
  aarch64_op_mls_advsimd_elt,
  aarch64_op_mls_advsimd_vec,
  aarch64_op_mneg_msub,
  aarch64_op_mov_add_addsub_imm,
  aarch64_op_mov_dup_advsimd_elt,
  aarch64_op_mov_ins_advsimd_elt,
  aarch64_op_mov_ins_advsimd_gen,
  aarch64_op_mov_movn,
  aarch64_op_mov_movz,
  aarch64_op_mov_orr_advsimd_reg,
  aarch64_op_mov_orr_log_imm,
  aarch64_op_mov_orr_log_shift,
  aarch64_op_mov_umov_advsimd,
  aarch64_op_movi_advsimd,
  aarch64_op_movk,
  aarch64_op_movn,
  aarch64_op_movz,
  aarch64_op_mrs,
  aarch64_op_msr_imm,
  aarch64_op_msr_reg,
  aarch64_op_msub,
  aarch64_op_mul_advsimd_elt,
  aarch64_op_mul_advsimd_vec,
  aarch64_op_mul_madd,
  aarch64_op_mvn_not_advsimd,
  aarch64_op_mvn_orn_log_shift,
  aarch64_op_mvni_advsimd,
  aarch64_op_neg_advsimd,
  aarch64_op_neg_sub_addsub_shift,
  aarch64_op_negs_subs_addsub_shift,
  aarch64_op_ngc_sbc,
  aarch64_op_ngcs_sbcs,
  aarch64_op_nop_hint,
  aarch64_op_not_advsimd,
  aarch64_op_orn_advsimd,
  aarch64_op_orn_log_shift,
  aarch64_op_orr_advsimd_imm,
  aarch64_op_orr_advsimd_reg,
  aarch64_op_orr_log_imm,
  aarch64_op_orr_log_shift,
  aarch64_op_pmul_advsimd,
  aarch64_op_pmull_advsimd,
  aarch64_op_prfm_imm,
  aarch64_op_prfm_lit,
  aarch64_op_prfm_reg,
  aarch64_op_prfum,
  aarch64_op_raddhn_advsimd,
  aarch64_op_rbit_advsimd,
  aarch64_op_rbit_int,
  aarch64_op_ret,
  aarch64_op_rev,
  aarch64_op_rev16_advsimd,
  aarch64_op_rev16_int,
  aarch64_op_rev32_advsimd,
  aarch64_op_rev32_int,
  aarch64_op_rev64_advsimd,
  aarch64_op_ror_extr,
  aarch64_op_ror_rorv,
  aarch64_op_rorv,
  aarch64_op_rshrn_advsimd,
  aarch64_op_rsubhn_advsimd,
  aarch64_op_saba_advsimd,
  aarch64_op_sabal_advsimd,
  aarch64_op_sabd_advsimd,
  aarch64_op_sabdl_advsimd,
  aarch64_op_sadalp_advsimd,
  aarch64_op_saddl_advsimd,
  aarch64_op_saddlp_advsimd,
  aarch64_op_saddlv_advsimd,
  aarch64_op_saddw_advsimd,
  aarch64_op_sbc,
  aarch64_op_sbcs,
  aarch64_op_sbfiz_sbfm,
  aarch64_op_sbfm,
  aarch64_op_sbfx_sbfm,
  aarch64_op_scvtf_advsimd_fix,
  aarch64_op_scvtf_advsimd_int,
  aarch64_op_scvtf_float_fix,
  aarch64_op_scvtf_float_int,
  aarch64_op_sdiv,
  aarch64_op_sev_hint,
  aarch64_op_sevl_hint,
  aarch64_op_sha1c_advsimd,
  aarch64_op_sha1h_advsimd,
  aarch64_op_sha1m_advsimd,
  aarch64_op_sha1p_advsimd,
  aarch64_op_sha1su0_advsimd,
  aarch64_op_sha1su1_advsimd,
  aarch64_op_sha256h2_advsimd,
  aarch64_op_sha256h_advsimd,
  aarch64_op_sha256su0_advsimd,
  aarch64_op_sha256su1_advsimd,
  aarch64_op_shadd_advsimd,
  aarch64_op_shl_advsimd,
  aarch64_op_shll_advsimd,
  aarch64_op_shrn_advsimd,
  aarch64_op_shsub_advsimd,
  aarch64_op_sli_advsimd,
  aarch64_op_smaddl,
  aarch64_op_smax_advsimd,
  aarch64_op_smaxp_advsimd,
  aarch64_op_smaxv_advsimd,
  aarch64_op_smc,
  aarch64_op_smin_advsimd,
  aarch64_op_sminp_advsimd,
  aarch64_op_sminv_advsimd,
  aarch64_op_smlal_advsimd_elt,
  aarch64_op_smlal_advsimd_vec,
  aarch64_op_smlsl_advsimd_elt,
  aarch64_op_smlsl_advsimd_vec,
  aarch64_op_smnegl_smsubl,
  aarch64_op_smov_advsimd,
  aarch64_op_smsubl,
  aarch64_op_smulh,
  aarch64_op_smull_advsimd_elt,
  aarch64_op_smull_advsimd_vec,
  aarch64_op_smull_smaddl,
  aarch64_op_sqabs_advsimd,
  aarch64_op_sqadd_advsimd,
  aarch64_op_sqdmlal_advsimd_elt,
  aarch64_op_sqdmlal_advsimd_vec,
  aarch64_op_sqdmlsl_advsimd_elt,
  aarch64_op_sqdmlsl_advsimd_vec,
  aarch64_op_sqdmulh_advsimd_elt,
  aarch64_op_sqdmulh_advsimd_vec,
  aarch64_op_sqdmull_advsimd_elt,
  aarch64_op_sqdmull_advsimd_vec,
  aarch64_op_sqneg_advsimd,
  aarch64_op_sqrdmulh_advsimd_elt,
  aarch64_op_sqrdmulh_advsimd_vec,
  aarch64_op_sqrshl_advsimd,
  aarch64_op_sqrshrn_advsimd,
  aarch64_op_sqrshrun_advsimd,
  aarch64_op_sqshl_advsimd_imm,
  aarch64_op_sqshl_advsimd_reg,
  aarch64_op_sqshlu_advsimd,
  aarch64_op_sqshrn_advsimd,
  aarch64_op_sqshrun_advsimd,
  aarch64_op_sqsub_advsimd,
  aarch64_op_sqxtn_advsimd,
  aarch64_op_sqxtun_advsimd,
  aarch64_op_srhadd_advsimd,
  aarch64_op_sri_advsimd,
  aarch64_op_srshl_advsimd,
  aarch64_op_srshr_advsimd,
  aarch64_op_srsra_advsimd,
  aarch64_op_sshl_advsimd,
  aarch64_op_sshll_advsimd,
  aarch64_op_sshr_advsimd,
  aarch64_op_ssra_advsimd,
  aarch64_op_ssubl_advsimd,
  aarch64_op_ssubw_advsimd,
  aarch64_op_st1_advsimd_mult,
  aarch64_op_st1_advsimd_sngl,
  aarch64_op_st2_advsimd_mult,
  aarch64_op_st2_advsimd_sngl,
  aarch64_op_st3_advsimd_mult,
  aarch64_op_st3_advsimd_sngl,
  aarch64_op_st4_advsimd_mult,
  aarch64_op_st4_advsimd_sngl,
  aarch64_op_stlr,
  aarch64_op_stlrb,
  aarch64_op_stlrh,
  aarch64_op_stlxp,
  aarch64_op_stlxr,
  aarch64_op_stlxrb,
  aarch64_op_stlxrh,
  aarch64_op_stnp_fpsimd,
  aarch64_op_stnp_gen,
  aarch64_op_stp_fpsimd,
  aarch64_op_stp_gen,
  aarch64_op_str_imm_fpsimd,
  aarch64_op_str_imm_gen,
  aarch64_op_str_reg_fpsimd,
  aarch64_op_str_reg_gen,
  aarch64_op_strb_imm,
  aarch64_op_strb_reg,
  aarch64_op_strh_imm,
  aarch64_op_strh_reg,
  aarch64_op_sttr,
  aarch64_op_sttrb,
  aarch64_op_sttrh,
  aarch64_op_stur_fpsimd,
  aarch64_op_stur_gen,
  aarch64_op_sturb,
  aarch64_op_sturh,
  aarch64_op_stxp,
  aarch64_op_stxr,
  aarch64_op_stxrb,
  aarch64_op_stxrh,
  aarch64_op_sub_addsub_ext,
  aarch64_op_sub_addsub_imm,
  aarch64_op_sub_addsub_shift,
  aarch64_op_sub_advsimd,
  aarch64_op_subhn_advsimd,
  aarch64_op_subs_addsub_ext,
  aarch64_op_subs_addsub_imm,
  aarch64_op_subs_addsub_shift,
  aarch64_op_suqadd_advsimd,
  aarch64_op_svc,
  aarch64_op_sxtb_sbfm,
  aarch64_op_sxth_sbfm,
  aarch64_op_sxtl_sshll_advsimd,
  aarch64_op_sxtw_sbfm,
  aarch64_op_sys,
  aarch64_op_sysl,
  aarch64_op_tbl_advsimd,
  aarch64_op_tbnz,
  aarch64_op_tbx_advsimd,
  aarch64_op_tbz,
  aarch64_op_tlbi_sys,
  aarch64_op_trn1_advsimd,
  aarch64_op_trn2_advsimd,
  aarch64_op_tst_ands_log_imm,
  aarch64_op_tst_ands_log_shift,
  aarch64_op_uaba_advsimd,
  aarch64_op_uabal_advsimd,
  aarch64_op_uabd_advsimd,
  aarch64_op_uabdl_advsimd,
  aarch64_op_uadalp_advsimd,
  aarch64_op_uaddl_advsimd,
  aarch64_op_uaddlp_advsimd,
  aarch64_op_uaddlv_advsimd,
  aarch64_op_uaddw_advsimd,
  aarch64_op_ubfiz_ubfm,
  aarch64_op_ubfm,
  aarch64_op_ubfx_ubfm,
  aarch64_op_ucvtf_advsimd_fix,
  aarch64_op_ucvtf_advsimd_int,
  aarch64_op_ucvtf_float_fix,
  aarch64_op_ucvtf_float_int,
  aarch64_op_udiv,
  aarch64_op_uhadd_advsimd,
  aarch64_op_uhsub_advsimd,
  aarch64_op_umaddl,
  aarch64_op_umax_advsimd,
  aarch64_op_umaxp_advsimd,
  aarch64_op_umaxv_advsimd,
  aarch64_op_umin_advsimd,
  aarch64_op_uminp_advsimd,
  aarch64_op_uminv_advsimd,
  aarch64_op_umlal_advsimd_elt,
  aarch64_op_umlal_advsimd_vec,
  aarch64_op_umlsl_advsimd_elt,
  aarch64_op_umlsl_advsimd_vec,
  aarch64_op_umnegl_umsubl,
  aarch64_op_umov_advsimd,
  aarch64_op_umsubl,
  aarch64_op_umulh,
  aarch64_op_umull_advsimd_elt,
  aarch64_op_umull_advsimd_vec,
  aarch64_op_umull_umaddl,
  aarch64_op_uqadd_advsimd,
  aarch64_op_uqrshl_advsimd,
  aarch64_op_uqrshrn_advsimd,
  aarch64_op_uqshl_advsimd_imm,
  aarch64_op_uqshl_advsimd_reg,
  aarch64_op_uqshrn_advsimd,
  aarch64_op_uqsub_advsimd,
  aarch64_op_uqxtn_advsimd,
  aarch64_op_urecpe_advsimd,
  aarch64_op_urhadd_advsimd,
  aarch64_op_urshl_advsimd,
  aarch64_op_urshr_advsimd,
  aarch64_op_ursqrte_advsimd,
  aarch64_op_ursra_advsimd,
  aarch64_op_ushl_advsimd,
  aarch64_op_ushll_advsimd,
  aarch64_op_ushr_advsimd,
  aarch64_op_usqadd_advsimd,
  aarch64_op_usra_advsimd,
  aarch64_op_usubl_advsimd,
  aarch64_op_usubw_advsimd,
  aarch64_op_uxtb_ubfm,
  aarch64_op_uxth_ubfm,
  aarch64_op_uxtl_ushll_advsimd,
  aarch64_op_uzp1_advsimd,
  aarch64_op_uzp2_advsimd,
  aarch64_op_wfe_hint,
  aarch64_op_wfi_hint,
  aarch64_op_xtn_advsimd,
  aarch64_op_yield_hint,
  aarch64_op_zip1_advsimd,
  aarch64_op_zip2_advsimd,
  _entry_ids_max_
};

enum prefixEntryID {
  prefix_none,
  prefix_rep,
  prefix_repnz
};

#if defined(__GNUC__)
//***************** GCC ***********************
  #if !defined(cap_tr1)
  //**************** GCC < 4.3.0 ************
  namespace __gnu_cxx {

    template<> struct hash<entryID> {
      hash<unsigned int> h;
      unsigned operator()(const entryID &e) const
      {
         return h(static_cast<unsigned int>(e));
      };
    };
    template<> struct hash<prefixEntryID> {
      hash<unsigned int> h;
      unsigned operator()(const prefixEntryID &e) const
      {
         return h(static_cast<unsigned int>(e));
      };
    };
  }
	#else
  namespace std
  {
    namespace tr1
    {
      template <>
      struct hash<entryID>
      {
        hash<size_t> h;
        size_t operator()(const entryID &eid) const
        {
           return h(static_cast<size_t>(eid));
        }
      };
      template <>
         struct hash<prefixEntryID>
      {
        hash<size_t> h;
	size_t operator()(const prefixEntryID &eid) const
	{
	  return h(static_cast<size_t>(eid));
	}
      };
    }
  }
	#endif
#endif
namespace NS_x86 {
COMMON_EXPORT extern dyn_hash_map<entryID, std::string> entryNames_IAPI;
COMMON_EXPORT extern dyn_hash_map<prefixEntryID, std::string> prefixEntryNames_IAPI;
}

#endif // defined(ENTRYIDS_IA32_H)
