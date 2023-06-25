#pragma once

namespace GameCore
{
	class GameLoop
	{
	private:
		int UPS;
		int FPS;
		bool _isRunning;
		void StartMainLoop();
	protected:
		virtual void Update(long long tSpan) = 0;
		virtual void Render() = 0;
	public:
		GameLoop();
		void Run();
		int GetFramesPerSecond() const;
		int GetUpdatePerSecond() const;
		void Exit();
	};
}
