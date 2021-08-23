#pragma once

#define SAFE_DELETE(x) if(x){delete x; x = nullptr;}

#define D3DXVECTOR2 Vector2

#include<Windows.h>
#include<stdio.h>
#include<mmsystem.h>
#include<d3d9.h>
#include<d3dx9.h>
#include<string>
#include<vector>
#include<map>
#include<time.h>

#include"Singleton.h"
#include"App.h"
#include"Texture.h"
#include"TextureMgr.h"
#include"Node.h"
#include"Scene.h"
#include"Sprite.h"
#include"Director.h"
#include"Input.h"
#include"CollisionMgr.h"
#include"Animation.h"
#include"Unit.h"
#include"Bullet.h"
#include"OurHero.h"
#include"Item.h"
#include"Effect.h"
#include"ObjectPool.h"
#include"Score.h"
#include"Progress.h"
#include"AddOn.h"