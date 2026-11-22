 #ifndef ALLOC_H
 #define ALLOC_H
 #if defined __cplusplus
#include <new>
 #if defined TRACK_MEMORY_USAGE
#include <malloc.h>
 #endif
 #endif
#include "CodeContract.h"
 #if !defined __cplusplus
 #define ___23(N, ___4237, str) (___4237*)malloc((N) * sizeof(___4237))
 #define ALLOC_ITEM(___4237, str)     (___4237*)malloc(sizeof(___4237))
 #ifdef _DEBUG
 #define ___1528(X, str)                                                                                             \
 do                                                                                                                 \
 {                                                                                                                  \
 free((void*)(X));                                                                                              \
 *((void**)&(X)) = (void*)0xFFFF;                                                                               \
 } while (0)
 #define ___1529(X, str)                                                                                              \
 do                                                                                                                 \
 {                                                                                                                  \
 free((void*)(X));                                                                                              \
 *((void**)&(X)) = (void*)0xFFFF;                                                                               \
 } while (0)
 #else
 #define ___1528(X, str) free((void*)(X))
 #define ___1529(X, str)  free((void*)(X))
 #endif
 #else
 #ifdef TRACK_MEMORY_USAGE
void printMemoryUsage(char const* context, size_t sizeChange); void ___1935(); void ___489(); void ___4208(size_t size); void ___4210(size_t size); void ___4209(); void ___4211(); void ___1757( size_t* ___2408, size_t* ___2407, size_t* ___2409, size_t* ___2410);
 #endif
 #if defined MSWIN && defined _DEBUG && defined TRACK_MEMORY_USAGE
template <typename T> inline T* nonExceptionNew(size_t ___2813, const char* ___1392, int lineNumber) { REQUIRE(___2813 > 0); REQUIRE(VALID_REF(___1392)); REQUIRE(lineNumber > 0); T* ___3359 = NULL; try {
 #ifdef DEBUG_NEW
 #ifdef new
 #undef new
 #define USING_DEBUG_NEW
 #endif
___3359 = new (___1392, lineNumber) T[___2813];
 #ifdef USING_DEBUG_NEW
 #undef USING_DEBUG_NEW
 #endif
 #else
___3359 = new T[___2813];
 #endif
} catch (std::bad_alloc&) { ___3359 = NULL; }
 #ifdef TRACK_MEMORY_USAGE
if (___3359 != NULL) {
 #ifdef MSWIN
___4208(_msize(___3359));
 #else
___4208(malloc_usable_size(___3359));
 #endif
}
 #endif
ENSURE(VALID_REF_OR_NULL(___3359)); return ___3359; }
 #define ___23(N, ___4237, str) nonExceptionNew<___4237>((N), __FILE__, __LINE__)
 #else
template <typename T> inline T* nonExceptionNew(size_t ___2813) { REQUIRE(___2813 > 0); T* ___3359 = NULL; try { ___3359 = new T[___2813]; } catch (std::bad_alloc&) { ___3359 = NULL; }
 #ifdef TRACK_MEMORY_USAGE
if (___3359 != NULL) {
 #ifdef MSWIN
___4208(_msize(___3359));
 #else
___4208(malloc_usable_size((void*)___3359));
 #endif
}
 #endif
return ___3359; }
 #define ___23(N, ___4237, str) nonExceptionNew<___4237>((N))
 #endif
 #define ALLOC_ITEM(___4237, str) ___23(1, ___4237, str)
template <typename T> inline void nonExceptionDelete(T*& ___3252) { REQUIRE(VALID_REF(___3252));
 #if defined TRACK_MEMORY_USAGE
{ if (___3252 != NULL) {
 #ifdef MSWIN
___4210(_msize(___3252));
 #else
___4210(malloc_usable_size((void*)___3252));
 #endif
} }
 #endif
delete[] ___3252;
 #if !defined NO_ASSERTS
___3252 = (T*)(void*)0xFFFF;
 #endif
} template <typename T> inline void nonExceptionDelete(T* const& ___3252) { nonExceptionDelete(const_cast<T*&>(___3252)); }
 #define ___1528(___3252, str) nonExceptionDelete((___3252))
 #define ___1529(___3252, str)  ___1528(___3252, str)
 #endif
struct ___954 { template <typename T> void operator()(T*& object) { delete object; object = NULL; } };
 #endif 
