#pragma once
class cApis
{
private:
//==========================================================================//
	int LoadModules();
	int LoadAddresses();
//==========================================================================//
	typedef void(WINAPI *safe_sleepA)(DWORD);
	typedef int(WINAPI* safe_get_intA)(LPCSTR, LPCSTR, INT, LPCSTR);
	typedef int(WINAPI* safe_closehandleA)(HANDLE);
	typedef BOOL(WINAPI *safe__DisableThreadCalls)(HMODULE);
	typedef BOOL(WINAPI *safe_terminatethreadA)(HANDLE, DWORD);
	typedef BOOL(WINAPI* safe_enumprocessmodulesA)(HANDLE, HMODULE *, DWORD, LPDWORD, DWORD);
	typedef HANDLE(WINAPI *safe_createthreadA)(LPSECURITY_ATTRIBUTES, SIZE_T, LPTHREAD_START_ROUTINE, LPVOID, DWORD, LPDWORD);
	typedef NTSTATUS(NTAPI *safe__NtQuerySyS)(ULONG, PVOID, ULONG, PULONG);
	typedef NTSTATUS(NTAPI *safe_read_memA)(HANDLE, PVOID, PVOID, ULONG, PULONG);
	typedef NTSTATUS(NTAPI *safe_write_memA)(HANDLE, PVOID, PVOID, ULONG, PULONG);
	typedef DWORD(WINAPI* safe_getcurrentprocessA)(void);
	typedef DWORD(WINAPI *safe_get_stringA)(LPCSTR, LPCSTR, LPCSTR, LPSTR, DWORD, LPCSTR);
	typedef DWORD(WINAPI* safe_getmodulebasenameA)(HANDLE, HMODULE, LPSTR, DWORD);
	safe__DisableThreadCalls safe_DisableThreadCalls = nullptr;
//==========================================================================//
	HMODULE safe_Kernel32 = nullptr;
	HMODULE safe_Ntdll = nullptr;
//==========================================================================//
public: int Start(HMODULE hMod);
	safe__NtQuerySyS safe_NtQuerySyS = nullptr;
	safe_get_stringA safe_get_string = nullptr;
	safe_read_memA safe_read_mem = nullptr;
	safe_write_memA safe_write_mem = nullptr;
	safe_sleepA safe_sleep = nullptr;
	safe_closehandleA safe_closehandle = nullptr;
	safe_createthreadA safe_createthread = nullptr;
	safe_getmodulebasenameA safe_getmodulebasename = nullptr;
	safe_enumprocessmodulesA safe_enumprocessmodules = nullptr;
	safe_terminatethreadA safe_terminatethread = nullptr;
	safe_get_intA safe_get_int = nullptr;
	safe_getcurrentprocessA safe_getcurrentprocess = nullptr;
//==========================================================================//
};

