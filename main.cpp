#include <iostream>
#include "GameLoop.h"
#include <Windows.h>

void ShowConsoleCursor(bool showFlag)
{
	auto out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO     cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(out, &cursorInfo);
}

void SetCursorPosition(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

class GameSample : public GameCore::GameLoop
{
public:
	void Update(long long time) override
	{

	}
	void Render() override
	{
		SetCursorPosition(0, 0);
		std::cout << "FPS: " << GetFramesPerSecond() << " UPS: " << GetUpdatePerSecond();
	}
};

int main()
{
	ShowConsoleCursor(false);
	auto game = GameSample();
	game.Run();
}
