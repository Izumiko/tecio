 #pragma once
#include "ThirdPartyHeadersBegin.h"
#include <vector>
#include "ThirdPartyHeadersEnd.h"
#include "basicTypes.h"
namespace tecplot { namespace ___3934 { class FaceNeighborGeneratorAbstract; class NonSzZoneFaceNeighborWriter { public: NonSzZoneFaceNeighborWriter(FaceNeighborGeneratorAbstract& faceNeighborGenerator, ___4636 zone, ___4636 ___341); ___372 write(class FileWriterInterface& file); uint64_t  sizeInFile(bool ___2001); private: FaceNeighborGeneratorAbstract const& m_faceNeighborGenerator; ___4636 const                    ___2678; ___4636 const                    m_baseZone; std::string const                    m_zoneNumberLabel; std::vector<int32_t>                 m_userFaceNeighbors; }; }}
