 #pragma once
#include "ThirdPartyHeadersBegin.h"
#include <string>
#include "ThirdPartyHeadersEnd.h"
#include "MASTER.h"
#include "GLOBAL.h"
#include "basicTypes.h"
#include "FileIOStream.h"
#include "FileWriterInterface.h"
namespace tecplot { namespace ___3934 { class FileStreamWriter : public FileWriterInterface { public: explicit FileStreamWriter(std::string const& ___1392); virtual ~FileStreamWriter(); virtual ___372               ___2040() const; virtual ___372               close(bool ___3362); virtual ___1391               fileLoc(); virtual ___372               ___3461(); virtual ___372               ___3460(___1391 fileLoc); virtual ___372               seekToFileEnd(); virtual std::string const&      ___1392() const; virtual void                    ___3495(___372 ___2001); virtual ___372               ___2001() const; virtual void                    setDataFileType(DataFileType_e ___842); virtual DataFileType_e          ___842() const; virtual class FileIOStatistics& statistics(); virtual ___372 open(bool update); virtual size_t    fwrite(void const* ___416, size_t size, size_t count); virtual int       fprintf(char const* format, ...); private: FileIOStream m_fileIOStream; UNCOPYABLE_CLASS(FileStreamWriter); }; }}
