#include "stdafx.h"
#include "Sprite.h"


Sprite::Sprite()
{
	UseMRect = 1;
	frame = 0;
	Alpha = 255;
	tick = 0;
	died = 0;
}

Sprite::~Sprite()
{
}

Sprite * Sprite::Create(std::wstring fileName)
{
	auto sprite = new (std::nothrow) Sprite();
	if (sprite && sprite->Init(fileName))
	{
		return sprite;
	}

	MessageBox(nullptr, fileName.c_str(), nullptr, 0);

	SAFE_DELETE(sprite);
	return nullptr;
}

bool Sprite::Init(std::wstring fileName)
{
	m_Texture = TextureMgr::Get()->GetTexture(fileName);

	if (m_Texture)
	{
		m_Size.x = m_Texture->m_Size.x;
		m_Size.y = m_Texture->m_Size.y;
	}
	else
	{
		return false;
	}
	return true;
}

void Sprite::Draw()
{
	auto sprite = App::Get()->m_Sprite;
	sprite->Begin(D3DXSPRITE_ALPHABLEND);
	sprite->SetTransform(&GetMatrix());

	if (UseMRect)
	{
		RECT rect;
		SetRect(&rect, 0, 0, (int)(m_Size.x), (int)(m_Size.y));
		m_Rect = rect;
	}

	if (tick)
	{
		frame++;
	}

	if (tick)
	{
		Alpha = 100;

		if (frame >= 5)
		{
			Alpha = 255;
			tick = 0;
			frame = 0;
		}
	}

	if (died)
	{
		frame++;

		if (frame % 5 == 0)
		{
  			Alpha -= 60;
		}
		
		if (frame >= 30)
		{
			died = 0;
			frame = 0;
		}
	}

	sprite->Draw(m_Texture->m_Texture, &m_Rect, &D3DXVECTOR3{ 0.f,0.f,0.f }, NULL, D3DCOLOR_ARGB(Alpha, 255, 255, 255));
	sprite->End();
}
