#pragma once
enum class Weapon
{
	OneBullet,
	Tripple,
	Lazer_Tripple
};

class AddOn;
class OurHero : public Unit
{
private:
	static OurHero* Inst;
	Weapon m_Weapon;

	int hpFrameCounter;
	bool IsShield;
	bool CanCollide2;

	AddOn* add1;
	AddOn* add2;
	AddOn* add3;
	AddOn* add4;

public:
	OurHero();
	virtual ~OurHero();
	bool Star;

	Sprite* m_UI;
	Animation* m_WeaponSprite;
	Animation* m_HpAnim;

	void Release()
	{
		for (int i = 0; i < m_Children.size(); i++)
		{
			SAFE_DELETE(m_Children[i]);
			//("³ëµå Á¦°ÅµÊ");
		}
		m_Children.clear();
	}

	int AddOnCount;
	int w;
	void UpgradeWeapon() {

		if (w == 1)
		{
			m_Weapon = Weapon::OneBullet;

			if(m_WeaponSprite)
				m_WeaponSprite->SetFrame(0);
		}

		if (w == 2)
		{
			m_Weapon = Weapon::Tripple;
			m_WeaponSprite->SetFrame(1);
		}

		if (w == 3)
		{
			m_Weapon = Weapon::Lazer_Tripple;
			m_WeaponSprite->SetFrame(2);
		}

		if (w >= 3)
			w = 3;

	}

	static OurHero* Get()
	{
		if (Inst == nullptr)
		{
			Inst = new OurHero();
		}
		return Inst;
	}

	static void ReleaseInst()
	{
		delete Inst;
		Inst = nullptr;
	}
	bool CanMove;
	void Init(float x, float y);
	void Update();
	void Draw();

	void MoveMent();
	void Attack();
	void HpCalc(bool plus);
	void CollideWith(Node* other);

	void AddOnPlayer(int count);
	

};

