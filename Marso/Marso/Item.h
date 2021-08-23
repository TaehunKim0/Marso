#pragma once
enum class ItemGroup
{
	SpeedUp,
	HpUp,
	Shield,
	WeaponUp,
	Missile,
	Add_On
};

class Item : public Node
{
private:
	Sprite* m_Sprite;
	bool died;
public:
	Item();
	virtual ~Item();

	ItemGroup m_Group;

	void Init(float x, float y , ItemGroup item);

	void Update();
	void Draw();
	void CollideWith(Node* other);
};

