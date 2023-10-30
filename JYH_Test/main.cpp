#define FLT_WINDOWS

#include <iostream>
#include "../FloaterPlatform/include/Platform.h"
#include "../FloaterUtil/include/Timer.h"
#include "../FloaterUtil/include/FloaterMacro.h"
#include <windows.h>



int main()
{
	std::cout << std::boolalpha;

	std::cout << sizeof(bool) << std::endl;
	std::cout << sizeof(int) << std::endl;

	flt::Platform platform;
	platform.Initialize(1280, 720, L"title", L".\\path");
	auto renderer = platform.CreateRenderer(flt::RendererType::DX11);

	//ASSERT(renderer, "렌더러 생성 실패");

	while (true)
	{
		if (!platform.Update())
		{
			break;
		}

		renderer->Render(1.0f);

		//if (!renderer->Render(deltaTime))
		//{
		//	break;
		//}

		auto keyData = platform.GetKey(flt::KeyCode::z);
		if (keyData)
		{
			std::cout << "z" << keyData.keyTime << std::endl;
		}
		keyData = platform.GetKey(flt::KeyCode::x);
		if (keyData)
		{
			std::cout << "x" << keyData.keyTime << std::endl;
		}
		keyData = platform.GetKey(flt::KeyCode::mouseLButton);
		if (keyData)
		{
			std::cout << "LL " << keyData.keyTime << " " << keyData.x << " " << keyData.y << std::endl;
		}
		keyData = platform.GetKey(flt::KeyCode::mouseRButton);
		if (keyData)
		{
			std::cout << "RR " << keyData.keyTime << std::endl;
		}

		keyData = platform.GetKey(flt::KeyCode::mouseRelativePos);
		if (keyData)
		{
			std::cout << "diff Pos " << keyData.x << " " << keyData.y << std::endl;
		}

		keyData = platform.GetKey(flt::KeyCode::mouseWheelUp);
		if (keyData)
		{
			std::cout << "wheel up " << keyData.x << std::endl;
		}

		keyData = platform.GetKey(flt::KeyCode::mouseWheelDown);
		if (keyData)
		{
			std::cout << "wheel down " << keyData.x << std::endl;
		}

		keyData = platform.GetKey(flt::KeyCode::mouseButton3);
		if (keyData)
		{
			std::cout << "button3 " << keyData.keyTime << std::endl;
		}

		keyData = platform.GetKey(flt::KeyCode::mouseButton4);
		if (keyData)
		{
			std::cout << "button4 " << keyData.keyTime << std::endl;
		}

		keyData = platform.GetKey(flt::KeyCode::mouseMButton);
		if (keyData)
		{
			std::cout << "WheelDown " << keyData.keyTime << std::endl;
		}

		keyData = platform.GetKey(flt::KeyCode::mouseAbsolutePos);
		if(keyData)
		{
			std::cout << "abs Pos " << keyData.x << " " << keyData.y << std::endl;
		}

		Sleep(10);
	}

	platform.Finalize();
}
