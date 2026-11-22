#include "MASTER.h"
#include "GLOBAL.h"
#include "Q_UNICODE.h"
#include "CodeContract.h"
 #if defined MSWIN
#include "UnicodeStringUtils.h"
 #endif
#include "ALLOC.h"
#include "STRUTIL.h"
using namespace tecplot;
 #define MAXCHARACTERSPERLINE 60
___372 ___4478(char const* ___2874, char** ___2701) { size_t ___2164; if (___2874 == NULL) return (___1303); ___2164          = strlen(___2874); *___2701 = ___23(___2164 + 1, char, "new error message string"); if (*___2701 == NULL) return (___1303); strcpy(*___2701, ___2874); if (___2164 > MAXCHARACTERSPERLINE) { char* LineStart = *___2701; char* LastWord  = *___2701; char* WPtr      = *___2701; while (WPtr && (*WPtr != '\0')) { size_t CurLen; WPtr = strchr(LineStart, '\n'); if (WPtr && ((WPtr - LineStart) < MAXCHARACTERSPERLINE)) { WPtr++; while (*WPtr == '\n') WPtr++; LineStart = WPtr; while (*WPtr == ' ') WPtr++; LastWord = WPtr; continue; } WPtr = strchr(LastWord, ' '); if (WPtr != NULL) { while (*WPtr == ' ') WPtr++; } if (WPtr == NULL) { CurLen = strlen(LineStart); } else { CurLen = WPtr - LineStart; } if (CurLen > MAXCHARACTERSPERLINE) { if (LastWord == LineStart) { if (WPtr && (*WPtr != '\0')) { *(WPtr - 1) = '\n'; LastWord    = WPtr; } } else { *(LastWord - 1) = '\n'; } LineStart = LastWord; } else LastWord = WPtr; } } return (___4227); } namespace { void SendMessageToFile(FILE* F, char const* S, MessageBoxType_e messageBoxType) { REQUIRE(VALID_REF(F)); REQUIRE(VALID_REF(S)); REQUIRE(VALID_ENUM(messageBoxType, MessageBoxType_e)); REQUIRE( messageBoxType == ___2444 || messageBoxType == ___2448 || messageBoxType == ___2445); char* S2 = NULL; if (___4478(S, &S2)) { switch (messageBoxType) { case ___2444: fprintf(F, "Error: %s\n", S2); break; case ___2448: fprintf(F, "Warning: %s\n", S2); break; case ___2445: fprintf(F, "Info: %s\n", S2); break; default: ___476(___1303); break; } ___1528(S2, "temp info string"); } } } namespace { void defaultErrMsg(char const* Msg) { REQUIRE(VALID_REF(Msg));
 #if defined MSWIN
::MessageBoxA(NULL, Msg, "Error", MB_OK | MB_ICONERROR);
 #else
SendMessageToFile(stderr, Msg, ___2444);
 #endif
} } namespace { void postMessage(std::string const& ___2433, MessageBoxType_e messageBoxType) { { if (messageBoxType == ___2444) defaultErrMsg(___2433.c_str()); else SendMessageToFile(stderr, ___2433.c_str(), messageBoxType); } } } namespace { void Message(char const* ___2433, MessageBoxType_e messageBoxType) { REQUIRE(VALID_NON_ZERO_LEN_STR(___2433)); REQUIRE(VALID_ENUM(messageBoxType, MessageBoxType_e)); REQUIRE( messageBoxType == ___2444 || messageBoxType == ___2448 || messageBoxType == ___2445); static ___372 InMessage = ___1303; if (!InMessage) { { SendMessageToFile(stderr, ___2433, messageBoxType); } } } } void Information(___4219 format, ...) { REQUIRE(!format.___2034()); ___372 cleanUp = ___4227; va_list ___93;
 #if defined(_MSC_VER)
 #pragma warning(push, 0)
 #pragma warning(disable : 4840)
 #endif
va_start(___93, format);
 #if defined(_MSC_VER)
 #pragma warning(pop)
 #endif
char* ___2433 = ___4410(format.c_str(), ___93); va_end(___93); if (___2433 == NULL) { cleanUp = ___1303; ___2433 = (char*)format.c_str(); } Message(___2433, ___2445); if (cleanUp) ___1528(___2433, "message"); } void ___4447(___4219 format, ...) { REQUIRE(!format.___2034()); ___372 cleanUp = ___4227; va_list ___93;
 #if defined(_MSC_VER)
 #pragma warning(push, 0)
 #pragma warning(disable : 4840)
 #endif
va_start(___93, format);
 #if defined(_MSC_VER)
 #pragma warning(pop)
 #endif
char* ___2433 = ___4410(format.c_str(), ___93); va_end(___93); if (___2433 == NULL) { cleanUp = ___1303; ___2433 = (char*)format.c_str(); } Message(___2433, ___2448); if (cleanUp) ___1528(___2433, "message"); } namespace { void PostErrorMessage(___4219 format, va_list ___93) { REQUIRE(!format.___2034()); ___372 cleanUp       = ___4227; char*     ___2456 = ___4410(format.c_str(), ___93); if (___2456 == NULL) { cleanUp       = ___1303; ___2456 = (char*)format.c_str(); } postMessage(___2456, ___2444); if (cleanUp) ___1528(___2456, "messageString"); } } void ___4407(___4219 format, va_list ___93) { REQUIRE(!format.___2034()); static ___372 InErrMsg = ___1303; if (!InErrMsg) { PostErrorMessage(format, ___93); } } void ___1175(___4219 format, ...) { REQUIRE(!format.___2034()); va_list ___93;
 #if defined(_MSC_VER)
 #pragma warning(push, 0)
 #pragma warning(disable : 4840)
 #endif
va_start(___93, format);
 #if defined(_MSC_VER)
 #pragma warning(pop)
 #endif
PostErrorMessage(format, ___93); va_end(___93); }
