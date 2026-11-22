 #pragma once
#include "MASTER.h"
#include "GLOBAL.h"
#include "FileReaderInterface.h"
#include "LightweightVector.h"
#include "ioDescription.h"
 #define STRING_SIZE   100
 #define STRING_FORMAT "%99s"
namespace tecplot { namespace ___3934 { template <typename T, bool ___2024, int baseValue> ___372 readValues(___1397& file, size_t ___2797, T* ___4300, IODescription const& ___970); template <typename T, bool ___2024, int base> ___372 readValueArray( ___1397&  file, size_t                ___2866, size_t                ___2796, ___2241<T>& ___4300, IODescription const&  ___970); template <typename T> ___372 readMinMaxArray( ___1397& file, size_t ___2866, size_t ___2796, ___2482& ___2481, IODescription const& ___970); template <typename T, bool ___2024> ___372 readValue(___1397& file, T& ___4299, IODescription const& ___970); template <typename T, bool ___2024> ___372 readAndVerifyValue(___1397& file, T const expectedVal, IODescription const& ___970); ___372 readString(___1397& file, size_t length, ___471& ___4299, IODescription const& ___970); ___372 readStringArray( ___1397& file, size_t ___2866, size_t ___2813, ___3817& itemNameArray, IODescription const& ___970); }}
