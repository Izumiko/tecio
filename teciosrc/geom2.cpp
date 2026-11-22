#include "MASTER.h"
#include "GLOBAL.h"
#include "ThirdPartyHeadersBegin.h"
#include <cmath>
#include <functional>
#include <tuple>
#include "ThirdPartyHeadersEnd.h"
#include "TASSERT.h"
#include "ALLOC.h"
#include "GEOM.h"
#include "GEOM2.h"
#include "STRUTIL.h"
#include "TEXT.h"
#include "CodeContract.h"
#include "DATASET0.h"
FieldDataType_e ___1746(___1630 const* ___1554) { FieldDataType_e ___3360; REQUIRE(VALID_REF(___1554)); REQUIRE(VALID_REF(___1554->___1571.___1546.___4294)); ___3360 = ___1554->___905; ENSURE(VALID_GEOM_FIELD_DATA_TYPE(___3360)); ENSURE(IMPLICATION(VALID_REF(___1554->___1571.___1546.___4294), ___3360 == ___1725(___1554->___1571.___1546.___4294))); ENSURE(IMPLICATION(VALID_REF(___1554->___1571.___1546.___4296), ___3360 == ___1725(___1554->___1571.___1546.___4296))); ENSURE(IMPLICATION(VALID_REF(___1554->___1571.___1546.___4298), ___3360 == ___1725(___1554->___1571.___1546.___4298))); return ___3360; }
