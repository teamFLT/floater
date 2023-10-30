#include "Core.h"

double flt::engine::Time::deltaTime;

flt::engine::Core::Core()
{
}

flt::engine::Core::~Core()
{
}

bool flt::engine::Core::Initialize()
{
	bool ret = false;
	_timer.Start();
	ret = _platform.Initialize(1280, 1080, title, iconPath);
	if (ret)
	{
		return ret;
	}
	ret = _input.Initialize(&_platform);
	if (ret)
	{
		return ret;
	}
	ret = _graphic.Initialize(_platform.CreateRenderer(RendererType::DX11));
	if (ret)
	{
		return ret;
	}
	ret = _gameObjectManager.Initialize();
	if (ret)
	{
		return ret;
	}
	return true;
}

bool flt::engine::Core::Update()
{
	bool ret = false;
	_timer.Update();
	Time::deltaTime = _timer.GetDeltaSeconds();
	ret = _platform.Update();
	if (ret)
	{
		return ret;
	}
	ret = _input.Update();
	if (ret)
	{
		return ret;
	}
	ret = _gameObjectManager.Update();
	if (ret)
	{
		return ret;
	}
	return true;
}

bool flt::engine::Core::Finalize()
{
	return _platform.Finalize();
}
