 #pragma once
#include "ThirdPartyHeadersBegin.h"
#include <algorithm>
#include <new>
#include "ThirdPartyHeadersEnd.h"
#include "MASTER.h"
#include "GLOBAL.h"
#include "ClassMacros.h"
#include "CodeContract.h"
#include "ItemAddress.h"
#include "MinMax.h"
inline uint64_t numBytesForNumBits(uint64_t numBits) { return (numBits + 7) / 8; } namespace { template <typename T> uint64_t const* getRealMemPtr(T* const& ___3252) { REQUIRE(VALID_REF(___3252)); uint64_t const* uint64Array = (uint64_t const*)___3252; return uint64Array - 1; } } namespace { template <typename T> uint64_t* getRealMemPtr(T*& ___3252) { REQUIRE(VALID_REF(___3252)); uint64_t* uint64Array = (uint64_t*)___3252; return uint64Array - 1; } } namespace tecplot { namespace ___3934 { template <typename T> class ___2241 { public: ___2241(___2241 const&)            = delete; ___2241& operator=(___2241 const&) = delete; ___2241(___2241&& ___2889) : m_ptr(std::move(___2889.m_ptr))
 #if !defined NO_ASSERTS
, m_size(std::move(___2889.m_size))
 #endif
{ ___2889.m_ptr = nullptr;
 #if !defined NO_ASSERTS
___2889.m_size = 0;
 #endif
} ___2241& operator=(___2241&& ___3393) { if (this != &___3393) { ___935(); m_ptr     = std::move(___3393.m_ptr); ___3393.m_ptr = nullptr;
 #if !defined NO_ASSERTS
m_size     = std::move(___3393.m_size); ___3393.m_size = 0;
 #endif
} return *this; } void ___2320(char const* container, size_t numElements) {
 #ifdef LARGE_ARRAY_MEMORY_LOGGING
size_t const MEMTRACK_CUTOFF = size_t(1000) * size_t(1000); if (numElements * sizeof(T) >= MEMTRACK_CUTOFF) { FILE* file = fopen("memtrack.txt", "at"); if (file) { fprintf( file, "%s\t%" "I64u" "\t%" "I64u" "\t%s\n", container, numElements, sizeof(T), typeid(T).___2686()); fclose(file); } else throw std::bad_alloc(); }
 #else
___4279(container); ___4279(numElements);
 #endif
} private: T* m_ptr;
 #ifndef NO_ASSERTS
uint64_t m_size;
 #endif
inline bool allocRawData(T*& ___3252, uint64_t requestedSize) { REQUIRE(___3252 == NULL); bool ___2038 = true; if (requestedSize > 0) { uint64_t const totalBytesRequired = sizeof(uint64_t) + requestedSize * uint64_t(sizeof(T)); uint64_t*      mem                = NULL; if (sizeof(size_t) == 4 && totalBytesRequired > uint32_t(-1)) { mem = NULL; } else { ___2320("LightweightVector", requestedSize); mem = (uint64_t*)malloc(static_cast<size_t>(totalBytesRequired)); } ___2038 = (mem != NULL); if (___2038) { mem[0] = requestedSize; ___3252    = (T*)&mem[1]; ___2038   = true; } } else { ___476(___2038); ___3252 = NULL; } return ___2038; } inline void freeRawData(T*& ___3252) { REQUIRE(VALID_REF_OR_NULL(___3252)); if (___3252 != NULL) { free(getRealMemPtr(___3252)); ___3252 = NULL; } } public: ___2241() : m_ptr(NULL)
 #ifndef NO_ASSERTS
, m_size(0)
 #endif
{} ~___2241() { ___935(); } inline void swap(___2241<T>& ___2889) { using std::swap; swap(m_ptr, ___2889.m_ptr);
 #ifndef NO_ASSERTS
swap(m_size, ___2889.m_size);
 #endif
} inline uint64_t size() const { uint64_t ___3359; if (empty()) ___3359 = 0; else ___3359 = getRealMemPtr(m_ptr)[0]; ENSURE(___3359 == m_size); return ___3359; } inline uint64_t numBytesAllocated(uint64_t knownSize) const { REQUIRE(IMPLICATION(empty(), knownSize == 0)); REQUIRE(IMPLICATION(!empty(), knownSize == size())); if (empty()) return 0; else return sizeof(uint64_t) + knownSize * uint64_t(sizeof(T)); } inline bool empty() const { INVARIANT(EQUIVALENCE(m_ptr == NULL, m_size == 0)); return (m_ptr == NULL); } inline bool alloc(uint64_t requestedSize) { REQUIRE(empty()); bool ___2038; if (!empty()) { ___2038 = false; } else { ___2038 = allocRawData(m_ptr, requestedSize); if (___2038) {
 #ifndef NO_ASSERTS
m_size = requestedSize;
 #endif
uint64_t pos = 0; try { for (pos = 0; pos < requestedSize; pos++) ::new (&m_ptr[pos]) T; } catch (...) { for (uint64_t pos2 = 0; pos2 < pos; pos++) m_ptr[pos].~T(); freeRawData(m_ptr);
 #ifndef NO_ASSERTS
m_size = 0;
 #endif
___2038 = false; } } } return ___2038; } inline bool alloc(uint64_t requestedSize, T const& padVal) { REQUIRE(empty()); bool ___2038; if (!empty()) { ___2038 = false; } else { ___2038 = allocRawData(m_ptr, requestedSize); if (___2038) {
 #ifndef NO_ASSERTS
m_size = requestedSize;
 #endif
uint64_t pos = 0; try { for (pos = 0; pos < requestedSize; pos++) ::new (&m_ptr[pos]) T(padVal); } catch (...) { for (uint64_t pos2 = 0; pos2 < pos; pos++) m_ptr[pos].~T(); freeRawData(m_ptr);
 #ifndef NO_ASSERTS
m_size = 0;
 #endif
___2038 = false; } } } return ___2038; } inline bool reallocate(uint64_t requestedSize) { bool ___2038 = true; if (empty()) { ___2038 = alloc(requestedSize); } else if (size() != requestedSize) { uint64_t const origSize = size(); T*             newPtr   = 0; ___2038                    = allocRawData(newPtr, requestedSize); if (___2038) { uint64_t pos = 0; try { for (pos = 0; pos < requestedSize; ++pos) ::new (&newPtr[pos]) T; uint64_t const numItemsToSwap = std::min(origSize, requestedSize); for (pos = 0; pos < numItemsToSwap; ++pos) newPtr[pos].swap(m_ptr[pos]); for (pos = 0; pos < origSize; ++pos) m_ptr[pos].~T(); freeRawData(m_ptr); m_ptr = newPtr;
 #ifndef NO_ASSERTS
m_size = requestedSize;
 #endif
} catch (...) { for (uint64_t pos2 = 0; pos2 < pos; ++pos) newPtr[pos].~T(); freeRawData(newPtr); ___2038 = false; } } } return ___2038; } inline void ___935() { if (m_ptr) { uint64_t const ___2813 = size(); for (uint64_t pos = 0; pos < ___2813; pos++) m_ptr[pos].~T(); freeRawData(m_ptr);
 #ifndef NO_ASSERTS
m_size = 0;
 #endif
} ENSURE(empty()); } inline T& operator[](uint64_t pos) { REQUIRE(pos < size()); return m_ptr[pos]; } inline T const& operator[](uint64_t pos) const { REQUIRE(pos < size()); return m_ptr[pos]; } inline T* data() { return m_ptr; } inline T const* data() const { return m_ptr; } typedef T* iterator; inline iterator begin() { return m_ptr; } inline iterator end(uint64_t knownSize) { REQUIRE(size() == knownSize); return m_ptr + knownSize; } typedef T const* const_iterator; inline const_iterator begin() const { return m_ptr; } inline const_iterator end(uint64_t knownSize) const { REQUIRE(size() == knownSize); return m_ptr + knownSize; } };
 #define LWV_SPECIALIZE_PLAIN_DATA_VECTORS
 #ifdef LWV_SPECIALIZE_PLAIN_DATA_VECTORS
template <typename T> class ___3095 { public: ___3095(___3095 const&)            = delete; ___3095& operator=(___3095 const&) = delete; ___3095(___3095&& ___2889) : m_ptr(std::move(___2889.m_ptr))
 #if !defined NO_ASSERTS
, m_size(std::move(___2889.m_size))
 #endif
{ ___2889.m_ptr = nullptr;
 #if !defined NO_ASSERTS
___2889.m_size = 0;
 #endif
} ___3095& operator=(___3095&& ___3393) { if (this != &___3393) { ___935(); m_ptr     = std::move(___3393.m_ptr); ___3393.m_ptr = nullptr;
 #if !defined NO_ASSERTS
m_size     = std::move(___3393.m_size); ___3393.m_size = 0;
 #endif
} return *this; } void ___2320(char const* container, size_t numElements) {
 #ifdef LARGE_ARRAY_MEMORY_LOGGING
size_t const MEMTRACK_CUTOFF = size_t(1000) * size_t(1000); if (numElements * sizeof(T) >= MEMTRACK_CUTOFF) { FILE* file = fopen("memtrack.txt", "at"); if (file) { fprintf( file, "%s\t%" "I64u" "\t%" "I64u" "\t%s\n", container, numElements, sizeof(T), typeid(T).___2686()); fclose(file); } else throw std::bad_alloc(); }
 #else
___4279(container); ___4279(numElements);
 #endif
} private: T* m_ptr;
 #ifndef NO_ASSERTS
uint64_t m_size;
 #endif
public: ___3095() : m_ptr(NULL)
 #ifndef NO_ASSERTS
, m_size(0)
 #endif
{} ~___3095() { ___935(); } inline void swap(___3095<T>& ___2889) { using std::swap; swap(m_ptr, ___2889.m_ptr);
 #ifndef NO_ASSERTS
swap(m_size, ___2889.m_size);
 #endif
} inline uint64_t numBytesAllocated(uint64_t knownSize) const { REQUIRE(knownSize == m_size); REQUIRE(EQUIVALENCE(empty(), knownSize == 0)); if (empty()) return 0; else return knownSize * sizeof(T); } inline bool empty() const { REQUIRE(EQUIVALENCE(m_ptr == NULL, m_size == 0)); return (m_ptr == NULL); }
 #ifndef NO_ASSERTS
inline uint64_t size() const { return m_size; }
 #endif
inline bool alloc(uint64_t requestedSize) { REQUIRE(empty()); bool ___2038 = true; if (!empty()) { ___2038 = false; } else if (requestedSize > 0) { uint64_t const totalBytesRequired = requestedSize * uint64_t(sizeof(T)); if (sizeof(size_t) == 4 && totalBytesRequired > uint32_t(-1)) { m_ptr = NULL; } else { ___2320("PlainDataVector", requestedSize); m_ptr = (T*)malloc(static_cast<size_t>(totalBytesRequired)); } ___2038 = (m_ptr != NULL);
 #ifndef NO_ASSERTS
if (___2038) m_size = requestedSize;
 #endif
} else { ___476(___2038); ___476(m_size == 0); ___476(m_ptr == NULL); } ENSURE(EQUIVALENCE(___2038, (m_size == 0 && m_ptr == NULL) || (m_size > 0 && VALID_REF(m_ptr)))); return ___2038; } inline bool alloc(uint64_t requestedSize, T padVal) { REQUIRE(empty()); bool ___2038 = alloc(requestedSize); if (___2038) { try { for (uint64_t pos = 0; pos < requestedSize; pos++) new (&m_ptr[pos]) T(padVal); } catch (...) { ___935(); ___2038 = false; } } return ___2038; } inline bool reallocate(uint64_t origSize, uint64_t requestedSize) { REQUIRE(origSize == size()); bool ___2038 = true; if (empty()) { ___2038 = alloc(requestedSize); } else if (origSize != requestedSize) { T* newPtr = 0; if (requestedSize > 0) { uint64_t const totalBytesRequired = requestedSize * uint64_t(sizeof(T)); if (sizeof(size_t) == 4 && totalBytesRequired > uint32_t(-1)) { newPtr = NULL; } else { ___2320("PlainDataVector", requestedSize); newPtr = (T*)malloc(static_cast<size_t>(totalBytesRequired)); } ___2038 = (newPtr != NULL); if (___2038) { uint64_t const       bytesToCopy   = std::min(origSize, requestedSize) * uint64_t(sizeof(T)); uint8_t const* const sourceBytePtr = reinterpret_cast<uint8_t const*>(m_ptr); uint8_t* const       targetBytePtr = reinterpret_cast<uint8_t*>(newPtr); std::copy(sourceBytePtr, sourceBytePtr + bytesToCopy, targetBytePtr); } } else { ___476(___2038); } if (___2038) { free(m_ptr); m_ptr = newPtr;
 #ifndef NO_ASSERTS
m_size = requestedSize;
 #endif
} } return ___2038; } inline void ___935() { if (m_ptr) { free(m_ptr); m_ptr = NULL;
 #ifndef NO_ASSERTS
m_size = 0;
 #endif
} ENSURE(empty()); } inline T& operator[](uint64_t pos) { REQUIRE(!empty() && pos < size()); return m_ptr[pos]; } inline T const& operator[](uint64_t pos) const { REQUIRE(!empty() && pos < size()); return m_ptr[pos]; } inline T* data() { return m_ptr; } inline T const* data() const { return m_ptr; } typedef T* iterator; inline iterator begin() { return m_ptr; } inline iterator end(uint64_t knownSize) { REQUIRE(knownSize == size()); return m_ptr + knownSize; } typedef T const* const_iterator; inline const_iterator begin() const { return m_ptr; } inline const_iterator end(uint64_t knownSize) const { REQUIRE(knownSize == size()); return m_ptr + knownSize; } }; template <> class ___2241<ItemAddress64> : public ___3095<ItemAddress64> {}; template <> class ___2241<ItemAddress64::SubzoneAddress> : public ___3095<ItemAddress64::SubzoneAddress> {}; template <> class ___2241<double> : public ___3095<double> {}; template <> class ___2241<float> : public ___3095<float> {}; template <> class ___2241<uint64_t> : public ___3095<uint64_t> {}; template <> class ___2241<int64_t> : public ___3095<int64_t> {}; template <> class ___2241<uint32_t> : public ___3095<uint32_t> {}; template <> class ___2241<int32_t> : public ___3095<int32_t> {}; template <> class ___2241<uint16_t> : public ___3095<uint16_t> {}; template <> class ___2241<int16_t> : public ___3095<int16_t> {}; template <> class ___2241<uint8_t> : public ___3095<uint8_t> {}; template <> class ___2241<int8_t> : public ___3095<int8_t> {}; template <typename T> class ___2241<T*> : public ___3095<T*> {}; template <> class ___2241<___2480> : public ___3095<___2480> {};
 #endif
template <typename T> inline bool ___3357(___2241<___2241<T>>& twoDLwVector, uint64_t newDim1, uint64_t newDim2) { REQUIRE(newDim1 > 0 && newDim2 > 0); bool ___2038 = false; try { twoDLwVector.alloc(newDim1); for (uint64_t ___1840 = 0; ___1840 < newDim1; ___1840++) twoDLwVector[___1840].alloc(newDim2); ___2038 = true; } catch (...) { if (!twoDLwVector.empty()) { ___476(twoDLwVector.size() == newDim1); for (uint64_t ___1840 = 0; ___1840 < newDim1; ___1840++) twoDLwVector[___1840].___935(); twoDLwVector.___935(); } ___2038 = false; } ENSURE(IMPLICATION(___2038, twoDLwVector.size() == newDim1)); ENSURE(IMPLICATION(___2038, twoDLwVector[0].size() == newDim2)); ENSURE(IMPLICATION(___2038, twoDLwVector[newDim1 / 2].size() == newDim2)); ENSURE(IMPLICATION(___2038, twoDLwVector[newDim1 - 1].size() == newDim2)); return ___2038; } template <typename T> inline bool ___3357( ___2241<___2241<T>>& twoDLwVector, uint64_t newDim1, uint64_t newDim2, T padValue) { REQUIRE(newDim1 > 0 && newDim2 > 0); bool ___2038 = false; try { twoDLwVector.alloc(newDim1); for (uint64_t ___1840 = 0; ___1840 < newDim1; ___1840++) twoDLwVector[___1840].alloc(newDim2, padValue); ___2038 = true; } catch (...) { if (!twoDLwVector.empty()) { ___476(twoDLwVector.size() == newDim1); for (uint64_t ___1840 = 0; ___1840 < newDim1; ___1840++) twoDLwVector[___1840].___935(); twoDLwVector.___935(); } ___2038 = false; } ENSURE(IMPLICATION(___2038, twoDLwVector.size() == newDim1)); ENSURE(IMPLICATION(___2038, twoDLwVector[0].size() == newDim2)); ENSURE(IMPLICATION(___2038, twoDLwVector[newDim1 / 2].size() == newDim2)); ENSURE(IMPLICATION(___2038, twoDLwVector[newDim1 - 1].size() == newDim2)); return ___2038; } }}
