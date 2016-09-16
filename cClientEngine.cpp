#include "stdafx.h"
#include "cClientEngine.h"

cVector cClientEngine::GetViewAngles()
{
	return cVector(pad[cNetvar->dw_ViewAngles_x], pad[cNetvar->dw_ViewAngles_y], 0);
}

void cClientEngine::SetViewAngles(cVector Angles)
{
	if (this->CheckProcess())
	{
		cMem->RPM(PVOID(cMem->engine_dll + cNetvar->dw_EnginePointer), &dwgEngine, sizeof(DWORD), 0);
		if (!dwgEngine)return;
		cMem->WPM(PVOID(dwgEngine + cNetvar->dw_ViewAngles), &Angles, sizeof(cVector), 0);
		if (!this)return;
	}
}

void cClientEngine::GetEngine()
{
	if (this->CheckProcess())
	{
		cMem->RPM(PVOID(cMem->engine_dll + cNetvar->dw_EnginePointer), &dwgEngine, sizeof(DWORD), 0);
		if (!dwgEngine)return;
		cMem->RPM(PVOID(dwgEngine), this, sizeof(cClientEngine), 0);
		if (!this)return;
	}
}

bool cClientEngine::CheckProcess()
{
	if (!cMem->hProc)
		return false;

	if (!cMem->engine_dll)
		return false;
	return true;
}
