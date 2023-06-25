#include "GameLoop.h"
#include "Time.h"

GameCore::GameLoop::GameLoop()
{
    _isRunning = false;
}

void GameCore::GameLoop::Run()
{
    if (_isRunning)
        return;
    StartMainLoop();
}

void GameCore::GameLoop::StartMainLoop()
{
    auto time = Utils::Time();
    auto frames = 0;
    auto ups = 0;
    _isRunning = true;
    while (_isRunning)
    {
        time.UpdateTime();
        if (time.IsRequiredGameUpdate())
        {
            Update(time.Ticks.Current);
            ++ups;
            time.ResetDelta();
        }
        ++frames;
        Render();
        if (time.IsSecondPassed())
        {
            time.IncreaseSecondTimer();
            UPS = ups;
            FPS = frames;
            ups = 0;
            frames = 0;
        }
    }
}

int GameCore::GameLoop::GetFramesPerSecond() const
{
    return FPS;
}

int GameCore::GameLoop::GetUpdatePerSecond() const
{
    return UPS;
}

void GameCore::GameLoop::Exit()
{
    _isRunning = false;
}