#pragma once
namespace flt
{
	class IRenderer;
}

namespace flt
{
	namespace engine
	{
		class Graphic
		{
		public:
			bool Initialize(IRenderer* renderer);
			bool Update();

		private:
			static IRenderer* g_pRenderer;
		};
	}
}
