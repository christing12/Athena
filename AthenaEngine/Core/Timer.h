#pragma once
#include <chrono>

namespace athena {
	class Timer {
	public:
		void Start();
		void Stop();

		double ElapsedMilliseconds();
		double ElapsedSeconds();
	private:
		const double MS_TO_S = 1 / 1000.0;
		using time_point = std::chrono::time_point<std::chrono::system_clock>;
		time_point m_StartTime;
		time_point m_endTime;
		bool m_isRunning = false;
	};

}
