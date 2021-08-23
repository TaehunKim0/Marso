#include "stdafx.h"
#include "ObjectPool.h"
#include"Enemys.h"
#include"Missile.h"
#include"Lazer.h"

ObjectPool::ObjectPool()
{
}

ObjectPool::~ObjectPool()
{
}

void ObjectPool::Init(Scene * scene, int bulletCount)
{
	m_Parent = scene;
}

void ObjectPool::Init(Scene * scene)
{
	m_Parent = scene;
}

void ObjectPool::SpawnStraight(float x, float y)
{
	auto straight = new StraightEnemy();
	straight->Init(x, y);
	straight->UsePMatrix = 0;

	m_Enemys.push_back(straight);

	m_Parent->AddChild(straight);
}

void ObjectPool::SpawnDivide(float x, float y)
{
	auto divide = new DivideEnemy();
	divide->Init(x, y);
	divide->UsePMatrix = 0;
	m_Enemys.push_back(divide);
	m_Parent->AddChild(divide);
}

void ObjectPool::SpawnDivided(float x, float y , float angle)
{
	auto divided = new Divided();
	divided->Init(x, y, angle);
	m_Enemys.push_back(divided);
	m_Parent->AddChild(divided);
}

void ObjectPool::SpawnFlight(float x, float y)
{
	auto flight = new FlightEnemy();
	flight->Init(x, y);
	flight->UsePMatrix = 0;
	m_Enemys.push_back(flight);
	m_Parent->AddChild(flight);
}

void ObjectPool::SpawnFlightFormation(float x, float y)
{
	SpawnFlight(x, y);
	SpawnFlight(x , y + 80);
	SpawnFlight(x + 140, y - 20);
	SpawnFlight(x - 140, y - 20);
	SpawnFlight(x + 280, y - 40);
	SpawnFlight(x - 280, y - 50);

	SpawnFlight(x, y - 100);
}

void ObjectPool::SpawnDash(float x, float y)
{
	auto dash = new DashEnemy();
	dash->Init(x, y);
	dash->UsePMatrix = 0;
	m_Enemys.push_back(dash);
	m_Parent->AddChild(dash);
}

void ObjectPool::FireBullet(Vector2 pos, Tag tag, Direction direction, float speed, std::wstring fileName, float angle)
{
	auto bullet = new Bullet(pos,tag,direction,speed,fileName,angle);
	m_Parent->AddChild(bullet);
}

void ObjectPool::CreateEffect(float x, float y, EffectType type, float angle)
{
	if (m_Parent == nullptr)
		return;

	auto effect = new Effect();
	effect->Init(x, y, type,angle);
	effect->UsePMatrix = 0;

	m_Parent->AddChild(effect);
}

void ObjectPool::CreateItem(float x, float y, ItemGroup group)
{
	if (m_Parent == nullptr)
		return;

	auto item = new Item();
	item->Init(x, y, group);

	m_Parent->AddChild(item);
}

void ObjectPool::FireMissile(Vector2 pos, Tag tag, float speed, float angle, std::wstring fileName)
{ 
	auto missile = new Missile();
	missile->Init( pos, tag, angle, speed, fileName);

	m_Parent->AddChild(missile);
}

void ObjectPool::FireLazer(Vector2 pos, Tag tag)
{
	auto lazer = new Lazer();
	lazer->UsePMatrix = 0;
	lazer->Init(pos, tag);

	m_Parent->AddChild(lazer);
}

void ObjectPool::Release()
{
	m_Enemys.clear();
	m_Parent = NULL;
}

void ObjectPool::DestroyEnemy(Node * enemy)
{
	auto iter = std::find(m_Enemys.begin(), m_Enemys.end(), enemy);

	if (iter != m_Enemys.end())
	{
		m_Enemys.erase(iter);
	}
}
