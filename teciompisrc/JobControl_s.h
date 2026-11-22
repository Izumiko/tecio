 #pragma once
#include "ThirdPartyHeadersBegin.h"
 #if defined _WIN32
#include <windows.h>
 #else
#include <thread>
 #if defined __APPLE__
#include <sys/sysctl.h>
#include <sys/types.h>
 #endif
 #endif
#include <utility>
#include "ThirdPartyHeadersEnd.h"
#include "MASTER.h"
#include "GLOBAL.h"
#include "Mutex_s.h"
 #if defined _WIN32
typedef PTP_WORK thread_t;
 #else
typedef std::thread thread_t;
 #endif
struct ___2121 { ___2665              ___2495; std::vector<thread_t> ___2649; static int ___2828(); ___2121() { ___2495 = new ___2666(); } ~___2121() { delete ___2495; } struct ThreadJobData { ___4161 m_job; ___90       m_jobData; ThreadJobData(___4161 ___2117, ___90 ___2122) : m_job(___2117) , m_jobData(___2122) {} };
 #if defined _WIN32
static VOID CALLBACK ___4163(PTP_CALLBACK_INSTANCE Instance, PVOID Context, PTP_WORK Work);
 #else
static void* ___4163(void* data);
 #endif
void addJob(___4161 ___2117, ___90 ___2122); void wait(); void lock() { ___2495->lock(); } void unlock() { ___2495->unlock(); } }; inline int ___2121::___2828() { int ___2829 = 0;
 #if defined _WIN32
SYSTEM_INFO sysinfo; GetSystemInfo(&sysinfo); ___2829 = static_cast<int>(sysinfo.dwNumberOfProcessors);
 #elif defined __APPLE__
int      nm[2]; size_t   len = 4; uint32_t count; nm[0] = CTL_HW; nm[1] = HW_AVAILCPU; sysctl(nm, 2, &count, &len, NULL, 0); if (count < 1) { nm[1] = HW_NCPU; sysctl(nm, 2, &count, &len, NULL, 0); if (count < 1) count = 1; } ___2829 = static_cast<int>(count);
 #else
___2829 = static_cast<int>(sysconf(_SC_NPROCESSORS_ONLN));
 #endif
return ___2829; }
 #if defined _WIN32
inline VOID CALLBACK ___2121::___4163(PTP_CALLBACK_INSTANCE, PVOID data, PTP_WORK)
 #else
inline void* ___2121::___4163(void* data)
 #endif
{ ThreadJobData* ___2122 = reinterpret_cast<ThreadJobData*>(data); ___2122->m_job(___2122->m_jobData); delete ___2122;
 #if !defined _WIN32
return NULL;
 #endif
} inline void ___2121::addJob(___4161 ___2117, ___90 ___2122) { lock(); ___2121::ThreadJobData* threadJobData = new ThreadJobData(___2117, ___2122);
 #if defined _WIN32
thread_t thr = CreateThreadpoolWork(___4163, threadJobData, NULL); SubmitThreadpoolWork(thr); ___2649.push_back(thr);
 #else
___2649.emplace_back(___4163, (void*)threadJobData);
 #endif
unlock(); } inline void ___2121::wait() { size_t i; for (i = 0; i < ___2649.size(); ++i) { lock(); thread_t thr; std::swap(thr, ___2649[i]); unlock();
 #if defined _WIN32
WaitForThreadpoolWorkCallbacks(thr, ___1303); CloseThreadpoolWork(thr);
 #else
thr.join();
 #endif
} lock(); ___2649.erase(___2649.begin(), ___2649.begin() + i); unlock(); }
