#include "FileStreamWriter.h"
#include "MASTER.h"
#include "GLOBAL.h"
#include "CodeContract.h"
#include "showMessage.h"
namespace tecplot { namespace ___3934 { FileStreamWriter::FileStreamWriter(std::string const& ___1392) : m_fileIOStream(___1392) {} FileStreamWriter::~FileStreamWriter() { m_fileIOStream.close(true); } ___372 FileStreamWriter::___2040() const { return m_fileIOStream.___2040(); } ___372 FileStreamWriter::open(bool update) { REQUIRE(!___2040()); ___372 ___2038; if (update) { ___2038 = m_fileIOStream.open("rb+"); if (!___2038) ___2038 = m_fileIOStream.open("wb+"); } else { ___2038 = m_fileIOStream.open("wb+"); } if (___2038) {
 #if !defined NDEBUG
{ if (m_fileIOStream.___2001()) if (setvbuf(m_fileIOStream.handle(), NULL, _IONBF, 0) != 0) ___2038 = ___1303; }
 #endif
} else { ___1184("Cannot write to file %s", m_fileIOStream.___1392().c_str()); }
 #ifdef PROFILE_FILE_ACCESS
___476( statistics().numFSeeksPerformed == 0 && statistics().numReadWritesPerformed == 0 && statistics().___2781 == 0);
 #endif
return ___2038; } ___372 FileStreamWriter::close(bool ___3362) { return m_fileIOStream.close(___3362); } ___1391 FileStreamWriter::fileLoc() { REQUIRE(___2040()); return m_fileIOStream.fileLoc(); } ___372 FileStreamWriter::___3461() { REQUIRE(___2040()); return m_fileIOStream.___3461(); } ___372 FileStreamWriter::___3460(___1391 fileLoc) { REQUIRE(___2040()); REQUIRE(fileLoc != ___330); return m_fileIOStream.___3460(fileLoc); } ___372 FileStreamWriter::seekToFileEnd() { REQUIRE(___2040()); return m_fileIOStream.seekToFileEnd(); } std::string const& FileStreamWriter::___1392() const { return m_fileIOStream.___1392(); } void FileStreamWriter::___3495(___372 ___2001) { REQUIRE(VALID_BOOLEAN(___2001)); m_fileIOStream.___3495(___2001); } ___372 FileStreamWriter::___2001() const { return m_fileIOStream.___2001(); } void FileStreamWriter::setDataFileType(DataFileType_e ___842) { REQUIRE(VALID_ENUM(___842, DataFileType_e)); m_fileIOStream.setDataFileType(___842); } DataFileType_e FileStreamWriter::___842() const { return m_fileIOStream.___842(); } class FileIOStatistics& FileStreamWriter::statistics() { return m_fileIOStream.statistics(); } size_t FileStreamWriter::fwrite(void const* ___416, size_t size, size_t count) { REQUIRE(___2040()); REQUIRE(VALID_REF(___416)); size_t ___3359 = ::fwrite(___416, size, count, m_fileIOStream.handle());
 #ifdef PROFILE_FILE_ACCESS
if (___3359 > 0) { statistics().numReadWritesPerformed++; statistics().___2781 += ___3359 * size; }
 #endif
return ___3359; } int FileStreamWriter::fprintf(char const* format, ...) { REQUIRE(___2040()); REQUIRE(VALID_NON_ZERO_LEN_STR(format)); va_list args; va_start(args, format); int ___3359 = ::vfprintf(m_fileIOStream.handle(), format, args); va_end(args);
 #ifdef PROFILE_FILE_ACCESS
if (___3359 > 0) { statistics().numReadWritesPerformed++; statistics().___2781 += ___3359; }
 #endif
return ___3359; } }}
