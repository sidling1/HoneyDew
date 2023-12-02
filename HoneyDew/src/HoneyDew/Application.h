#pragma once

#include "Core.h"

namespace Honey{

	class HNY_API Application
	{
		
		public:
			Application();
			virtual ~Application();

			void Run();

	};

	//To be defined in the client
	Application* CreateApplication();
}


