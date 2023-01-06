#pragma once
#include "../../utilities/includes.hpp"
#include "../../dependencies/minhook/MinHook.h"

class Hooks 
{
private:
	bool AddHook(std::string hookName, unsigned long long pTarget, void* detour, void* original);
public:
	bool Setup();
	void Destroy();

	static void __stdcall hRecoilFir(Firearms_o* thisptr, float x, float y, float z);
	static void __stdcall hDoAttack(Firearms_o* thisptr);
	static void __stdcall hReloadGun(Firearms_o* thisptr, float time, int spin);

	static void __stdcall hUpdatePlayer(Player* player);

	HWND window = NULL;
	WNDPROC oWndProc;
	ID3D11Device* pDevice = NULL;
	ID3D11DeviceContext* pContext = NULL;
	ID3D11RenderTargetView* mainRenderTargetView;

	static LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	static HRESULT __stdcall hPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
private:

	typedef void(__thiscall* RecoilFirFN)(Firearms_o*, float, float, float);
	typedef void(__thiscall* ReloadGunFN)(Firearms_o*, float, int);
	typedef void(__thiscall* DoAttackFN)(Firearms_o*);
	typedef unsigned long(__stdcall* PresentFN) (IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
	typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);

	typedef void(__thiscall* UpdatePlayerFN)(Player*);
public:
	RecoilFirFN oRecoil = nullptr;
	DoAttackFN oDoAttack = nullptr;
	ReloadGunFN oReloadGun = nullptr;

	UpdatePlayerFN oUpdatePlayer = nullptr;

	PresentFN oPresent = nullptr;
}; inline Hooks* g_Hooks = new Hooks();