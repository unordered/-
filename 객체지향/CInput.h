#pragma once
#include <stdio.h>
#include <memory.h>
#include <Windows.h>
#include <time.h>
class CInput
{
	SHORT left_state;
	SHORT right_state;
	SHORT up_state;
	SHORT down_state;
	SHORT space_state;
	SHORT enter_state;
public:
	CInput()
	{
		left_state = GetAsyncKeyState(VK_LEFT);
		right_state = GetAsyncKeyState(VK_RIGHT);
		up_state = GetAsyncKeyState(VK_UP);
		down_state = GetAsyncKeyState(VK_DOWN);
		space_state = GetAsyncKeyState(VK_SPACE);
	}
	SHORT PlayerInput()
	{
		enter_state  = GetAsyncKeyState(VK_RETURN);
		left_state = GetAsyncKeyState(VK_LEFT);
		right_state = GetAsyncKeyState(VK_RIGHT);
		up_state = GetAsyncKeyState(VK_UP);
		down_state = GetAsyncKeyState(VK_DOWN);
		space_state = GetAsyncKeyState(VK_SPACE);

		if (0x0001 & up_state || 0x8000 & up_state || 0x8001 & up_state)
		{
			return VK_UP;
		}

		if (0x0001 & down_state || 0x8000 & down_state || 0x8001 & down_state)
		{
			return VK_DOWN;
		}


		if (0x0001 & left_state || 0x8000 & left_state || 0x8001 & left_state)
		{
			return VK_LEFT;
		}

		if (0x0001 & right_state || 0x8000 & right_state || 0x8001 & right_state)
		{
			return VK_RIGHT;
		}

		if (0x0001 & space_state || 0x8000 & space_state || 0x8001 & space_state)
		{
			return VK_SPACE;
		}

		if (0x0001 & enter_state || 0x8000 & enter_state || 0x8001 & enter_state)
		{
			return VK_RETURN;
		}



		return VK_END;
	}
};