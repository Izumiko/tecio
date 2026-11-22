 #ifndef TECPLOT_SYSTEM_H
 #define TECPLOT_SYSTEM_H
 #if defined EXTERN
 #undef EXTERN
 #endif
 #if defined ___3922
 #define EXTERN
 #else
 #define EXTERN extern
 #endif
 #if defined ALLOW_INTERRUPTS_DURING_SLOW_READS_WRITES
 #define MAX_BYTES_PER_CHUNK 4096L 
 #else
 #define MAX_BYTES_PER_CHUNK 131072L 
 #endif
 #if defined TECPLOTKERNEL
size_t ___485( void const* ___3645, size_t      ___2100, size_t      ___2814, FILE*       ___3949, size_t      maxBytesPerChunk = MAX_BYTES_PER_CHUNK);
 #endif
EXTERN ___372 ___4406(const char* ___1437); EXTERN ___372 ___2068(const char* ___1437); EXTERN ___372 ___1387(const char* F, ___372 ___3571); EXTERN void      ___1174(const char* ___1437); EXTERN ___372 ___2069(const char* ___1393, ___372 ___2053, ___372 ___3573); EXTERN ___372 ___3358(FILE* File, int64_t ___2223); EXTERN ___372 ___503(FILE** F, ___372 ___3571); EXTERN ___372 ___2878( FILE**      F, const char* ___1437, ___372   ___2053, ___372   ___2000, ___372   ___1471, ___372   ___3571, ___372   ___2002);
 #endif
