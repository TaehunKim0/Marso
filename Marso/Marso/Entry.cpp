#include"stdafx.h"
#include"MainScene.h"
#include"Stage1.h"

INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
	srand(time(NULL));

	/*AllocConsole();
	FILE* stream;
	freopen_s(&stream, "CONOUT$", "wt", stdout);*/

	App* app = App::Get();
	app->Init(1280, 720, 0);

	Director::Get()->AlterScene(new MainScene());
	app->GameLoop();

	return 0;
}