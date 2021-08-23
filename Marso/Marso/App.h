#pragma once
class App : public Singleton<App>
{
public:
	HWND m_Hwnd;
	LPDIRECT3D9 m_D3D;
	LPDIRECT3DDEVICE9 m_Device;
	LPD3DXSPRITE m_Sprite;

	MCI_OPEN_PARMS mciOpen;
	MCI_PLAY_PARMS mciPlay;
	MCI_STATUS_PARMS mciStatus;

	DWORD WDeviceD;

	DWORD Sound;

	int m_Width;
	int m_Height;

	bool m_IsFullScreen;

public:
	App();
	~App();

	bool Init(int width, int height, bool windowMode);

	bool winInit();
	bool d3dInit();
	
	void GameLoop();

	void BeginScene();

	void EndScene();

	DWORD LoadWAV(LPCTSTR lpszWave)
	{
		DWORD Result = 0;

		mciOpen.lpstrDeviceType = L"WaveAudio";
		mciOpen.lpstrElementName = lpszWave;

		Result = mciSendCommand(WDeviceD, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)(LPVOID)&mciOpen);

		if (Result)
			return Result;

		WDeviceD = mciOpen.wDeviceID;

		mciPlay.dwCallback = (DWORD)m_Hwnd;

		if (Result)
			return Result;

		return 0;
	}

public:
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT Msg, WPARAM w, LPARAM l);
	
};