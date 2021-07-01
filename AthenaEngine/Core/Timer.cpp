#include "pch.h"
#include "Timer.h"


namespace chr = std::chrono;
namespace athena
{
	
	void athena::Timer::Start()
	{
		m_StartTime = chr::system_clock::now();
		m_isRunning = true;
	}

	void athena::Timer::Stop()
	{
		m_endTime = chr::system_clock::now();
		m_isRunning = false;
	}

	double athena::Timer::ElapsedMilliseconds()
	{
		time_point endTime = m_isRunning ? chr::system_clock::now() : m_endTime;
		return chr::duration_cast<chr::milliseconds>(endTime - m_StartTime).count();
	}

	double athena::Timer::ElapsedSeconds()
	{
		return ElapsedMilliseconds() * MS_TO_S;
	}

}

