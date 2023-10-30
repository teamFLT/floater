#include "Graphic.h"

#include "Core.h"
#include "../FloaterRendererCommon/include/IRenderer.h"

flt::IRenderer* flt::engine::Graphic::g_pRenderer;

bool flt::engine::Graphic::Initialize(IRenderer* renderer)
{
	g_pRenderer=renderer;
	return true;
}

bool flt::engine::Graphic::Update()
{
	g_pRenderer->Render(static_cast<float>(Time::deltaTime));
	return true;
}
