 #pragma once
#include "ThirdPartyHeadersBegin.h"
#include <string>
#include "ThirdPartyHeadersEnd.h"
#include "MASTER.h"
#include "GLOBAL.h"
#include "basicTypes.h"
#include "CodeContract.h"
namespace tecplot { namespace ___3934 { class FileIOStreamInterface { public: virtual ___372               ___2040() const                               = 0; virtual ___372               close(bool ___3362)                           = 0; virtual ___1391               fileLoc()                                    = 0; virtual ___372               ___3461()                            = 0; virtual ___372               ___3460(___1391 fileLoc)             = 0; virtual ___372               seekToFileEnd()                              = 0; virtual std::string const&      ___1392() const                             = 0; virtual void                    ___3495(___372 ___2001)                = 0; virtual ___372               ___2001() const                              = 0; virtual void                    setDataFileType(DataFileType_e ___842) = 0; virtual DataFileType_e          ___842() const                         = 0; virtual class FileIOStatistics& statistics()                                 = 0; virtual ~FileIOStreamInterface() {} }; }}
