#include "Equation.h"
#include"Calculator.h"
#include"User.h"
#include <stdio.h>

void Equation::SetNumber(int n)
{
	this->num = n;
}

void Equation::SetCoefficient()
{
	IMAGE background;
	loadimage(&background, "flash.jpg", 472 - 66, 298 - 55);
	putimage(66, 55, &background);
	IMAGE kongge;
	loadimage(&kongge, "flash.jpg", 15, 35);
	IMAGE flash;
	loadimage(&flash, "flash.jpg", 250, 35);
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);//去掉文字背景
	settextstyle(25, 0, _T("宋体"));
	outtextxy(70, 60, _T("设置系数"));
	outtextxy(70, 100, _T("第  个方程")); 
	char x[5] = { '\0' };
	char y[5] = { '\0' };
	char z[10] = { '\0' };
	char w[5] = { '\0' };
	for (int i = 0; i < this->num; i++)
	{
		putimage(70, 130, &flash);
		putimage(105, 130, &kongge);
		putimage(105, 100, &kongge);
		sprintf(x, "%d", i+1);
		outtextxy(105, 100, x);
		outtextxy(70, 130, _T("第  个未知数的系数:"));
		for (int j = 0; j < this->num; j++)
		{
			sprintf(y, "%d", j + 1);
			outtextxy(105, 130, y);
			ci[i][j] = GetNumber();
			if (j == 0)
			{
				sprintf(z, " %.0lfx%d", ci[i][j], j + 1);
			}
			else
			{
				sprintf(z, "+%.0lfx%d", ci[i][j], j + 1);
			}
			
			outtextxy(65 + j * 55, 165 + i * 30, z);
			putimage(105, 130, &kongge);
		}
		putimage(70, 130, &flash);
		outtextxy(70, 130, _T("第  个方程右侧常数:"));
		outtextxy(105, 130, x);
		bi[i] = GetNumber();
		sprintf(w, "=%.0lf", bi[i]);
		outtextxy(260, 165 + i * 30, w);
	}
	Sleep(1000);
}

bool Equation::Solve()
{
	IMAGE background;
	loadimage(&background, "flash.jpg", 472 - 66, 298 - 55);
	putimage(66, 55, &background);
	for (int i = 0; i < this->num; i++)
	{
		int flag = 0;
		flag = FindMax(i);
		if (flag != i && flag != -1)
		{
			Exchange(flag, i);
		}
		else if (flag == -1)
		{
			return false;
		}
		Elimination(i);
	}
	Inverse();
	return true;
}

int Equation::FindMax(int n)
{
	long double max = ci[n][0];
	int sign = 0;
	for (int i = 1; i < this->num; i++)
	{
		if (ci[i][n] > max)
		{
			max = ci[i][n];
			sign = i;
		}
	}
	if (max == 0 || ci[this->num-1][this->num-1]==0)
	{
		return -1;
	}
	return sign;
}

void Equation::Exchange(int m, int n)
{
	long double tmp = 0;
	long double tb = 0;
	for (int i = 0; i < this->num; i++)
	{
		tmp = ci[n][i];
		ci[n][i] = ci[m][i];
		ci[m][i] = tmp;
	}
	tb = bi[m];
	bi[m] = bi[n];
	bi[n] = tb;
}

void Equation::Elimination(int i)
{
	long double m = 0.0;
	for (int j = i + 1; j < this->num; j++)
	{
		m = ci[j][i] / ci[i][i];
		ci[j][i] = 0;
		for (int k = i + 1; k < this->num; k++)
		{
			ci[j][k] -= (m * ci[i][k]);
		}
		bi[j] -= (m * bi[i]);
	}
}

void Equation::Inverse()
{
	for (int i = this->num - 1; i >= 0; i--)
	{
		for (int j = this->num - 1; j > i; j--)
		{
			bi[i] -= (ci[i][j] * xi[j]);
		}
		xi[i] = bi[i] / ci[i][i];
	}
}

void Equation::RightAnswer()
{
	IMAGE background;
	loadimage(&background, "flash.jpg", 472 - 66, 298 - 55);
	putimage(66, 55, &background);
	setbkmode(TRANSPARENT);//去掉文字背景
	settextstyle(25, 0, _T("宋体"));
	for (int i = 1; i <= this->num; i++)
	{
		char awe[20] = { '\0' };
		if (xi[i - 1] > 0)
		{
			sprintf(awe, "X%d = %f", i, xi[i - 1]);
		}
		else
		{
			sprintf(awe, "X%d =%f", i, xi[i - 1]);
		}
		if (i <= 5)
		{
			outtextxy(70, 70 + (i - 1) * 40, awe);
		}
		else
		{
			outtextxy(270, 70 + (i - 1) * 40, awe);
		}
	}
}

