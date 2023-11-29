#include "Calculator.h"
#include<Windows.h>
#include <conio.h>
#include <corecrt_math.h>
#include <stdio.h>
#include <string>
using namespace std;

void Calculator::GetUsersMessage()
{
	int flag = 0;
	MOUSEMSG mouse;
	while (1)
	{
		mouse = GetMouseMsg();
		if (mouse.uMsg == WM_LBUTTONDOWN)
		{
			if (mouse.x > 417 && mouse.y > 394 && mouse.x < 467 && mouse.y < 435)
			{
				if (flag == 0)
				{
					OpenMachine();
					flag = 1;
				}
				else
				{
					CloseMachine();
					flag = 0;
					break;
				}
			}
			else if (mouse.x > 294 && mouse.y > 390 && mouse.x < 385 && mouse.y < 443)
			{
				Menu();
			}
		}
	}
}

void Calculator::OpenMachine()
{
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);//去掉文字背景
	settextstyle(55, 0, _T("宋体"));
	outtextxy(185, 100, _T("凯茨潘"));
	settextstyle(55, 0, _T("微软雅黑"));
	outtextxy(165, 150, _T("KAICEPAN"));
	settextstyle(55, 0, _T("宋体"));
	outtextxy(160, 200, _T("欢迎回来"));
	Sleep(1000);
	IMAGE background;
	loadimage(&background, "flash.jpg", 472-66,298-55);
	putimage(66, 55, &background);
}

void Calculator::CloseMachine()
{
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);//去掉文字背景
	settextstyle(55, 0, _T("宋体"));
	outtextxy(185, 100, _T("凯茨潘"));
	settextstyle(55, 0, _T("微软雅黑"));
	outtextxy(165, 150, _T("KAICEPAN"));
	settextstyle(55, 0, _T("宋体"));
	outtextxy(160, 200, _T("感谢使用"));
	Sleep(1000);
	IMAGE background;
	loadimage(&background, "flash.jpg", 472 - 66, 298 - 55);
	putimage(66, 55, &background);
}

void Calculator::Menu()
{
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);//去掉文字背景
	settextstyle(35, 0, _T("宋体"));
	outtextxy(70, 60, _T("1:解线性方程组"));
	
	MOUSEMSG mouse;
	while (1)
	{
		mouse = GetMouseMsg();
		if (mouse.uMsg == WM_LBUTTONDOWN)
		{
			if (mouse.x > 60 && mouse.y > 624 && mouse.x < 144 && mouse.y < 672)
			{
				InitEquation();
			}
		}
	}
}

void Calculator::InitEquation()
{
	IMAGE background;
	IMAGE kongge;
	loadimage(&background, "flash.jpg", 472 - 66, 298 - 55);
	loadimage(&kongge, "flash.jpg", 35, 35);
	putimage(66, 55, &background);
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);//去掉文字背景
	settextstyle(35, 0, _T("宋体"));
	outtextxy(70, 60, _T("未知数个数(2～9)："));
	int number = 0;
	MOUSEMSG mouse;
	while (1)
	{
		mouse = GetMouseMsg();
		if (mouse.uMsg == WM_LBUTTONDOWN)
		{
			if (mouse.x > 173 && mouse.y > 624 && mouse.x < 257 && mouse.y < 672)
			{
				number = 2;
				outtextxy(380, 60, _T("2"));
			}
			else if (mouse.x > 286 && mouse.y > 624 && mouse.x < 370 && mouse.y < 672)
			{
				number = 3;
				outtextxy(380, 60, _T("3"));
			}
			else if (mouse.x > 60 && mouse.y > 551 && mouse.x < 144 && mouse.y < 599)
			{
				number = 4;
				outtextxy(380, 60, _T("4"));
			}
			else if (mouse.x > 173 && mouse.y > 551 && mouse.x < 257 && mouse.y < 599)
			{
				number = 5;
				outtextxy(380, 60, _T("5"));
			}
			else if (mouse.x > 286 && mouse.y > 551 && mouse.x < 370 && mouse.y < 599)
			{
				number = 6;
				outtextxy(380, 60, _T("6"));
			}
			else if (mouse.x > 60 && mouse.y > 478 && mouse.x < 144 && mouse.y < 525)
			{
				number = 7;
				outtextxy(380, 60, _T("7"));
			}
			else if (mouse.x > 173 && mouse.y > 478 && mouse.x < 257 && mouse.y < 525)
			{
				number = 8;
				outtextxy(380, 60, _T("8"));
			}
			else if (mouse.x > 286 && mouse.y > 478 && mouse.x < 370 && mouse.y < 525)
			{
				number = 9;
				outtextxy(380, 60, _T("9"));
			}
			else if ((mouse.x > 60 && mouse.y > 389 && mouse.x < 152 && mouse.y < 442)||(mouse.x > 176 && mouse.y > 390 && mouse.x < 268 && mouse.y < 442))
			{
				number = 0;
				putimage(380, 60, &kongge);
			}
			else if (mouse.x > 286 && mouse.y > 698 && mouse.x < 370 && mouse.y < 745)
			{
				if (number != 0)
				{
					break;
				}
			}
		}
	}
	equation.SetNumber(number);
	equation.SetCoefficient();
	bool flag = equation.Solve();
	equation.Print();
	if (flag == false)
	{
		equation.WrongAnswer();
	}
	else
	{
		equation.RightAnswer();
	}
}

