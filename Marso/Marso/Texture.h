#pragma once
class Texture
{
public:
	LPDIRECT3DTEXTURE9 m_Texture;
	Vector2 m_Size;

public:
	Texture();
	~Texture();

	bool Init(std::wstring fileName);

};

