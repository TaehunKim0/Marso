#include "stdafx.h"
#include "TextureMgr.h"


TextureMgr::TextureMgr()
{
}


TextureMgr::~TextureMgr()
{
}

Texture * TextureMgr::GetTexture(std::wstring fileName)
{
	if (!m_Map.count(fileName))
	{
		auto texture = new (std::nothrow) Texture();
		if (texture && texture->Init(fileName))
		{
			m_Map[fileName] = texture;
		}
		else
		{
			("텍스쳐 없음\n");
			SAFE_DELETE(texture);
			return nullptr;
		}
	}

	return m_Map[fileName];
}
