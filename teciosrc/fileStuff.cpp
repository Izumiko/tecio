#include "fileStuff.h"
#include "ThirdPartyHeadersBegin.h"
#include <stdarg.h>
#include <string>
#include "ThirdPartyHeadersEnd.h"
#include "SzlFileLoader.h"
using std::string; namespace tecplot { namespace ___3934 { std::string getFileNameSansFolder(std::string const& ___1392) { REQUIRE(!___1392.empty()); size_t beginBaseFileNamePos; size_t backslashPos    = ___1392.rfind('\\'); size_t forwardSlashPos = ___1392.rfind('/'); if (backslashPos != string::npos) if (forwardSlashPos != string::npos) beginBaseFileNamePos = std::max(backslashPos, forwardSlashPos) + 1; else beginBaseFileNamePos = backslashPos + 1; else if (forwardSlashPos != string::npos) beginBaseFileNamePos = forwardSlashPos + 1; else beginBaseFileNamePos = 0; std::string baseFileName = ___1392.substr(beginBaseFileNamePos, string::npos); ENSURE(!baseFileName.empty()); return baseFileName; } }}
