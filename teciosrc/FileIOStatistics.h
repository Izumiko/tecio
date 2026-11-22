 #pragma once
#include "StandardIntegralTypes.h"
namespace tecplot { namespace ___3934 { class FileIOStatistics { public: FileIOStatistics() : numFSeeksPerformed(0) , numReadWritesPerformed(0) , ___2781(0) , numCszConnectivityProcessed(0) , numNszConnectivityProcessed(0) , numCszVarBlocksProcessed(0) , numNszVarBlocksProcessed(0) {} uint64_t numFSeeksPerformed; uint64_t numReadWritesPerformed; uint64_t ___2781; uint64_t numCszConnectivityProcessed; uint64_t numNszConnectivityProcessed; uint64_t numCszVarBlocksProcessed; uint64_t numNszVarBlocksProcessed; }; }}
