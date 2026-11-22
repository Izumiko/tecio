 #pragma once
#include "ThirdPartyHeadersBegin.h"
#include <string>
#include "ThirdPartyHeadersEnd.h"
#include "basicTypes.h"
namespace tecplot { namespace ___3934 { class ___37; class FileWriterInterface; class ___1350; class ItemSetIterator; class NonSzZoneVariableWriter { public: NonSzZoneVariableWriter(ItemSetIterator& varIter, ___4636 zone, ___4636 ___341, ___37& ___36); static uint64_t varHeaderSizeInFile(bool ___2001); uint64_t varSizeInFile(___4352 ___4336, bool ___2001) const; ___372 writeVarHeader(FileWriterInterface& file, ValueLocation_e ___4326, ___4352 ___4336); ___372 writeVar(FileWriterInterface& szpltFile, ___1350 const& ___1349); private: ItemSetIterator&  m_varIter; ___4636 const ___2678; ___4636 const m_baseZone; ___37&       ___2338; std::string const m_zoneNumberLabel; }; }}
