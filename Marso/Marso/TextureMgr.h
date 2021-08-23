#pragma once
class TextureMgr : public Singleton<TextureMgr>
{
public:
	std::map<std::wstring, Texture*> m_Map;

public:
	TextureMgr();
	~TextureMgr();

	Texture* GetTexture(std::wstring fileName);

};

