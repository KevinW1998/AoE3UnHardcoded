#include "DelayLoad.h"

#include "UHC.h"

#include <delayimp.h>
#include <cstring>

FARPROC WINAPI DelayLoadNotifyHandler(unsigned dliNotify, PDelayLoadInfo pdli)
{
	if (dliNotify == dliNotePreLoadLibrary)
	{
		if (strcmp(pdli->szDll, "Bang.dll") == 0)
			return reinterpret_cast<FARPROC>(0xDEADBA26);
	} else if (dliNotify == dliNotePreGetProcAddress) {
		if (pdli->dlp.fImportByName && strcmp(pdli->szDll, "Bang.dll") == 0)
		{
			return reinterpret_cast<FARPROC>(pUHCInfo->BNative.GetSym(pdli->dlp.szProcName));
		}
	}
	return nullptr;
}

PfnDliHook const __pfnDliNotifyHook2 = &DelayLoadNotifyHandler;