void Equation::WrongAnswer()
{
	IMAGE background;
	loadimage(&background, "flash.jpg", 472 - 66, 298 - 55);
	putimage(66, 55, &background);
	setbkmode(TRANSPARENT);//去掉文字背景
	settextstyle(25, 0, _T("宋体"));
	outtextxy(100, 130, _T("该方程组没有唯一解"));
}

long double Equation::GetNumber()
{
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);//去掉文字背景
	settextstyle(25, 0, _T("宋体"));
	IMAGE kongge;
	loadimage(&kongge, "flash.jpg", 35, 35);
	IMAGE flash;
	loadimage(&flash, "flash.jpg", 100, 35);
	long double c = 0;
	int fh = 1;
	MOUSEMSG mouse;
	int n = 0;
	int x = 0;
	while (1)
	{
		mouse = GetMouseMsg();
		if (mouse.uMsg == WM_LBUTTONDOWN)
		{
			if (mouse.x > 286 && mouse.y > 698 && mouse.x < 370 && mouse.y < 745)
			{
				if (x != 0)
				{
					printf_s("=\n");
					break;
				}
			}
			else if (mouse.x > 173 && mouse.y > 698 && mouse.x < 257 && mouse.y < 745)
			{
				printf_s("0\n");
				c = c * 10 + 0;
				outtextxy(320 + x * 15, 130, _T("0"));
				x++;
				n++;
			}
			else if (mouse.x > 60 && mouse.y > 624 && mouse.x < 144 && mouse.y < 672)
			{
				printf_s("1\n");
				c = c * 10 + 1;
				outtextxy(320 + x * 15, 130, _T("1"));
				x++;
				n++;
			}
			else if (mouse.x > 173 && mouse.y > 624 && mouse.x < 257 && mouse.y < 672)
			{
				printf_s("2\n");
				c = c * 10 + 2;
				outtextxy(320 + x * 15, 130, _T("2"));
				x++;
				n++;

			}
			else if (mouse.x > 286 && mouse.y > 624 && mouse.x < 370 && mouse.y < 672)
			{
				printf_s("3\n");
				c = c * 10 + 3;
				outtextxy(320 + x * 15, 130, _T("3"));
				x++;
				n++;
			}
			else if (mouse.x > 60 && mouse.y > 551 && mouse.x < 144 && mouse.y < 599)
			{
				printf_s("4\n");
				c = c * 10 + 4;
				outtextxy(320 + x * 15, 130, _T("4"));
				x++;
				n++;
			}
			else if (mouse.x > 173 && mouse.y > 551 && mouse.x < 257 && mouse.y < 599)
			{
				printf_s("5\n");
				c = c * 10 + 5;
				outtextxy(320 + x * 15, 130, _T("5"));
				x++;
				n++;
			}
			else if (mouse.x > 286 && mouse.y > 551 && mouse.x < 370 && mouse.y < 599)
			{
				printf_s("6\n");
				c = c * 10 + 6;
				outtextxy(320 + x * 15, 130, _T("6"));
				x++;
				n++;
			}
			else if (mouse.x > 60 && mouse.y > 478 && mouse.x < 144 && mouse.y < 525)
			{
				printf_s("7\n");
				c = c * 10 + 7;
				outtextxy(320 + x * 15, 130, _T("7"));
				x++;
				n++;
			}
			else if (mouse.x > 173 && mouse.y > 478 && mouse.x < 257 && mouse.y < 525)
			{
				printf_s("8\n");
				c = c * 10 + 8;
				outtextxy(320 + x * 15, 130, _T("8"));
				x++;
				n++;
			}
			else if (mouse.x > 286 && mouse.y > 478 && mouse.x < 370 && mouse.y < 525)
			{
				printf_s("9\n");
				c = c * 10 + 9;
				outtextxy(320 + x * 15, 130, _T("9"));
				x++;
				n++;
			}
			else if (mouse.x > 395 && mouse.y > 551 && mouse.x < 480 && mouse.y < 599)
			{
				printf_s("-\n");
				if (x == 0)
				{
					outtextxy(320 + x * 15, 130, _T("-"));
					x++;
					fh = -1;
				}
			}
			else if (mouse.x > 60 && mouse.y > 389 && mouse.x < 152 && mouse.y < 442)
			{
				if (c != 0)
				{
					c /= 10;
					printf_s("%f\n", c);
					x--;
					putimage(320 + x * 15, 130, &kongge);
				}
			}
			else if (mouse.x > 176 && mouse.y > 390 && mouse.x < 268 && mouse.y < 442)
			{
				c = 0;
				n = 0;
				fh = 1;
				putimage(320, 130, &flash);
				x = 0;
			}
		}
	}
	c *= fh;
	putimage(320, 130, &flash);
	return c;
}

void Equation::Print()
{
	for (int i = 0; i < this->num; i++)
	{
		printf("%d:", i+1);
		for (int j = 0; j < this->num; j++)
		{
			printf("\t%.64lf\n", this->ci[i][j]);
		}
		printf("\t=%.64lf\n\n",bi[i]);
	}
}
