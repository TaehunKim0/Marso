#pragma once
class ObjectPool : public Singleton<ObjectPool>
{
public:
	Scene* m_Parent;
	std::vector<Unit*> m_Enemys;

public:
	ObjectPool();
	~ObjectPool();

	void Init(Scene* scene, int bulletCount);
	void Init(Scene* scene);

public:
	void SpawnStraight(float x, float y);
	void SpawnDivide(float x, float y);
	void SpawnDivided(float x, float y, float angle);
	void SpawnFlight(float x, float y);
	void SpawnFlightFormation(float x, float y);
	void SpawnDash(float x, float y);

public:
	void FireBullet(Vector2 pos, Tag tag, Direction direction, float speed, std::wstring fileName, float angle);
	void CreateEffect(float x, float y, EffectType type, float angle);
	void CreateItem(float x, float y, ItemGroup group);

	void FireMissile(Vector2 pos, Tag tag, float speed, float angle, std::wstring fileName);
	void FireLazer(Vector2 pos, Tag tag);

public:
	void Release();
	void DestroyEnemy(Node* enemy);
};