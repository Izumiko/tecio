#include "FileStreamReader.h"
#include "MASTER.h"
#include "GLOBAL.h"
#include "CodeContract.h"
#include "showMessage.h"
namespace tecplot { namespace ___3934 { FileStreamReader::FileStreamReader(std::string const& ___1392) : m_fileIOStream(___1392) {} FileStreamReader::~FileStreamReader() { m_fileIOStream.close(true); } ___372 FileStreamReader::___2040() const { return m_fileIOStream.___2040(); } ___372 FileStreamReader::open() { REQUIRE(!___2040()); ___372 ___2038 = m_fileIOStream.open("rb"); if (!___2038) ___1184("Cannot read file %s", ___1392().c_str());
 #ifdef PROFILE_FILE_ACCESS
___476( statistics().numFSeeksPerformed == 0 && statistics().numReadWritesPerformed == 0 && statistics().___2781 == 0);
 #endif
return ___2038; } ___372 FileStreamReader::close(bool ___3362) { return m_fileIOStream.close(___3362); } ___1391 FileStreamReader::fileLoc() { REQUIRE(___2040()); return m_fileIOStream.fileLoc(); } ___372 FileStreamReader::___3461() { REQUIRE(___2040()); return m_fileIOStream.___3461(); } ___372 FileStreamReader::___3460(___1391 fileLoc) { REQUIRE(___2040()); REQUIRE(fileLoc != ___330); return m_fileIOStream.___3460(fileLoc); } ___372 FileStreamReader::seekToFileEnd() { REQUIRE(___2040()); return m_fileIOStream.seekToFileEnd(); } std::string const& FileStreamReader::___1392() const { return m_fileIOStream.___1392(); } void FileStreamReader::___3495(___372 ___2001) { REQUIRE(VALID_BOOLEAN(___2001)); m_fileIOStream.___3495(___2001); } ___372 FileStreamReader::___2001() const { return m_fileIOStream.___2001(); } void FileStreamReader::setDataFileType(DataFileType_e ___842) { REQUIRE(VALID_ENUM(___842, DataFileType_e)); m_fileIOStream.setDataFileType(___842); } DataFileType_e FileStreamReader::___842() const { return m_fileIOStream.___842(); } class FileIOStatistics& FileStreamReader::statistics() { return m_fileIOStream.statistics(); } size_t FileStreamReader::fread(void* ___416, size_t size, size_t count) { REQUIRE(VALID_REF(___416)); REQUIRE(___2040()); size_t ___3359 = ::fread(___416, size, count, m_fileIOStream.handle());
 #ifdef PROFILE_FILE_ACCESS
if (___3359 > 0) { statistics().numReadWritesPerformed++; statistics().___2781 += ___3359 * size; }
 #endif
return ___3359; } char* FileStreamReader::fgets(char* s, int size) { REQUIRE(VALID_REF(s)); REQUIRE(size >= 0); REQUIRE(___2040()); char* ___3359 = ::fgets(s, size, m_fileIOStream.handle());
 #ifdef PROFILE_FILE_ACCESS
if (___3359 != NULL) { statistics().numReadWritesPerformed++; statistics().___2781 += ___3359 ? strlen(s) : 0; }
 #endif
return ___3359; } int FileStreamReader::feof() { REQUIRE(___2040()); return ::feof(m_fileIOStream.handle()); } int FileStreamReader::getc() { REQUIRE(___2040()); int ___3359 = ::getc(m_fileIOStream.handle());
 #ifdef PROFILE_FILE_ACCESS
statistics().numReadWritesPerformed++; statistics().___2781++;
 #endif
return ___3359; } int FileStreamReader::ungetc(int c) { REQUIRE(___2040()); int ___3359 = ::ungetc(c, m_fileIOStream.handle());
 #ifdef PROFILE_FILE_ACCESS
___476(statistics().___2781 > 0); statistics().___2781--;
 #endif
return ___3359; } int FileStreamReader::fscanf(char const* format, void* ___3252) { REQUIRE(___2040()); REQUIRE(VALID_NON_ZERO_LEN_STR(format)); REQUIRE(VALID_REF(___3252));
 #ifdef PROFILE_FILE_ACCESS
___1391 startLoc = fileLoc();
 #endif
int ___3359 = ::fscanf(m_fileIOStream.handle(), format, ___3252);
 #ifdef PROFILE_FILE_ACCESS
___1391 endLoc = fileLoc(); statistics().numReadWritesPerformed++; statistics().___2781 += (endLoc - startLoc);
 #endif
return ___3359; } int FileStreamReader::fscanf(char const* format, void* ptr1, void* ptr2) { REQUIRE(___2040()); REQUIRE(VALID_NON_ZERO_LEN_STR(format)); REQUIRE(VALID_REF(ptr1)); REQUIRE(VALID_REF(ptr2));
 #ifdef PROFILE_FILE_ACCESS
___1391 startLoc = fileLoc();
 #endif
int ___3359 = ::fscanf(m_fileIOStream.handle(), format, ptr1, ptr2);
 #ifdef PROFILE_FILE_ACCESS
___1391 endLoc = fileLoc(); statistics().numReadWritesPerformed++; statistics().___2781 += (endLoc - startLoc);
 #endif
return ___3359; } int FileStreamReader::fscanf(char const* format, void* ptr1, void* ptr2, void* ptr3) { REQUIRE(___2040()); REQUIRE(VALID_NON_ZERO_LEN_STR(format)); REQUIRE(VALID_REF(ptr1)); REQUIRE(VALID_REF(ptr2)); REQUIRE(VALID_REF(ptr3));
 #ifdef PROFILE_FILE_ACCESS
___1391 startLoc = fileLoc();
 #endif
int ___3359 = ::fscanf(m_fileIOStream.handle(), format, ptr1, ptr2, ptr3);
 #ifdef PROFILE_FILE_ACCESS
___1391 endLoc = fileLoc(); statistics().numReadWritesPerformed++; statistics().___2781 += (endLoc - startLoc);
 #endif
return ___3359; } }}
