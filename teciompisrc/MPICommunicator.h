 #pragma once
#include "ThirdPartyHeadersBegin.h"
#include <mpi.h>
#include "ThirdPartyHeadersEnd.h"
#include "SimpleVector.h"
#include "MPIError.h"
namespace tecplot { namespace teciompi { class MPICommunicator { public: explicit MPICommunicator(MPI_Comm communicator); template <typename T> void sendScalar(T ___4299, int dest, int tag); template <typename T> void receiveScalar(T& ___4299, int ___3657, int tag); template <typename T> void sendVector(SimpleVector<T> const& vec, int dest, int sizeTag, int vecTag); template <typename T> void receiveVector(SimpleVector<T>& vec, int ___3657, int sizeTag, int vecTag); private: MPI_Comm m_communicator; }; }}
