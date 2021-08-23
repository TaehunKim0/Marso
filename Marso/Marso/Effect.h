#pragma once

enum class EffectType
{
	EnemyDead,
	BulletCollide,
};

class Effect : public Node
{
private:
	Sprite* m_Effect;
	EffectType m_Type;
	int frame;
	float m_Angle;

public:
	Effect();
	virtual ~Effect();

	void Init(float x, float y , EffectType type, float angle);
	void Update();
	void Draw();
};