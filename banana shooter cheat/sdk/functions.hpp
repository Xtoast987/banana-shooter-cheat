#pragma once
#include "sdk.hpp"
#include "../core/hack.hpp"

class Functions {
private:
	typedef void(__cdecl* CreateExplosiveBulletFN)(void*, Vector3);

	typedef Camera*(__cdecl* CameraGetCurrentFN)();
	typedef void(__cdecl* CameraSetAspect)(void*, float);
public:
	CreateExplosiveBulletFN pCreateExplosiveBullet = nullptr;

	CameraGetCurrentFN pGetCurrentCam = nullptr;
	CameraSetAspect pSetCameraAspect = nullptr;
public:
	void Setup() 
	{
		pCreateExplosiveBullet = reinterpret_cast<CreateExplosiveBulletFN>(Offsets::pAssembly + Offsets::Firearms::CreateExplosiveBullet);
		pGetCurrentCam = reinterpret_cast<CameraGetCurrentFN>(Offsets::pAssembly + Offsets::Cam::GetCurrent);
		pSetCameraAspect = reinterpret_cast<CameraSetAspect>(Offsets::pAssembly + Offsets::Cam::SetAspect);
	}
}; inline Functions* g_Funcs = new Functions();