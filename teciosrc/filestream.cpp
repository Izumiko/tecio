#include "MASTER.h"
 #define ___1402
#include "GLOBAL.h"
#include "stdafx.h"
#include "FILESTREAM.h"
#include "ALLOC.h"
#include "SYSTEM.h"
#include "CodeContract.h"
___1403* ___1400(FILE* File, ___372 ___2006) { REQUIRE(VALID_REF(File) || File == NULL); ___1403* ___3360 = ALLOC_ITEM(___1403, "FileStream"); if (___3360 != NULL) { ___3360->File              = File; ___3360->___2006 = ___2006; } ENSURE(VALID_REF(___3360) || ___3360 == NULL); return ___3360; } void ___1401(___1403** ___1399) { REQUIRE(VALID_REF(___1399)); REQUIRE(VALID_REF(*___1399) || *___1399 == NULL); if (*___1399 != NULL) { ___1529(*___1399, "FileStream"); *___1399 = NULL; } ENSURE(*___1399 == NULL); }
