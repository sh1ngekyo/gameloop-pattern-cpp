#include "Time.h"
#include <Windows.h>
#include <cmath>

long long GetCPUTicks()
{
	return GetTickCount() * 10000i64;
}

Utils::Time::Time()
{
	Ticks = CpuTicks();
	_oneSecondTimer = GetCPUTicks();
	Ticks.Last = GetCPUTicks() / TicksPerMillisecond;
	_delta = 0.0;
}

bool Utils::Time::IsRequiredGameUpdate() const
{
	return _delta >= MS_PER_UPDATE;
}

bool Utils::Time::IsSecondPassed() const
{
	return GetCPUTicks() - _oneSecondTimer > TicksPerSecond;
}

void Utils::Time::UpdateTime()
{
	Ticks.Current = GetCPUTicks() / TicksPerMillisecond;
	_delta += (Ticks.Current - Ticks.Last);
	Ticks.Last = Ticks.Current;
}

void Utils::Time::IncreaseSecondTimer()
{
	_oneSecondTimer = GetCPUTicks();
}

void Utils::Time::ResetDelta()
{
	_delta = std::fmod(_delta, MS_PER_UPDATE);
}