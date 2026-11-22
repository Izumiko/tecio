#include "FileIOStream.h"
#include "MASTER.h"
#include "GLOBAL.h"
#include "CodeContract.h"
#include "FileSystem.h"
namespace tecplot { namespace ___3934 { FileIOStream::FileIOStream(std::string const& ___1392) : m_fileHandle(NULL) , ___2462(___1392) , m_isAscii(false) , m_dataFileType(___843) { REQUIRE(!___2462.empty()); } FileIOStream::~FileIOStream() { close(true); } ___372 FileIOStream::___2040() const { return m_fileHandle != NULL; } ___372 FileIOStream::close(bool ___3362) { ___372 ___3359 = ___4227; if (___2040()) { ___4196(m_fileHandle); m_fileHandle = NULL; if (!___3362) { ___476(!___1392().empty()); if (remove(___1392().c_str()) != 0) ___3359 = ___1303; }
 #ifdef PROFILE_FILE_ACCESS
m_statistics.numFSeeksPerformed     = 0; m_statistics.numReadWritesPerformed = 0; m_statistics.___2781      = 0;
 #endif
} else { ___3359 = ___1303; } ENSURE(VALID_BOOLEAN(___3359)); return ___3359; } ___1391 FileIOStream::fileLoc() { REQUIRE(___2040()); ___1391 fileLoc = ___1391(___4202(m_fileHandle)); ENSURE(fileLoc != ___330); return fileLoc; } ___372 FileIOStream::___3461() { REQUIRE(___2040());
 #ifdef PROFILE_FILE_ACCESS
m_statistics.numFSeeksPerformed++;
 #endif
return ___4201(m_fileHandle, ___1391(0), SEEK_SET) == 0; } ___372 FileIOStream::___3460(___1391 fileLoc) { REQUIRE(___2040()); REQUIRE(fileLoc != ___330);
 #ifdef PROFILE_FILE_ACCESS
m_statistics.numFSeeksPerformed++;
 #endif
return ___4201(m_fileHandle, fileLoc, SEEK_SET) == 0; } ___372 FileIOStream::seekToFileEnd() { REQUIRE(___2040());
 #ifdef PROFILE_FILE_ACCESS
m_statistics.numFSeeksPerformed++;
 #endif
return ___4201(m_fileHandle, ___1391(0), SEEK_END) == 0; } std::string const& FileIOStream::___1392() const { return ___2462; } void FileIOStream::___3495(___372 ___2001) { REQUIRE(VALID_BOOLEAN(___2001)); m_isAscii = (___2001 == ___4227); } ___372 FileIOStream::___2001() const { return m_isAscii; } void FileIOStream::setDataFileType(DataFileType_e ___842) { REQUIRE(VALID_ENUM(___842, DataFileType_e)); m_dataFileType = ___842; } DataFileType_e FileIOStream::___842() const { return m_dataFileType; } class FileIOStatistics& FileIOStream::statistics() { return m_statistics; } ___372 FileIOStream::open(std::string const& ___2505) { REQUIRE(!___1392().empty()); REQUIRE(!___2040()); m_fileHandle   = tecplot::filesystem::fileOpen(___1392(), ___2505); ___372 ___2038 = m_fileHandle != NULL;
 #ifdef PROFILE_FILE_ACCESS
___476( m_statistics.numFSeeksPerformed == 0 && m_statistics.numReadWritesPerformed == 0 && m_statistics.___2781 == 0);
 #endif
return ___2038; } FILE* FileIOStream::handle() const { return m_fileHandle; } }}
