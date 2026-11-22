#include "MASTER.h"
 #define ___3863
#include "GLOBAL.h"
#include "stdafx.h"
#include "TASSERT.h"
#include "Q_UNICODE.h"
#include "CodeContract.h"
#include "ThirdPartyHeadersBegin.h"
#include <algorithm>
#include <cctype> 
#include <limits.h>
#include "ThirdPartyHeadersEnd.h"
#include "ALLOC.h"
#include "ARRLIST.h"
#include "CHARTYPE.h"
#include "Q_MSG.h"
#include "STRLIST.h"
#include "STRUTIL.h"
#include "TranslatedString.h"
#include "stringformat.h"
using std::string; using tecplot::___1095; using tecplot::___4218; using tecplot::___4219;
 #ifdef MSWIN
 #pragma warning(disable : 4786) 
 #endif
 #define FORMAT_BUFFER_SIZE 16384
static char* FormatStringBuffer     = NULL; static int   FormatStringBufferSize = FORMAT_BUFFER_SIZE; void ___1474() { if (FormatStringBuffer != NULL) free(FormatStringBuffer); FormatStringBuffer = NULL; } char* ___4410(const char* Format, va_list ___93) { char* ___3360 = NULL; REQUIRE(VALID_REF(Format)); if (FormatStringBuffer == NULL) FormatStringBuffer = (char*)malloc(FormatStringBufferSize); if (FormatStringBuffer != NULL) {
 #if defined MSWIN
ASSERT_ONLY(int nChars =) _vsnprintf(FormatStringBuffer, FormatStringBufferSize, Format, ___93);
 #else
ASSERT_ONLY(int nChars =) vsnprintf(FormatStringBuffer, FormatStringBufferSize, Format, ___93);
 #endif
FormatStringBuffer[FormatStringBufferSize - 1] = '\0'; ___476(nChars > 0); ___3360 = ___1133(___1095(FormatStringBuffer)); } ENSURE(VALID_REF(___3360) || ___3360 == NULL); return ___3360; } char* ___1473(___4219 Format, ...) { REQUIRE(!Format.___2034()); va_list ___93;
 #if defined(_MSC_VER)
 #pragma warning(push, 0)
 #pragma warning(disable : 4840)
 #endif
va_start(___93, Format);
 #if defined(_MSC_VER)
 #pragma warning(pop)
 #endif
char* ___3360 = ___4410(Format.c_str(), ___93); va_end(___93); ENSURE(VALID_REF(___3360) || ___3360 == NULL); return ___3360; } int ___1473(string& ___417, ___4219 Format...) { REQUIRE(!Format.___2034()); va_list ___93;
 #if defined(_MSC_VER)
 #pragma warning(push, 0)
 #pragma warning(disable : 4840)
 #endif
va_start(___93, Format);
 #if defined(_MSC_VER)
 #pragma warning(pop)
 #endif
char* FormattedString = ___4410(Format.c_str(), ___93); va_end(___93); int ___3360; if (FormattedString != NULL) { ___417.assign(FormattedString); ___3360 = (int)___417.size(); ___1528(FormattedString, "FormattedString"); } else ___3360 = -1; ENSURE(___3360 == -1 || ___3360 >= 0); return ___3360; } char* ___1133(___4219 ___3814) { REQUIRE(VALID_TRANSLATED_STRING(___3814)); char* ___3360 = ___23(strlen(___3814.c_str()) + 1, char, "duplicate string"); if (___3360 != NULL) strcpy(___3360, ___3814.c_str()); ENSURE(___3360 == NULL || (VALID_REF(___3360) && strcmp(___3360, ___3814.c_str()) == 0)); return ___3360; } void ___676(char* ___3947, const char* ___3643, int ___1925, int ___682) { int ___2223 = 0; REQUIRE(VALID_REF(___3947)); REQUIRE( "Target string is sized to accommodate a string who's length " "is at least MIN(strlen(&Source[Index]), Count) characters."); REQUIRE(VALID_REF(___3643)); REQUIRE(0 <= ___1925 && ___1925 <= (int)strlen(___3643)); REQUIRE(___682 >= 0); ___2223 = MIN((int)strlen(&___3643[___1925]), ___682); memmove(___3947, &___3643[___1925], ___2223); ___3947[___2223] = '\0'; ENSURE(VALID_REF(___3947) && (int)strlen(___3947) == ___2223); } char* ___3819(char* ___3814) { char* ___3360 = ___3814; char* Start  = ___3814; REQUIRE(VALID_REF(___3814)); while (tecplot::isspace(*Start)) Start++; if (Start != ___3814) memmove(___3814, Start, strlen(Start) + 1); ENSURE(VALID_REF(___3360) && ___3360 == ___3814); return ___3360; } static char* StringFlushRight(char* ___3814) { REQUIRE(VALID_REF(___3814)); char* ___3360 = ___3814; char* End = ___3814 + strlen(___3814) - 1; while (End > ___3814 && tecplot::isspace(*End)) End--; *(End + 1) = '\0'; ENSURE(VALID_REF(___3360) && ___3360 == ___3814); return ___3360; } char* ___4226(char* ___3814) { REQUIRE((___3814 == NULL) || VALID_REF(___3814)); if (___3814) return (___3819(StringFlushRight(___3814))); else return ___3814; } char* ___3860(char* ___3814, int ___2377) { REQUIRE(VALID_REF(___3814)); REQUIRE(___2377 >= 0); if ((int)strlen(___3814) > ___2377) ___3814[___2377] = '\0'; ENSURE(VALID_REF(___3814)); ENSURE((int)strlen(___3814) <= ___2377); return ___3814; } std::string& ___3859(std::string& str, size_t maxLength) { if (!str.empty()) { ___3859(&str[0], static_cast<int>(maxLength)); str.resize(std::min(strlen(&str[0]), maxLength)); } return str; } char* ___3859(char* ___3814, int ___2377) { REQUIRE(VALID_REF(___3814)); REQUIRE(___2377 >= 0); ___3819(___3814); ___3860(___3814, ___2377); StringFlushRight(___3814); ENSURE(VALID_REF(___3814)); ENSURE((int)strlen(___3814) <= ___2377); ENSURE(IMPLICATION(strlen(___3814) != 0, (!tecplot::isspace(___3814[0]) && !tecplot::isspace(___3814[strlen(___3814) - 1])))); return ___3814; }
 #ifndef MSWIN
