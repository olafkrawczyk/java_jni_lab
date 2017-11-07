#pragma comment(lib, "psapi.lib") // Added to support GetProcessMemoryInfo()

#include "com_pwrlab_memomonitor_MonitorJNI.h"

#include <Windows.h>
#include <Psapi.h>

_PERFORMANCE_INFORMATION perf_info;
_SYSTEM_INFO system_info;


JNIEXPORT jint JNICALL Java_com_pwrlab_memomonitor_MonitorJNI_getTotalRamMBNative(JNIEnv *, jclass) {

	perf_info.cb = sizeof(perf_info);
	GetPerformanceInfo(&perf_info, perf_info.cb);
	GetSystemInfo(&system_info);

	return ((perf_info.PhysicalTotal / 1024) * system_info.dwPageSize) / 1024;
}

JNIEXPORT jint JNICALL Java_com_pwrlab_memomonitor_MonitorJNI_getUsedRamMBNative(JNIEnv *, jclass) {
	perf_info.cb = sizeof(perf_info);
	GetPerformanceInfo(&perf_info, perf_info.cb);
	GetSystemInfo(&system_info);

	return ((perf_info.PhysicalAvailable / 1024) * system_info.dwPageSize) / 1024;
}