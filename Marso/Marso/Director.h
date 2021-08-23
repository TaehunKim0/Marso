#pragma once
class Director : public Singleton<Director>
{
public:
	Scene* m_CurrentScene;


public:
	Director();
	~Director();

	void Update();
	void Draw();

	void AlterScene(Scene* scene);
};