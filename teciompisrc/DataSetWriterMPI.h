#include "ThirdPartyHeadersBegin.h"
#include <mpi.h>
#include <vector>
#include "ThirdPartyHeadersEnd.h"
#include "DataSetWriter.h"
namespace tecplot { namespace ___3934 { class ___37; class FileWriterInterface; class ___1843; }} namespace tecplot { namespace teciompi { class DataSetWriterMPI : public ___3934::DataSetWriter { public: DataSetWriterMPI( ___3934::___37*          ___36, ___3502                      vars, ___3502                      ___4671, ___3934::___1843 const&           maxIJKSubzoneSize, ItemAddress64::ItemOffset_t maxFESubzoneSize, MPI_Comm                    communicator, int                         mainProcess, int                         localProcess, bool                        flushToDisk = false); virtual ~DataSetWriterMPI(); virtual ___372 writeDataSet( tecplot::___3934::FileWriterInterface& szpltFile, uint32_t                             fileVersion, tecplot::___3934::___1390&        szpltZoneHeaderFileLocs); private: MPI_Comm m_communicator; int      m_mainProcess; int      m_localProcess; }; }}
