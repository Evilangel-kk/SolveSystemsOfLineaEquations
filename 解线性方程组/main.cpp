#include<iostream>
#include<vector>

#include<Windows.h>
#include <graphics.h>
#include"Calculator.h"
#include"Equation.h"
#include"User.h"
using namespace std;
#define WIDTH 540
#define HIGH 809

IMAGE calculator;
IMAGE flash;


int main()
{
	Calculator cal;
	loadimage(&calculator, "calculator.jpg", WIDTH, HIGH);
	loadimage(&flash, "flash.jpg", 420, 250);
	initgraph(WIDTH, HIGH, EW_SHOWCONSOLE);
	putimage(0, 0, &calculator);

	while (1)
	{
		cal.GetUsersMessage();
	}

	system("pause");
	closegraph();
}