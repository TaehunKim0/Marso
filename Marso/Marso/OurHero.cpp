#include "stdafx.h"
#include "OurHero.h"

OurHero* OurHero::Inst = nullptr;

OurHero::OurHero()
{
}

OurHero::~OurHero()
{
	("hERo Deie");
}

void OurHero::Init(float x, float y)
{
	Star = 0;
	hpFrameCounter = 10;
	IsShield = 0;
	AddOnCount = 1;
	CanCollide2 = 1;
	CanMove = 1;
	UpgradeWeapon();

	w = 1;
	m_WeaponSprite = new Animation(1, 0);

	m_WeaponSprite->AddFrame(L"Resource/UI/Weapon1.png");
	m_WeaponSprite->AddFrame(L"Resource/UI/Weapon2.png");
	m_WeaponSprite->AddFrame(L"Resource/UI/Weapon3.png");

	m_WeaponSprite->SetPos(8.f, 18.f);
	m_WeaponSprite->UsePMatrix = 0;

	AddChild(m_WeaponSprite);

	m_Anim = new Animation(1, 0);
	m_Anim->AddFrame(L"Resource/Player/Player.png");
	m_Anim->AddFrame(L"Resource/Player/PlayerDmg.png");

	m_Speed = 7.f;
	m_Weapon = Weapon::OneBullet;

	m_UI = Sprite::Create(L"Resource/UI/PlayerUI.png");
	m_UI->UsePMatrix = 0;
	m_UI->Translate(10.f, 20.f);

	AddChild(m_UI);

	Unit::Init(x, y, Tag::Player, L"Hero", 10);
	m_Size = Vector2(81, 100);

	m_HpAnim = new Animation(1, 0);
	
	for (int i = 1; i <= 10; i++)
	{
		m_HpAnim->AddFrame(L"Resource/UI/Hp/" + std::to_wstring(i) + L".png");
	}

	m_HpAnim->CurrentFrame = 9;
	m_HpAnim->UsePMatrix = 0;
	m_HpAnim->Translate(150.f, 25.f);

	AddChild(m_HpAnim);
	AddChild(m_Anim);
}

void OurHero::Update()
{
	Node::Update();

	UpgradeWeapon();

	if (Died)
	{
		m_UI->Alpha = 100;
		m_HpAnim->Alpha = 100;
		m_WeaponSprite->Alpha = 100;
	}

		if (Died == 0 && CanMove) {
			MoveMent();
			Attack();
		}
	
	if (CanCollide == false)
		m_Anim->SetFrame(1);
	else
		m_Anim->SetFrame(0);

	if (CanCollide == false)
		Frame1++;

	if (Frame1 >= 10)
	{
		Frame1 = 0;
		CanCollide = 1;
	}

	if (CanCollide2 == false)
		Frame2++;

	if (Frame2 >= 5)
	{
		Frame2 = 0;
		CanCollide2 = 1;
	}

	switch (m_Direction)
	{
	case Direction::Left:

		break;

	case Direction::Right:

		break;
	}

	if (m_Hp <= 0)
	{
		Died = 1;
	}

	if (Died)
	{
		CollisionMgr::Get()->DestroyCollision(this);
	}
}

void OurHero::Draw()
{
	Unit::Draw();

	switch (m_Direction)
	{
	case Direction::Left:

		break;

	case Direction::Right:

		break;
	}
}

void OurHero::MoveMent()
{
	if (m_Pos.x <= 0)
		m_Pos.x = 0;
	else if (m_Pos.x >= 1280 - m_Size.x)
		m_Pos.x = 1280 - m_Size.x;
	if (m_Pos.y <= 0)
		m_Pos.y = 0;
	else if (m_Pos.y >= 720 - m_Size.y)
		m_Pos.y = 720 - m_Size.y;

	if (Input::Get()->GetKeyState('A') == KeyState::Press)
	{
		Translate(-m_Speed, 0.f);
		m_Direction = Direction::Left;
	}
	else if (Input::Get()->GetKeyState('D') == KeyState::Press)
	{
		Translate(m_Speed, 0.f);
		m_Direction = Direction::Right;
	}
	if (Input::Get()->GetKeyState('S') == KeyState::Press)
	{
		Translate(0.f, m_Speed);
	}
	else if (Input::Get()->GetKeyState('W') == KeyState::Press)
	{
		Translate(0.f, -m_Speed);
	}

	else
		m_State = State::Idle;
}

