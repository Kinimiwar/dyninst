	IMPLICIT NONE

	INTEGER test1_4_globalVariable4_1, passedTest

! **********************************************************************
! The following common block (globals) has a corresponding c structure 
! (struct block_) defined in test1.mutateeFortC.c.  Make sure all changes
! to this structure are reflected in the other. (Including the size of
! each memeber defined above)
! **********************************************************************
	common /test1_4f_globals/ test1_4_globalVariable4_1, passedTest
