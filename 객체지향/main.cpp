#include <stdio.h>
#include <memory.h>
#include <Windows.h>
#include <list>
#include <time.h>
#include "Console.h"
#include "CScreenBuffer.h"




CScreenBuffer ScreenBuffer;

struct Boss
{
	int x_pos;
	int y_pos;
};

struct Ball
{
	int x_pos;
	int y_pos;
	int x_velocity;
	int y_velocity;
	int life;
};


Boss boss;

int g_iX = 0;

int tempmain(void)
{
	cs_Initial();
	ScreenBuffer.Buffer_Clear();

	srand((unsigned int)time(NULL));

	std::list<Ball>* ball_list = new std::list<Ball>();

	//--------------------------------------------------------------------
	// 게임의 메인 루프
	// 이 루프가  1번 돌면 1프레임 이다.
	//--------------------------------------------------------------------
	int iX = 0;

	int c_xpos = 11;
	int c_ypos = 10;
	boss.x_pos = 20;
	boss.y_pos = 10;
	// 


	// 공 관리


	int move_frame = 0;
	int ball_frame = 0;
	int ball_launch = 29;
	while (1)
	{

		iX++;

		// 스크린 버퍼를 지움
		ScreenBuffer.Buffer_Clear();
		SHORT left_state = GetAsyncKeyState(VK_LEFT);
		SHORT right_state = GetAsyncKeyState(VK_RIGHT);
		SHORT up_state = GetAsyncKeyState(VK_UP);
		SHORT down_state = GetAsyncKeyState(VK_DOWN);
		SHORT space_state = GetAsyncKeyState(VK_SPACE);

		if (0x0001 & up_state || 0x8000 & up_state || 0x8001 & up_state)
		{
			c_ypos--;
		}

		if (0x0001 & down_state || 0x8000 & down_state || 0x8001 & down_state)
		{
			c_ypos++;
		}


		if (0x0001 & left_state || 0x8000 & left_state || 0x8001 & left_state)
		{
			c_xpos--;
		}

		if (0x0001 & right_state || 0x8000 & right_state || 0x8001 & right_state)
		{
			c_xpos++;
		}


		if (0x0001 & space_state || 0x8000 & space_state || 0x8001 & space_state || ball_launch < ball_frame)
		{
			//(rand()% dfSCREEN_WIDTH - 4)+1;
			Ball b;

			// 공의 방향 정하기
			int x_difference = boss.x_pos - c_xpos;
			int y_difference = boss.y_pos - c_ypos;
			if (x_difference < 0 && y_difference == 0)
			{
				// (1,0)
				b.x_velocity = 1;
				b.y_velocity = 0;
			}
			else if (x_difference > 0 && y_difference < 0)
			{
				// (1,-1)
				b.x_velocity = -1;
				b.y_velocity = 1;
			}
			else if (x_difference == 0 && y_difference < 0)
			{
				// (0,1)
				b.x_velocity = 0;
				b.y_velocity = 1;

			}
			else if (x_difference < 0 && y_difference < 0)
			{
				b.x_velocity = 1;
				b.y_velocity = 1;
			}
			else if (x_difference > 0 && y_difference == 0)
			{
				b.x_velocity = -1;
				b.y_velocity = 0;
			}
			else if (x_difference < 0 && y_difference > 0)
			{
				b.x_velocity = 1;
				b.y_velocity = -1;
			}
			else if (x_difference == 0 && y_difference > 0)
			{
				b.x_velocity = 0;
				b.y_velocity = -1;
			}
			else if (x_difference > 0 || y_difference > 0)
			{
				b.x_velocity = -1;
				b.y_velocity = -1;
			}


			b.x_pos = boss.x_pos;
			b.y_pos = boss.y_pos;

			b.life = 2;
			ball_list->push_back(b);
		}

		if (ball_frame == 30)
		{
			ball_frame = 0;
		}
		ball_frame++;
		move_frame++;
		// 몬스터의 방향 정하기
		if (move_frame == 5)
		{

			int x_difference = boss.x_pos - c_xpos;
			int y_difference = boss.y_pos - c_ypos;
			if (x_difference < 0 && y_difference == 0)
			{
				// (1,0)
				boss.x_pos += 1;
				boss.y_pos += 0;
			}
			else if (x_difference > 0 && y_difference < 0)
			{
				// (1,-1)
				boss.x_pos += -1;
				boss.y_pos += 1;
			}
			else if (x_difference == 0 && y_difference < 0)
			{
				// (0,1)
				boss.x_pos += 0;
				boss.y_pos += 1;

			}
			else if (x_difference < 0 && y_difference < 0)
			{
				boss.x_pos += 1;
				boss.y_pos += 1;
			}
			else if (x_difference > 0 && y_difference == 0)
			{
				boss.x_pos += -1;
				boss.y_pos += 0;
			}
			else if (x_difference < 0 && y_difference > 0)
			{
				boss.x_pos += 1;
				boss.y_pos += -1;
			}
			else if (x_difference == 0 && y_difference > 0)
			{
				boss.x_pos += 0;
				boss.y_pos += -1;
			}
			else if (x_difference > 0 || y_difference > 0)
			{
				boss.x_pos += -1;
				boss.y_pos += -1;
			}

			move_frame = 0;
		}

		if (c_xpos <= 0)
		{
			c_xpos = 1;
		}
		else if (c_xpos >= dfSCREEN_WIDTH - 3)
		{
			c_xpos = dfSCREEN_WIDTH - 3;
		}

		if (c_ypos <= 0)
		{
			c_ypos = 1;
		}
		else if (c_ypos >= dfSCREEN_HEIGHT - 2)
		{
			c_ypos = dfSCREEN_HEIGHT - 2;
		}




		std::list<Ball>::iterator iter;
		for (iter = ball_list->begin(); iter != ball_list->end(); ) {
			(*iter).x_pos += (*iter).x_velocity;
			(*iter).y_pos += (*iter).y_velocity;

			if ((*iter).x_pos <= 0)
			{
				(*iter).x_pos = 1;
				(*iter).x_velocity *= -1;
				(*iter).life--;
			}
			else if ((*iter).x_pos >= dfSCREEN_WIDTH - 3)
			{
				(*iter).x_pos = dfSCREEN_WIDTH - 3;
				(*iter).x_velocity *= -1;
				(*iter).life--;
			}

			if ((*iter).y_pos <= 0)
			{
				(*iter).y_pos = 1;
				(*iter).y_velocity *= -1;
				(*iter).life--;
			}
			else if ((*iter).y_pos >= dfSCREEN_HEIGHT - 2)
			{
				(*iter).y_pos = dfSCREEN_HEIGHT - 2;
				(*iter).y_velocity *= -1;
				(*iter).life--;
			}

			if ((*iter).life == 0)
			{
				iter = ball_list->erase(iter);
			}
			else
			{
				iter++;
			}
		}



		// 몬스터 출력

		ScreenBuffer.Sprite_Draw(boss.x_pos - 1, boss.y_pos, '@');
		ScreenBuffer.Sprite_Draw(boss.x_pos + 1, boss.y_pos, '@');
		ScreenBuffer.Sprite_Draw(boss.x_pos, boss.y_pos, '#');
		ScreenBuffer.Sprite_Draw(boss.x_pos, boss.y_pos - 1, '@');
		ScreenBuffer.Sprite_Draw(boss.x_pos, boss.y_pos + 1, '@');






		// 스크린 버퍼에 스프라이트 출력
		ScreenBuffer.Sprite_Draw(c_xpos, c_ypos, 'O');

		for (iter = ball_list->begin(); iter != ball_list->end(); iter++)
		{
			ScreenBuffer.Sprite_Draw((*iter).x_pos, (*iter).y_pos, '+');

		}



		for (int i = 0; i < dfSCREEN_WIDTH; i++)
		{
			ScreenBuffer.Sprite_Draw(i, 0, '*');

		}

		for (int i = 1; i < dfSCREEN_HEIGHT; i++)
		{
			ScreenBuffer.Sprite_Draw(0, i, '*');

		}

		for (int i = 1; i <= dfSCREEN_HEIGHT; i++)
		{
			ScreenBuffer.Sprite_Draw(dfSCREEN_WIDTH - 2, i, '*');

		}

		for (int i = 0; i < dfSCREEN_WIDTH; i++)
		{
			ScreenBuffer.Sprite_Draw(i, dfSCREEN_HEIGHT - 1, '*');

		}


		// 스크린 버퍼를 화면으로 출력
		ScreenBuffer.Flip();
		// 프레임 맞추기용 대기 10 Frame
		Sleep(100);
	}

	return 0;
}






