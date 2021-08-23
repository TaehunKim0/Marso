#include "stdafx.h"
#include "App.h"


App::App()
{
}


App::~App()
{
}

bool App::Init(int width, int height, bool windowMode)
{
	m_Width = width;
	m_Height = height;
	m_IsFullScreen = windowMode;

	if (winInit())
		if (!d3dInit())
			return false;

	return true;

}

bool App::winInit()
{
	WNDCLASS wc = {};
	wc.lpszClassName = L"Marso";
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.lpfnWndProc = WndProc;

	if (!RegisterClass(&wc))
		return false;

	DWORD Style = 0;
	if (m_IsFullScreen)
	{
		Style = WS_EX_TOPMOST | WS_POPUP | WS_OVERLAPPEDWINDOW;
	}
	else
	{
		Style = WS_POPUP | WS_OVERLAPPEDWINDOW;
	}

	HWND handle = CreateWindow(wc.lpszClassName, wc.lpszClassName, Style, 0, 0, m_Width, m_Height, NULL, NULL, NULL, NULL);
	if (handle == nullptr)
		return false;
	m_Hwnd = handle;

	ShowWindow(m_Hwnd, SW_SHOWDEFAULT);
	return true;
}

bool App::d3dInit()
{
	m_D3D = Direct3DCreate9(D3D_SDK_VERSION);

	D3DPRESENT_PARAMETERS pp = {  };
	pp.BackBufferFormat = D3DFMT_A8R8G8B8;
	pp.BackBufferWidth = m_Width;
	pp.BackBufferHeight = m_Height;
	pp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	pp.Windowed = !m_IsFullScreen;

	HRESULT hr = m_D3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, m_Hwnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&pp, &m_Device);

	if FAILED(hr)
		return false;

	if FAILED(D3DXCreateSprite(m_Device, &m_Sprite))
		return false;

	return true;
}

void App::GameLoop()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 1, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			BeginScene();
			Input::Get()->Update();
			CollisionMgr::Get()->Update();

			Director::Get()->Update();
			Director::Get()->Draw();
			EndScene();
		}
	}

}

void App::BeginScene()
{
	m_Device->Clear(1, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.f, 0);
	m_Device->BeginScene();
}

void App::EndScene()
{
	m_Device->EndScene();
	m_Device->Present(NULL, NULL, NULL, NULL);
}

LRESULT App::WndProc(HWND hWnd, UINT Msg, WPARAM w, LPARAM l)
{
	switch (Msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd, Msg, w, l);
}