___3840 ___2246(const char* ___3814, uint32_t ___4477) { REQUIRE(VALID_REF(___3814)); ___3840 ___3360 = ___3822(); if (___3360 != NULL) { ___372 ___2039 = ___4227; if (strlen(___3814) > ___4477) { char* StringCopy = ___1133(___1095(___3814)); ___2039             = (StringCopy != NULL); if (___2039) { char*    ___683         = StringCopy; char*    SubString    = StringCopy; uint32_t SubStringLen = 0; while (*___683 != '\0' && ___2039) { while (*___683 != '\0' && SubStringLen < ___4477) { if (*___683 == '\n') { *___683 = '\0'; ___683++; break; } ___683++; SubStringLen++; } if (*___683 != '\0' && SubStringLen == ___4477) { if (*___683 != ' ') { while (___683 != SubString && *___683 != ' ') ___683--; if (*___683 != ' ') { while (*___683 != '\0' && *___683 != ' ' && *___683 != '\n') ___683++; while (*___683 != '\0' && *___683 == ' ') ___683++; } } if (*___683 != '\0') { *___683 = '\0'; ___683++; } StringFlushRight(SubString); } ___2039         = ___3824(___3360, SubString); SubString    = ___683; SubStringLen = 0; } ___1528(StringCopy, "StringCopy"); } } else ___2039 = ___3824(___3360, ___3814); if (!___2039) ___3829(&___3360); } ENSURE(___3360 == NULL || VALID_REF(___3360)); return ___3360; }
 #endif
