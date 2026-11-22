 #pragma once
#include "ThirdPartyHeadersBegin.h"
 #if defined _WIN32
#include <windows.h>
 #else
#include <mutex>
#include <thread>
 #if defined __APPLE__
#include <sys/sysctl.h>
#include <sys/types.h>
 #endif
 #endif
#include "ThirdPartyHeadersEnd.h"
#include "MASTER.h"
#include "GLOBAL.h"
struct ___2666 {
 #if defined _WIN32
HANDLE ___2495;
 #else
std::mutex ___2495;
 #endif
___2666() {
 #if defined _WIN32
___2495 = CreateMutex(NULL, ___1303, NULL);
 #endif
} ~___2666() {
 #if defined _WIN32
CloseHandle(___2495);
 #endif
} void lock() {
 #if defined _WIN32
WaitForSingleObject(___2495, INFINITE);
 #else
___2495.lock();
 #endif
} void unlock() {
 #if defined _WIN32
ReleaseMutex(___2495);
 #else
___2495.unlock();
 #endif
} };
