 #pragma once
#include "ThirdPartyHeadersBegin.h"
#  include <algorithm>
#  include <new>
#include "ThirdPartyHeadersEnd.h"
#include "MASTER.h"
#include "GLOBAL.h"
#include "ClassMacros.h"
#include "CodeContract.h"
#include "MinMax.h"
#include "ItemAddress.h"
inline uint64_t numBytesForNumBits(uint64_t numBits) { return (numBits + 7) / 8; } namespace { template <typename T> uint64_t const* getRealMemPtr(T* const& ___3249) { REQUIRE(VALID_REF(___3249)); uint64_t const* uint64Array = (uint64_t const*)___3249; return uint64Array-1; } } namespace { template <typename T> uint64_t* getRealMemPtr(T*& ___3249) { REQUIRE(VALID_REF(___3249)); uint64_t* uint64Array = (uint64_t*)___3249; return uint64Array-1; } } namespace tecplot { namespace ___3931 { template<typename T> class ___2238 { public: ___2238(___2238 const&) = delete; ___2238& operator=(___2238 const&) = delete; ___2238(___2238&& ___2886) : m_ptr(std::move(___2886.m_ptr))
 #if !defined NO_ASSERTS
, m_size(std::move(___2886.m_size))
 #endif
{ ___2886.m_ptr = nullptr;
 #if !defined NO_ASSERTS
___2886.m_size = 0;
 #endif
} ___2238& operator=(___2238&& ___3390) { if (this != &___3390) { ___935(); m_ptr = std::move(___3390.m_ptr); ___3390.m_ptr = nullptr;
 #if !defined NO_ASSERTS
m_size = std::move(___3390.m_size); ___3390.m_size = 0;
 #endif
} return *this; } void ___2317( char const* container, size_t numElements) {
 #ifdef LARGE_ARRAY_MEMORY_LOGGING
size_t const MEMTRACK_CUTOFF = size_t(1000)*size_t(1000); if (numElements * sizeof(T) >= MEMTRACK_CUTOFF) { FILE *file = fopen("memtrack.txt", "at"); if (file) { fprintf(file, "%s\t%" "I64u" "\t%" "I64u" "\t%s\n", container, numElements, sizeof(T), typeid(T).___2683()); fclose(file); } else throw std::bad_alloc(); }
 #else
___4276(container); ___4276(numElements);
 #endif
} private: T* m_ptr;
 #ifndef NO_ASSERTS
uint64_t m_size;
 #endif
inline bool allocRawData(T*& ___3249, uint64_t requestedSize) { REQUIRE(___3249 == NULL); bool ___2037 = true; if (requestedSize > 0) { uint64_t const totalBytesRequired = sizeof(uint64_t) + requestedSize*uint64_t(sizeof(T)); uint64_t* mem = NULL; if ( sizeof(size_t) == 4 && totalBytesRequired > uint32_t(-1) ) { mem = NULL; } else { ___2317("LightweightVector", requestedSize); mem = (uint64_t *)malloc( static_cast<size_t>(totalBytesRequired) ); } ___2037 = (mem != NULL); if ( ___2037 ) { mem[0] = requestedSize; ___3249 = (T *)&mem[1]; ___2037 = true; } } else { ___476(___2037); ___3249 = NULL; } return ___2037; } inline void freeRawData(T*& ___3249) { REQUIRE(VALID_REF_OR_NULL(___3249)); if (___3249 != NULL) { free(getRealMemPtr(___3249)); ___3249 = NULL; } } public: ___2238() : m_ptr(NULL)
 #ifndef NO_ASSERTS
, m_size(0)
 #endif
{ } ~___2238() { ___935(); } inline void swap(___2238<T>& ___2886) { using std::swap; swap(m_ptr, ___2886.m_ptr);
 #ifndef NO_ASSERTS
swap(m_size, ___2886.m_size);
 #endif
} inline uint64_t size() const { uint64_t ___3356; if ( empty() ) ___3356 = 0; else ___3356 = getRealMemPtr(m_ptr)[0]; ENSURE(___3356 == m_size); return ___3356; } inline uint64_t numBytesAllocated(uint64_t knownSize) const { REQUIRE(IMPLICATION(empty(),knownSize==0)); REQUIRE(IMPLICATION(!empty(),knownSize==size())); if ( empty() ) return 0; else return sizeof(uint64_t) + knownSize*uint64_t(sizeof(T)); } inline bool empty() const { INVARIANT(EQUIVALENCE(m_ptr==NULL,m_size==0)); return ( m_ptr == NULL ); } inline bool alloc(uint64_t requestedSize) { REQUIRE(empty()); bool ___2037; if (!empty()) { ___2037 = false; } else { ___2037 = allocRawData(m_ptr, requestedSize); if ( ___2037 ) {
 #ifndef NO_ASSERTS
m_size = requestedSize;
 #endif
uint64_t pos = 0; try { for ( pos = 0; pos < requestedSize; pos++ ) ::new(&m_ptr[pos]) T; } catch (...) { for ( uint64_t pos2 = 0; pos2 < pos; pos++ ) m_ptr[pos].~T(); freeRawData(m_ptr);
 #ifndef NO_ASSERTS
m_size = 0;
 #endif
___2037 = false; } } } return ___2037; } inline bool alloc(uint64_t requestedSize, T const& padVal) { REQUIRE(empty()); bool ___2037; if (!empty()) { ___2037 = false; } else { ___2037 = allocRawData(m_ptr, requestedSize); if ( ___2037 ) {
 #ifndef NO_ASSERTS
m_size = requestedSize;
 #endif
uint64_t pos = 0; try { for ( pos = 0; pos < requestedSize; pos++ ) ::new(&m_ptr[pos]) T(padVal); } catch (...) { for ( uint64_t pos2 = 0; pos2 < pos; pos++ ) m_ptr[pos].~T(); freeRawData(m_ptr);
 #ifndef NO_ASSERTS
m_size = 0;
 #endif
___2037 = false; } } } return ___2037; } inline bool reallocate(uint64_t requestedSize) { bool ___2037 = true; if (empty()) { ___2037 = alloc(requestedSize); } else if (size() != requestedSize) { uint64_t const origSize = size(); T* newPtr = 0; ___2037 = allocRawData(newPtr, requestedSize); if ( ___2037 ) { uint64_t pos = 0; try { for (pos = 0; pos < requestedSize; ++pos) ::new(&newPtr[pos]) T; uint64_t const numItemsToSwap = std::min(origSize,requestedSize); for (pos = 0; pos < numItemsToSwap; ++pos) newPtr[pos].swap(m_ptr[pos]); for (pos = 0; pos < origSize; ++pos) m_ptr[pos].~T(); freeRawData(m_ptr); m_ptr = newPtr;
 #ifndef NO_ASSERTS
m_size = requestedSize;
 #endif
} catch (...) { for (uint64_t pos2 = 0; pos2 < pos; ++pos) newPtr[pos].~T(); freeRawData(newPtr); ___2037 = false; } } } return ___2037; } inline void ___935() { if ( m_ptr ) { uint64_t const ___2810 = size(); for ( uint64_t pos = 0; pos < ___2810; pos++ ) m_ptr[pos].~T(); freeRawData(m_ptr);
 #ifndef NO_ASSERTS
m_size = 0;
 #endif
} ENSURE(empty()); } inline T& operator[](uint64_t pos) { REQUIRE(pos<size()); return m_ptr[pos]; } inline T const& operator[](uint64_t pos) const { REQUIRE(pos<size()); return m_ptr[pos]; } inline T* data() { return m_ptr; } inline T const* data() const { return m_ptr; } typedef T* iterator; inline iterator begin() { return m_ptr; } inline iterator end(uint64_t knownSize) { REQUIRE(size() == knownSize); return m_ptr+knownSize; } typedef T const* const_iterator; inline const_iterator begin() const { return m_ptr; } inline const_iterator end(uint64_t knownSize) const { REQUIRE(size() == knownSize); return m_ptr+knownSize; } };
 #define LWV_SPECIALIZE_PLAIN_DATA_VECTORS
 #ifdef LWV_SPECIALIZE_PLAIN_DATA_VECTORS
template<typename T> class ___3092 { public: ___3092(___3092 const&) = delete; ___3092& operator=(___3092 const&) = delete; ___3092(___3092&& ___2886) : m_ptr(std::move(___2886.m_ptr))
 #if !defined NO_ASSERTS
, m_size(std::move(___2886.m_size))
 #endif
{ ___2886.m_ptr = nullptr;
 #if !defined NO_ASSERTS
___2886.m_size = 0;
 #endif
} ___3092& operator=(___3092&& ___3390) { if (this != &___3390) { ___935(); m_ptr = std::move(___3390.m_ptr); ___3390.m_ptr = nullptr;
 #if !defined NO_ASSERTS
m_size = std::move(___3390.m_size); ___3390.m_size = 0;
 #endif
} return *this; } void ___2317( char const* container, size_t numElements) {
 #ifdef LARGE_ARRAY_MEMORY_LOGGING
size_t const MEMTRACK_CUTOFF = size_t(1000)*size_t(1000); if (numElements * sizeof(T) >= MEMTRACK_CUTOFF) { FILE *file = fopen("memtrack.txt", "at"); if (file) { fprintf(file, "%s\t%" "I64u" "\t%" "I64u" "\t%s\n", container, numElements, sizeof(T), typeid(T).___2683()); fclose(file); } else throw std::bad_alloc(); }
 #else
___4276(container); ___4276(numElements);
 #endif
} private: T* m_ptr;
 #ifndef NO_ASSERTS
uint64_t m_size;
 #endif
public: ___3092() : m_ptr(NULL)
 #ifndef NO_ASSERTS
, m_size(0)
 #endif
{ } ~___3092() { ___935(); } inline void swap(___3092<T>& ___2886) { using std::swap; swap(m_ptr, ___2886.m_ptr);
 #ifndef NO_ASSERTS
swap(m_size, ___2886.m_size);
 #endif
} inline uint64_t numBytesAllocated(uint64_t knownSize) const { REQUIRE(knownSize==m_size); REQUIRE(EQUIVALENCE(empty(),knownSize==0)); if ( empty() ) return 0; else return knownSize*sizeof(T); } inline bool empty() const { REQUIRE(EQUIVALENCE(m_ptr==NULL,m_size==0)); return ( m_ptr == NULL ); }
 #ifndef NO_ASSERTS
inline uint64_t size() const { return m_size; }
 #endif
inline bool alloc(uint64_t requestedSize) { REQUIRE(empty()); bool ___2037 = true; if (!empty()) { ___2037 = false; } else if (requestedSize > 0) { uint64_t const totalBytesRequired = requestedSize*uint64_t(sizeof(T)); if ( sizeof(size_t) == 4 && totalBytesRequired > uint32_t(-1) ) { m_ptr = NULL; } else { ___2317("PlainDataVector", requestedSize); m_ptr = (T *)malloc( static_cast<size_t>(totalBytesRequired) ); } ___2037 = (m_ptr != NULL);
 #ifndef NO_ASSERTS
if ( ___2037 ) m_size = requestedSize;
 #endif
} else { ___476(___2037); ___476(m_size == 0); ___476(m_ptr == NULL); } ENSURE(EQUIVALENCE(___2037, (m_size == 0 && m_ptr == NULL) || (m_size > 0 && VALID_REF(m_ptr)))); return ___2037; } inline bool alloc(uint64_t requestedSize, T padVal) { REQUIRE(empty()); bool ___2037 = alloc(requestedSize); if ( ___2037 ) { try { for ( uint64_t pos = 0; pos < requestedSize; pos++ ) new(&m_ptr[pos]) T(padVal); } catch (...) { ___935(); ___2037 = false; } } return ___2037; } inline bool reallocate( uint64_t origSize, uint64_t requestedSize) { REQUIRE(origSize == size()); bool ___2037 = true; if (empty()) { ___2037 = alloc(requestedSize); } else if (origSize != requestedSize) { T* newPtr = 0; if (requestedSize > 0) { uint64_t const totalBytesRequired = requestedSize*uint64_t(sizeof(T)); if ( sizeof(size_t) == 4 && totalBytesRequired > uint32_t(-1) ) { newPtr = NULL; } else { ___2317("PlainDataVector", requestedSize); newPtr = (T *)malloc( static_cast<size_t>(totalBytesRequired) ); } ___2037 = (newPtr != NULL); if ( ___2037 ) { uint64_t const bytesToCopy = std::min(origSize,requestedSize)*uint64_t(sizeof(T)); uint8_t const* const sourceBytePtr = reinterpret_cast<uint8_t const*>(m_ptr); uint8_t* const targetBytePtr = reinterpret_cast<uint8_t*>(newPtr); std::copy(sourceBytePtr, sourceBytePtr+bytesToCopy, targetBytePtr); } } else { ___476(___2037); } if (___2037) { free(m_ptr); m_ptr = newPtr;
 #ifndef NO_ASSERTS
m_size = requestedSize;
 #endif
} } return ___2037; } inline void ___935() { if ( m_ptr ) { free(m_ptr); m_ptr = NULL;
 #ifndef NO_ASSERTS
m_size = 0;
 #endif
} ENSURE(empty()); } inline T& operator[](uint64_t pos) { REQUIRE(!empty() && pos < size()); return m_ptr[pos]; } inline T const& operator[](uint64_t pos) const { REQUIRE(!empty() && pos < size()); return m_ptr[pos]; } inline T* data() { return m_ptr; } inline T const* data() const { return m_ptr; } typedef T* iterator; inline iterator begin() { return m_ptr; } inline iterator end(uint64_t knownSize) { REQUIRE(knownSize == size()); return m_ptr+knownSize; } typedef T const* const_iterator; inline const_iterator begin() const { return m_ptr; } inline const_iterator end(uint64_t knownSize) const { REQUIRE(knownSize == size()); return m_ptr+knownSize; } }; template<> class ___2238<ItemAddress64> : public ___3092<ItemAddress64> {}; template<> class ___2238<ItemAddress64::SubzoneAddress> : public ___3092<ItemAddress64::SubzoneAddress> {}; template<> class ___2238<double> : public ___3092<double> {}; template<> class ___2238<float> : public ___3092<float> {}; template<> class ___2238<uint64_t> : public ___3092<uint64_t> {}; template<> class ___2238<int64_t> : public ___3092<int64_t> {}; template<> class ___2238<uint32_t> : public ___3092<uint32_t> {}; template<> class ___2238<int32_t> : public ___3092<int32_t> {}; template<> class ___2238<uint16_t> : public ___3092<uint16_t> {}; template<> class ___2238<int16_t> : public ___3092<int16_t> {}; template<> class ___2238<uint8_t> : public ___3092<uint8_t> {}; template<> class ___2238<int8_t> : public ___3092<int8_t> {}; template<typename T> class ___2238<T*> : public ___3092<T*> {}; template<> class ___2238<___2477> : public ___3092<___2477> {};
 #endif
template<typename T> inline bool ___3354(___2238<___2238<T> >& twoDLwVector, uint64_t newDim1, uint64_t newDim2) { REQUIRE(newDim1>0 && newDim2>0); bool ___2037 = false; try { twoDLwVector.alloc(newDim1); for ( uint64_t ___1839 = 0; ___1839 < newDim1; ___1839++ ) twoDLwVector[___1839].alloc(newDim2); ___2037 = true; } catch (...) { if ( !twoDLwVector.empty() ) { ___476(twoDLwVector.size() == newDim1); for ( uint64_t ___1839 = 0; ___1839 < newDim1; ___1839++ ) twoDLwVector[___1839].___935(); twoDLwVector.___935(); } ___2037 = false; } ENSURE(IMPLICATION(___2037, twoDLwVector.size()==newDim1)); ENSURE(IMPLICATION(___2037, twoDLwVector[0].size()==newDim2)); ENSURE(IMPLICATION(___2037, twoDLwVector[newDim1/2].size()==newDim2)); ENSURE(IMPLICATION(___2037, twoDLwVector[newDim1-1].size()==newDim2)); return ___2037; } template<typename T> inline bool ___3354(___2238<___2238<T> >& twoDLwVector, uint64_t newDim1, uint64_t newDim2, T padValue) { REQUIRE(newDim1>0 && newDim2>0); bool ___2037 = false; try { twoDLwVector.alloc(newDim1); for ( uint64_t ___1839 = 0; ___1839 < newDim1; ___1839++ ) twoDLwVector[___1839].alloc(newDim2, padValue); ___2037 = true; } catch (...) { if ( !twoDLwVector.empty() ) { ___476(twoDLwVector.size() == newDim1); for ( uint64_t ___1839 = 0; ___1839 < newDim1; ___1839++ ) twoDLwVector[___1839].___935(); twoDLwVector.___935(); } ___2037 = false; } ENSURE(IMPLICATION(___2037, twoDLwVector.size()==newDim1)); ENSURE(IMPLICATION(___2037, twoDLwVector[0].size()==newDim2)); ENSURE(IMPLICATION(___2037, twoDLwVector[newDim1/2].size()==newDim2)); ENSURE(IMPLICATION(___2037, twoDLwVector[newDim1-1].size()==newDim2)); return ___2037; } }}
