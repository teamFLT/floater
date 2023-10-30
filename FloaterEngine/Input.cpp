#include "Input.h"

#include "Platform.h"


flt::Platform* flt::engine::Input::g_pPlatform;
flt::Vector2f flt::engine::Input::g_previousMousePosition;
flt::engine::Input::State flt::engine::Input::g_keyState[135] = {
	flt::engine::Input::State::none,
};
flt::KeyCode flt::engine::Input::g_mouseMap[7] = {
		KeyCode::mouseLButton,
		KeyCode::mouseRButton,
		KeyCode::mouseMButton,
		KeyCode::mouseMup,
		KeyCode::mouseMdown,
		KeyCode::mouseButton3,
		KeyCode::mouseButton4
};

bool flt::engine::Input::Initialize(Platform* platform)
{
	g_pPlatform = platform;
	return true;
}

bool flt::engine::Input::Update()
{
	for (int i = 0; i < 135; i++)
	{
		flt::KeyData keydata = g_pPlatform->GetKey(static_cast<KeyCode>(i));
		if(keydata && g_keyState[i] == State::none)
		{
			g_keyState[i] = State::pressed;
		}
		else if (keydata && g_keyState[i] == State::pressed)
		{
			g_keyState[i] = State::pressing;
		}
		else if (!keydata && g_keyState[i] == State::pressing)
		{
			g_keyState[i] = State::released;
		}
		else if (!keydata && g_keyState[i] == State::released)
		{
			g_keyState[i] = State::none;
		}
	}
	return true;
}

flt::KeyData flt::engine::Input::GetKey(KeyCode code)
{
	flt::KeyData keydata = g_pPlatform->GetKey(code);
	if(keydata && g_keyState[static_cast<int>(code)]==State::pressing)
	{
		return keydata;
	}
	return keydata;
}

flt::KeyData flt::engine::Input::GetKeyDown(KeyCode code)
{
	flt::KeyData keydata = g_pPlatform->GetKey(code);
	if (keydata && g_keyState[static_cast<int>(code)] == State::pressed)
	{
		return keydata;
	}
	return keydata;
}

flt::KeyData flt::engine::Input::GetKeyUp(KeyCode code)
{
	flt::KeyData keydata = g_pPlatform->GetKey(code);
	if (keydata && g_keyState[static_cast<int>(code)] == State::released)
	{
		return keydata;
	}

	return keydata;
}

flt::engine::Input::State flt::engine::Input::GetKeyState(KeyCode code)
{
	return g_keyState[static_cast<int>(code)];
}

flt::KeyData flt::engine::Input::GetMouseButton(int mouseBtn)
{
	flt::KeyData keydata = g_pPlatform->GetKey(g_mouseMap[mouseBtn]);
	if (keydata && g_keyState[static_cast<int>(g_mouseMap[mouseBtn])] == State::pressing)
	{
		return keydata;
	}

	return keydata;
}

flt::KeyData flt::engine::Input::GetMouseButtonDown(int mouseBtn)
{
	flt::KeyData keydata = g_pPlatform->GetKey(g_mouseMap[mouseBtn]);
	if (keydata && g_keyState[static_cast<int>(g_mouseMap[mouseBtn])] == State::pressed)
	{
		return keydata;
	}

	return keydata;
}

flt::KeyData flt::engine::Input::GetMouseButtonUp(int mouseBtn)
{
	flt::KeyData keydata = g_pPlatform->GetKey(g_mouseMap[mouseBtn]);
	if (keydata && g_keyState[static_cast<int>(g_mouseMap[mouseBtn])] == State::released)
	{
		return keydata;
	}

	return keydata;
}

flt::Vector2f flt::engine::Input::GetMousePosition()
{
	flt::KeyData keydata = g_pPlatform->GetKey(KeyCode::mouseAbsolutePos);
	if(keydata)
	{
		g_previousMousePosition = Vector2f(keydata.x, keydata.y);
		return g_previousMousePosition;
	}
	else
	{
		return g_previousMousePosition;
	}

}
