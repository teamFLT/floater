#pragma once
#include "KeyCode.h"
#include "Platform.h"
#include "Vector2f.h"

namespace flt
{
	namespace engine
	{
		class Input
		{
		public:
			enum class State {
				pressed,
				released,
				pressing,
				none
			};

		public:
			bool Initialize(Platform* g_pPlatform);
			bool Update();
			static KeyData GetKey(KeyCode code);//키가 눌려진 동안 true를 반환하는 함수
			static KeyData GetKeyDown(KeyCode code);//키가 눌렸을때 true를 반환하는 함수
			static KeyData GetKeyUp(KeyCode code);//키가 떼어졌을때 true를 반환하는 함수
			static State GetKeyState(KeyCode code);//키의 상태를 반환하는 함수
			static KeyData GetMouseButton(int mouseBtn);//마우스가 눌려진 동안 true를 반환하는 함수
			static KeyData GetMouseButtonDown(int mouseBtn);//마우스가 눌렸을때 true를 반환하는 함수
			static KeyData GetMouseButtonUp(int mouseBtn);//마우스가 떼어졌을때 true를 반환하는 함수
			static Vector2f GetMousePosition();//마우스의 좌표를 반환하는 함수

		private:
			static Vector2f g_previousMousePosition;
			static Platform* g_pPlatform;
			static State g_keyState[135];//현재 키의 상태를 반환하는 변수
			static KeyCode g_mouseMap[7];
		};
	}
}
