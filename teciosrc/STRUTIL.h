 #pragma once
 #if defined EXTERN
 #undef EXTERN
 #endif
 #if defined ___3863
 #define EXTERN
 #else
 #define EXTERN extern
 #endif
#include "ThirdPartyHeadersBegin.h"
#include <set>
#include <string>
#include <vector>
#include "ThirdPartyHeadersEnd.h"
namespace tecplot { class ___3442; } EXTERN void ___1474(); EXTERN char* ___4410(const char* Format, va_list ___93); EXTERN char* ___1473(tecplot::___4219 Format, ...); EXTERN int   ___1473(std::string& ___417, tecplot::___4219 Format...); EXTERN char* ___1133(tecplot::___4219 ___3814); EXTERN void  ___676(char* ___3947, const char* ___3643, int ___1925, int ___682);
 #if !defined MSWIN
EXTERN void ___3353(char* S, short ___2872, short ___2697);
 #endif
EXTERN void  ___2336(char* str); EXTERN void  ___2337(char* str); EXTERN char* ___4226(char* ___3814); EXTERN char* ___3819(char* ___3814); EXTERN char* ___3860(char* ___3814, int ___2377); std::string& ___3859(std::string& str, size_t maxLength); char* ___3859(char* ___3814, int ___2377);
 #ifndef MSWIN
EXTERN ___3840 ___2246(const char* ___3814, uint32_t ___4477);
 #endif
EXTERN void        SkipSeparator(char const** ___683); EXTERN void        ___3610(char const** ___683); EXTERN void        ___3609(char const** ___683); EXTERN const char* ustrstr(const char* ___3431, const char* ___3432); EXTERN int         ustrncmp(const char* ___3431, const char* ___3432, size_t ___2222); EXTERN int         ustrcmp(const char* ___3431, const char* ___3432); ___372 isStringDelimiter(char C);
 #if !defined NO_ASSERTS
EXTERN ___372 ___1981(char** ___3434, const char* ___2701, ___372 ___2062, const char* ___1393, int ___2263);
 #define ___3356(___3434, ___2701, ___2062) ___1981(___3434, ___2701, ___2062, __FILE__, __LINE__)
 #else
EXTERN ___372 ___1981(char** ___3434, const char* ___2701, ___372 ___2062);
 #define ___3356(___3434, ___2701, ___2062) ___1981(___3434, ___2701, ___2062)
 #endif
EXTERN ___372 ___3942(char** ___3434, char const* ___3857, ___372 ___956, ___372 convertNewlineToEscSeq); EXTERN ___372 ___3941(char** ___3434, char const* ___3857, ___372 convertNewlineToEscSeq); EXTERN ___372 ___3940(char** ___3434, char ___474); EXTERN ___372 ___3354(char** ___3814); EXTERN ___372 ___3352(char** S); EXTERN ___372 ___1185(char** S, char ___957); EXTERN ___372 ___3440(tecplot::___3442& ___3441, char ___3916, ___372 ___2876); EXTERN char* ___654(const char* ___2885); EXTERN char* ___652( const char* ___2700, ___372 ___3475); EXTERN char* ___1953(char* ___339, char* ___2688); inline char* EndOfString(char* str) { return str + strlen(str); }; inline char const* EndOfString(char const* str) { return str + strlen(str); };
