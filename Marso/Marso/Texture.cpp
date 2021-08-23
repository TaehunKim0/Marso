#include "stdafx.h"
#include "Texture.h"


Texture::Texture()
{
}

Texture::~Texture()
{
}

bool Texture::Init(std::wstring fileName)
{
	auto device = App::Get()->m_Device;

	HRESULT hr = D3DXCreateTextureFromFileEx(App::Get()->m_Device, fileName.c_str(),
		D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2, 1, 0, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, NULL,
		NULL, NULL, &m_Texture);

	switch (hr)
	{
	case D3DERR_NOTAVAILABLE:
		("");
		break;
	case D3DERR_OUTOFVIDEOMEMORY:
		("");
		break;
	case D3DERR_INVALIDCALL:
		("");
		break;
	case D3DXERR_INVALIDDATA:
		("");
		break;
	}

	if FAILED(hr)
	{
		("텍스쳐 생성 실패\n");
		return false;
	}

	D3DSURFACE_DESC desc;
	m_Texture->GetLevelDesc(0, &desc);

	m_Size.x = (float)(desc.Width);
	m_Size.y = (float)(desc.Height);

	return true;
}
