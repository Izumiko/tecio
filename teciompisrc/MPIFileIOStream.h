 #pragma once
#include "ThirdPartyHeadersBegin.h"
#include <mpi.h>
#include <boost/scoped_ptr.hpp>
#include "ThirdPartyHeadersEnd.h"
#include "MASTER.h"
#include "GLOBAL.h"
#include "basicTypes.h"
#include "ClassMacros.h"
#include "FileIOStreamInterface.h"
namespace tecplot { namespace ___3934 { class FileIOStatistics; }} namespace tecplot { namespace teciompi { class MPIFileIOStream : public ___3934::FileIOStreamInterface { public: MPIFileIOStream(std::string const& ___1392, MPI_Comm comm, MPI_Info info = MPI_INFO_NULL); virtual ~MPIFileIOStream(); virtual ___372                ___2040() const; virtual ___372                close(bool ___3362); virtual ___3934::___1391         fileLoc(); virtual ___372                ___3461(); virtual ___372                ___3460(___3934::___1391 fileLoc); virtual ___372                seekToFileEnd(); virtual std::string const&       ___1392() const; virtual void                     ___3495(___372 ___2001); virtual ___372                ___2001() const; virtual void                     setDataFileType(DataFileType_e ___842); virtual DataFileType_e           ___842() const; virtual ___3934::FileIOStatistics& statistics(); ___372 open(int ___2505); MPI_File  fileHandle() const; MPI_Comm  comm() const; private: struct Impl; boost::scoped_ptr<Impl> m_impl; UNCOPYABLE_CLASS(MPIFileIOStream); }; }}