int ustrncmp(const char* ___3431, const char* ___3432, size_t ___2222) { REQUIRE((___3431 == NULL) || VALID_REF(___3431)); REQUIRE((___3432 == NULL) || VALID_REF(___3432)); char*  t1; char*  t2; char   ct1; char   ct2; size_t ___1831 = 0; if ((___3431 == NULL) && (___3432 == NULL)) return 0; if (___3431 == NULL) return -1; else if (___3432 == NULL) return 1; t1 = (char*)___3431; t2 = (char*)___3432; while (*t1 && *t2 && (___1831 < ___2222)) { ct1 = ___442(*t1); ct2 = ___442(*t2); if (ct1 != ct2) return (ct1 - ct2); t1++; t2++; ___1831++; } if ((___1831 == ___2222) || ((*t1 == '\0') && (*t2 == '\0'))) return 0; else return ___442(*t1) - ___442(*t2); } int ustrcmp(const char* ___3431, const char* ___3432) { REQUIRE((___3431 == NULL) || VALID_REF(___3431)); REQUIRE((___3432 == NULL) || VALID_REF(___3432)); return (ustrncmp(___3431, ___3432, INT_MAX)); }
 #if !defined NO_ASSERTS
___372 ___1981(char** ___3434, const char* ___2701, ___372 ___2062, const char* ___1393, int ___2263)
 #else
