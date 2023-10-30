#pragma once
#include "GameObjectManager.h"
#include "Graphic.h"
#include "Input.h"
#include "Timer.h"
#include "Platform.h"

namespace flt
{
	namespace engine
	{
		class Time
		{
		public:
			static double deltaTime;
		};

		class Core
		{
		public:
			Core();
			~Core();
		private:
			bool Initialize();
			bool Update();
			bool Finalize();

		private:
			std::wstring title;
			std::wstring iconPath;
			GameObjectManager _gameObjectManager;
			Platform _platform;
			Input _input;
			Graphic _graphic;
			Timer _timer;
		};
	}
}
