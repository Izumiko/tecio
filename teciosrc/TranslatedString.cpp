#include "MASTER.h"
#include "GLOBAL.h"
#include "stdafx.h"
#include "ThirdPartyHeadersBegin.h"
#include <string>
#include "ThirdPartyHeadersEnd.h"
#include "CodeContract.h"
#include "UnicodeStringUtils.h"
using std::string; using std::wstring; namespace tecplot { static inline string* createUtf8StringTranslation(string const& str) { string* ___3359 = new string(str); ENSURE(VALID_REF(___3359)); return ___3359; }
 #if defined MSWIN
static inline wstring* createWideStringTranslation(string const& str) { wstring* ___3359 = new wstring; *___3359         = utf8ToWideString(str.c_str()); ENSURE(VALID_REF(___3359)); return ___3359; }
 #endif
 #if defined MSWIN
static inline wstring* createWideString(___4219::___2506 ___2505, string const& str) { REQUIRE(___2505 == ___4219::___1102 || ___2505 == ___4219::___1096); wstring* ___3359; if (___2505 == ___4219::___1102) ___3359 = createWideStringTranslation(str); else ___3359 = new wstring(utf8ToWideString(str.c_str())); return ___3359; }
 #endif
void ___4219::___1931(___4219::___2506 ___2505, char const* str, char const* ASSERT_ONLY(___4220)) { REQUIRE(___2505 == ___1102 || ___2505 == ___1096); REQUIRE(VALID_REF_OR_NULL(str)); REQUIRE(VALID_REF_OR_NULL(___4220)); ___2494   = ___2505; ___2488 = (str == NULL); if (!___2488) ___2624 = str; ___2667 = NULL;
 #if defined MSWIN
___2676 = NULL;
 #endif
} ___4219::___4219() { ___1931(___1096, NULL, NULL); ENSURE(this->___2066()); } ___4219 ___4219::___2766() { return ___1095(NULL); } ___4219::___4219(___4219::___2506 ___2505, char const* str, char const* ___4220) { REQUIRE(___2505 == ___1102 || ___2505 == ___1096); REQUIRE(VALID_REF_OR_NULL(str)); REQUIRE(VALID_REF_OR_NULL(___4220)); ___1931(___2505, str, ___4220); ENSURE(this->___2066()); } ___4219::~___4219() { delete ___2667;
 #if defined MSWIN
delete ___2676;
 #endif
}
 #if !defined NO_ASSERTS
bool ___4219::___2066() const { ___476(IMPLICATION(___2488, ___2624.length() == 0));
 #if 0
___476(IMPLICATION(___2488, ___2494 == ___1096));
 #endif
return true; }
 #endif
bool ___4219::___2034() const { INVARIANT(this->___2066()); return ___2488; } bool ___4219::___2035() const { INVARIANT(this->___2066()); return ___2488 || ___2624.length() == 0; } char const* ___4219::c_str() const { INVARIANT(this->___2066()); char const* ___3359 = NULL; if (!___2034()) { if (___2494 == ___1102) { if (___2667 == NULL) ___2667 = createUtf8StringTranslation(___2624); ___3359 = ___2667->c_str(); } else ___3359 = ___2624.c_str(); } ENSURE(___3359 == NULL || VALID_REF(___3359)); return ___3359; }
 #if defined MSWIN && !defined MAKEARCHIVE
wchar_t const* ___4219::___796() const { INVARIANT(this->___2066()); wchar_t const* ___3359 = NULL; if (!___2034()) { if (___2676 == NULL) ___2676 = createWideString(___2494, ___2624); ___3359 = ___2676->c_str(); } ENSURE(___3359 == NULL || VALID_REF(___3359)); return ___3359; }
 #endif
___4219::operator string() { INVARIANT(this->___2066()); REQUIRE(!___2034()); string* ___3359; if (___2494 == ___1102) { if (___2667 == NULL) ___2667 = createUtf8StringTranslation(___2624); ___3359 = ___2667; } else ___3359 = &___2624; return *___3359; }
 #if defined MSWIN && !defined MAKEARCHIVE
___4219::operator wstring() { INVARIANT(this->___2066()); REQUIRE(!___2034()); if (___2676 == NULL) ___2676 = createWideString(___2494, ___2624); return *___2676; }
 #endif
___4219& ___4219::operator=(___4219 const& ___2889) { REQUIRE(___2889.___2066()); if (this != &___2889) { ___2494   = ___2889.___2494; ___2488 = ___2889.___2488; ___2624 = ___2889.___2624; delete ___2667; ___2667 = (___2889.___2667 != NULL ? new string(*___2889.___2667) : NULL);
 #if defined MSWIN
delete ___2676; ___2676 = (___2889.___2676 != NULL ? new wstring(*___2889.___2676) : NULL);
 #endif
} ENSURE(this->___2066()); return *this; } ___4219::___4219(___4219 const& ___2889) { REQUIRE(___2889.___2066()); ___2494       = ___2889.___2494; ___2488     = ___2889.___2488; ___2624     = ___2889.___2624; ___2667 = (___2889.___2667 != NULL ? new string(*___2889.___2667) : NULL);
 #if defined MSWIN
___2676 = (___2889.___2676 != NULL ? new wstring(*___2889.___2676) : NULL);
 #endif
ENSURE(this->___2066()); } ___4219 ___4219::___4218(char const* str, char const* ___4220) { REQUIRE(VALID_REF_OR_NULL(str)); REQUIRE(VALID_REF_OR_NULL(___4220)); return ___4219(___1102, str, ___4220); } ___4219 ___4219::___1095(char const* str) { REQUIRE(VALID_REF_OR_NULL(str)); return ___4219(___1096, str, NULL); } }
