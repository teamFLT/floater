#pragma once

namespace flt
{
	enum class RendererFlag
	{
		SOFTWARE = 0x0000'0001,
		ACCELERATED = 0x0000'0002,

	};

	struct Renderable
	{
		// 1. 그릴때 필요한것들.
		// 2. 게임 엔진상에서 데이터를 바꾸고 싶은것들.

		// transform
		// model
		// material, texture
		// shader
		// 
	};

	class IRenderer
	{
	public:
		IRenderer() = default;
		virtual ~IRenderer() = default;

		virtual bool Render(float deltaTime) = 0;
		virtual bool RegisterObject(Renderable& renderable) = 0;
		virtual bool DeregisterObject(Renderable& renderable) = 0;
	};
}
