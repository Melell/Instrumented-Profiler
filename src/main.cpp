#include "Profiler.h"
#include "OutputFormatters.h"
#include <iostream>


void Physics()
{
	for (int i = 0; i < 1000; ++i)
		std::cout << "Physics " << i<<std::endl;
}

void AI()
{
	for (int i = 0; i < 5000; ++i)
		std::cout << "AI " << i << std::endl;
}


void DoTerrain()
{
	for (int i = 0; i < 10000; ++i)
		std::cout << "DoTerrain " << i << std::endl;
}

void DoObjects()
{
	for (int i = 0; i < 20000; ++i)
		std::cout << "DoObjects " << i << std::endl;
}

void DoUI()
{
	for (int i = 0; i < 10000; ++i)
		std::cout << "DoUI " << i << std::endl;
}


void Graphics()
{
	{
		SCOPED_PROFILER("DoTerrain");
		DoTerrain();
	}

	{
		SCOPED_PROFILER("DoObjects");
		DoObjects();
	}

	{
		SCOPED_PROFILER("DoUI");
		DoUI();
	}
}




int main()
{
	{
		SCOPED_PROFILER("main");

		{
			SCOPED_PROFILER("Physics");
			Physics();
			//auto& profilerMgr = Profiler::ProfilingMgr::get_instance();
		}

		{
			SCOPED_PROFILER("AI");
			AI();
			//auto& profilerMgr = Profiler::ProfilingMgr::get_instance();
		}

		{
			SCOPED_PROFILER("Graphics");
			Graphics();
			//auto& profilerMgr = Profiler::ProfilingMgr::get_instance();
		}
	}

	DUMP_TO_JSON("example.json");

	//auto & profilerMgr = Profiler::ProfilingMgr::get_instance();

	return 0;
}