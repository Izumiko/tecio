 #pragma once
#include "ThirdPartyHeadersBegin.h"
#include <cstdarg>
#include "ThirdPartyHeadersEnd.h"
#include "MASTER.h"
#include "GLOBAL.h"
extern bool _showMessage(MessageBoxType_e messageBoxType, char const* ___2433); namespace tecplot { namespace ___3934 { inline bool messageBox(MessageBoxType_e messageBoxType, char const* format, va_list args) { REQUIRE(VALID_ENUM(messageBoxType, MessageBoxType_e)); REQUIRE(VALID_REF(format)); char ___2456[5000]; vsprintf(___2456, format, args); return _showMessage(messageBoxType, ___2456); } inline bool ___1184(char const* format, ...) { va_list args; va_start(args, format); (void)messageBox(___2444, format, args); va_end(args); return false; } inline bool ___3248(char const* format, ...) { va_list args; va_start(args, format); bool ___2038 = (messageBox(___2450, format, args) == ___4227); va_end(args); return ___2038; } inline bool ___1930( FILE*       file, char const* format, ...) { va_list args; va_start(args, format); bool ___2038; if (file == NULL) ___2038 = messageBox(___2445, format, args); else ___2038 = (vfprintf(file, format, args) >= 0); va_end(args); return ___2038; } inline bool ___1930(char const* format, ...) { va_list args; va_start(args, format); bool ___2038 = messageBox(___2445, format, args); va_end(args); return ___2038; } }}
