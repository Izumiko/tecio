 #pragma once
#include "SzlFileLoader.h"
#include "ZoneHeaderWriterAbstract.h"
namespace tecplot { namespace ___3934 { class ___37; class ___1880; class ItemSetIterator; class SZLOrderedZoneHeaderWriter : public ZoneHeaderWriterAbstract { public: SZLOrderedZoneHeaderWriter( uint32_t            fileVersion, ItemSetIterator&    varIter, ___4636         zone, ___4636         ___341, ___37&         ___36, ___1880 const&  ijkZoneInfo, ___1390 const& varFileLocs); virtual ~SZLOrderedZoneHeaderWriter(); virtual uint64_t  sizeInFile(bool ___2001) const; virtual ___372 write(FileWriterInterface& fileWriter) const; private: ___1880 const&  m_ijkZoneInfo; ___1390 const& ___2674; }; }}