___372 ___1981(char** ___3434, const char* ___2701, ___372 ___2062)
 #endif
{ REQUIRE(VALID_REF(___3434)); REQUIRE(*___3434 == NULL || VALID_REF(*___3434)); REQUIRE(___2701 == NULL || VALID_REF(___2701)); REQUIRE(IMPLICATION(VALID_REF(*___3434), *___3434 != ___2701)); REQUIRE(VALID_BOOLEAN(___2062)); REQUIRE(VALID_NON_ZERO_LEN_STR(___1393)); REQUIRE(___2263 >= 1); if (*___3434) {
 #if !defined NO_ASSERTS && defined DEBUG_ALLOC
char S[80 + 1]; MakeDebugRecord(___1393, ___2263, "releasing", *___3434, S, 80); ___1528(*___3434, S);
 #else
___1528(*___3434, "");
 #endif
} if (___2701 == NULL) { *___3434 = NULL; return (___4227); } else {
 #if !defined NO_ASSERTS && defined DEBUG_ALLOC
char S[80 + 1]; MakeDebugRecord(___1393, ___2263, "duplicating", ___2701, S, 80); *___3434 = ___23(strlen(___2701) + 1, char, S);
 #else
*___3434 = ___23(strlen(___2701) + 1, char, "");
 #endif
if (*___3434) { strcpy(*___3434, ___2701); return (___4227); } else { if (___2062) ___1175(___4218("Out of memory")); return (___1303); } } } ___372 ___3942(char** ___3434, char const* ___3857, ___372 ___956, ___372 convertNewlineToEscSeq) { size_t      CurLen; size_t      NewLen; int         NumNewlines = 0; char*       ___2701; const char* ___683 = ___3857; ___372   ___2039 = ___4227; REQUIRE(VALID_REF(___3434)); REQUIRE((___3857 == NULL) || VALID_REF(___3857)); REQUIRE(VALID_BOOLEAN(___956)); REQUIRE(VALID_BOOLEAN(convertNewlineToEscSeq)); if ((___3857 == NULL) || (*___3857 == '\0')) { if (___3857 && (*___3857 == '\0') && ___956) { char* TMP = (char*)___3857; ___1528(TMP, "empty string to add"); } } else { if (*___3434 == NULL) CurLen = 0; else CurLen = strlen(*___3434); while (*___683) if (*___683++ == '\n') NumNewlines++; NewLen = CurLen + strlen(___3857) + 1 + NumNewlines; ___2701 = ___23(NewLen, char, ___3857); if (___2701 == NULL) { if (___956) { char* TMP = (char*)___3857; ___1528(TMP, ___3857); } ___2039 = ___1303; } else { if (*___3434) { strcpy(___2701, *___3434); ___1528(*___3434, (CurLen > 0 ? *___3434 : "previous text")); } else *___2701 = '\0'; { char*       NPtr = EndOfString(___2701); const char* APtr = ___3857; while (*APtr) { if ((*APtr == '\n') && convertNewlineToEscSeq) { *NPtr++ = '\\'; *NPtr++ = 'n'; } else *NPtr++ = *APtr; APtr++; } *NPtr = '\0'; } if (___956) { char* TMP = (char*)___3857; ___1528(TMP, ___3857); } *___3434 = ___2701; } } ENSURE(VALID_BOOLEAN(___2039)); return (___2039); } ___372 ___3941(char** ___3434, char const* ___3857, ___372 convertNewlineToEscSeq) { size_t      CurLen; size_t      NewLen; int         NumNewlines = 0; char*       ___2701; const char* ___683 = ___3857; ___372   ___2039 = ___4227; REQUIRE(VALID_REF(___3434)); REQUIRE((___3857 == NULL) || VALID_REF(___3857)); REQUIRE(VALID_BOOLEAN(convertNewlineToEscSeq)); if ((___3857 != NULL) && (*___3857 != '\0')) { if (*___3434 == NULL) CurLen = 0; else CurLen = strlen(*___3434); while (*___683) if (*___683++ == '\n') NumNewlines++; NewLen = CurLen + strlen(___3857) + 1 + NumNewlines; ___2701 = ___23(NewLen, char, ___3857); if (___2701 == NULL) { ___2039 = ___1303; } else { if (*___3434) { strcpy(___2701, *___3434); ___1528(*___3434, (CurLen > 0 ? *___3434 : "previous text")); } else *___2701 = '\0'; { char*       NPtr = EndOfString(___2701); const char* APtr = ___3857; while (*APtr) { if ((*APtr == '\n') && convertNewlineToEscSeq) { *NPtr++ = '\\'; *NPtr++ = 'n'; } else *NPtr++ = *APtr; APtr++; } *NPtr = '\0'; } *___3434 = ___2701; } } ENSURE(VALID_BOOLEAN(___2039)); return (___2039); } ___372 ___3940(char** ___3434, char ___474) { REQUIRE(VALID_REF(___3434)); char S[2]; S[0] = ___474; S[1] = '\0'; return (___3942(___3434, S, ___1303, ___1303)); } ___372 ___3354(char** ___3814)
{ size_t ___1831; int    NewlineCount; size_t ___2223; char*  Replacement; REQUIRE(VALID_REF(___3814)); REQUIRE(VALID_REF(*___3814)); NewlineCount = 0; ___2223       = strlen(*___3814); for (___1831 = 0; ___1831 < ___2223; ___1831++) if ((*___3814)[___1831] == '\n') NewlineCount++; if (NewlineCount != 0) { Replacement = ___23(___2223 + NewlineCount + 1, char, "replacement string"); if (Replacement != NULL) { size_t ___2105; for (___1831 = ___2105 = 0; ___1831 < ___2223 + 1; ___1831++, ___2105++) { if ((*___3814)[___1831] == '\n') { Replacement[___2105] = '\\'; ___2105++; Replacement[___2105] = 'n'; } else { Replacement[___2105] = (*___3814)[___1831]; } } ___476(___1831 == ___2223 + 1); ___476(___2105 == ___2223 + NewlineCount + 1); } ___1528(*___3814, "original string"); *___3814 = Replacement; } ENSURE(*___3814 == NULL || VALID_REF(*___3814)); return (*___3814 != NULL); }
