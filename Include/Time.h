#pragma once

struct CpuTicks
{
public:
    long long Last;
    long long Current;
};

namespace Utils
{
#define TicksPerSecond 10000000
#define TicksPerMillisecond 10000
    class Time
    {
    private:
        const int UPS = 60;
        double MS_PER_UPDATE = TicksPerSecond / UPS / TicksPerMillisecond;
        double _delta;
        long long _oneSecondTimer;
    public:
        CpuTicks Ticks;
        bool IsRequiredGameUpdate() const;
        bool IsSecondPassed() const;
        Time();
        void UpdateTime();
        void IncreaseSecondTimer();
        void ResetDelta();
    };
}