void OurHero::Attack()
{
	Frame3++;

	if (m_Weapon == Weapon::Lazer_Tripple)
	{
		if (Frame3 >= 120)
		{
			ObjectPool::Get()->FireLazer(m_Pos + Vector2{ 35.f, 0.f }, Tag::Player);
			Frame3 = 0;
		}
	}

	if (Input::Get()->GetKeyState(VK_SPACE) == KeyState::Up)
	{
		switch (m_Weapon)
		{
		case Weapon::OneBullet:
		{
			ObjectPool::Get()->FireBullet(m_Pos + Vector2{ 35.f,-30.f }, Tag::Player, Direction::Up, 10.f, L"Resource/Bullet/Player.png", D3DXToRadian(-90));
			break;
		}

		case Weapon::Tripple:
		{
			ObjectPool::Get()->FireBullet(m_Pos + Vector2{ 35.f,-30.f }, Tag::Player, Direction::Up, 10.f, L"Resource/Bullet/Player.png", D3DXToRadian(-110));
			ObjectPool::Get()->FireBullet(m_Pos + Vector2{ 35.f,-30.f }, Tag::Player, Direction::Up, 10.f, L"Resource/Bullet/Player.png", D3DXToRadian(-90));
			ObjectPool::Get()->FireBullet(m_Pos + Vector2{ 35.f,-30.f }, Tag::Player, Direction::Up, 10.f, L"Resource/Bullet/Player.png", D3DXToRadian(-70));
			break;
		}

		case Weapon::Lazer_Tripple:
		{
			ObjectPool::Get()->FireBullet(m_Pos + Vector2{ 35.f,-30.f }, Tag::Player, Direction::Up, 10.f, L"Resource/Bullet/Player.png", D3DXToRadian(-90));
			ObjectPool::Get()->FireMissile(m_Pos + Vector2{ 5.f,50.f }, Tag::Player,  10.f, D3DXToRadian(-90.f), L"Resource/Bullet/Missile.png");
			ObjectPool::Get()->FireMissile(m_Pos + Vector2{ 65.f,50.f }, Tag::Player, 10.f, D3DXToRadian(-90.f) ,L"Resource/Bullet/Missile.png");
			break;

		}
		}
	}
}

void OurHero::HpCalc(bool plus)
{
	if(plus)
		m_HpAnim->CurrentFrame += 1;
	else
		m_HpAnim->CurrentFrame -= 1;
}

void OurHero::CollideWith(Node * other)
{
	if(CanCollide)
		if (other->m_Tag == Tag::Enemy || other->m_Name == L"Meteor")
		{
			if (IsShield)
			{
				IsShield = 0;
				return;
			}

			if (Star == false)
			{
				m_Hp -= 1;

				w--;

				if (w <= 0)
					w = 1;

				m_HpAnim->CurrentFrame -= 1;

				if (m_HpAnim->CurrentFrame <= 0)
					m_HpAnim->CurrentFrame = 0;

				CanCollide = 0;
			}
		}


	if(CanCollide2)
		if (other->m_Tag == Tag::Item)
		{
			if (other->m_Name == L"SpeedUp")
			{
				m_Speed += 1.f;

				if (m_Speed >= 10.f)
					m_Speed = 10.f;

				CanCollide2 = 0;
			}

			if (other->m_Name == L"HpUp")
			{
				m_Hp += 1;
				m_HpAnim->CurrentFrame += 1;

				if (m_Hp >= 10)
					m_Hp = 10;

				if(m_HpAnim->CurrentFrame > 9)
					m_HpAnim->CurrentFrame = 9;

				CanCollide2 = 0;
			}

			if (other->m_Name == L"Shield")
			{
				IsShield = 1;
				CanCollide2 = 0;
			}

			if (other->m_Name == L"WeaponUp")
			{	
				w++;
				CanCollide2 = 0;
			}

			if (other->m_Name == L"Add_On")
			{
				AddOnPlayer(AddOnCount);
				CanCollide2 = 0;
			}
		}
}

void OurHero::AddOnPlayer(int count)
{
	switch (count)
	{
	case 1:
		add1 = new AddOn();
		add1->Init(count);

		AddOnCount++;

		AddChild(add1);
		break;

	case 2:
		add2 = new AddOn();
		add2->Init(count);

		AddOnCount++;

		AddChild(add2);
		break;

	case 3:
		add3 = new AddOn();
		add3->Init(count);

		AddOnCount++;

		AddChild(add3);
		break;

	case 4:
		add4 = new AddOn();
		add4->Init(count);

		AddOnCount++;

		AddChild(add4);
		break;
	}
	


}