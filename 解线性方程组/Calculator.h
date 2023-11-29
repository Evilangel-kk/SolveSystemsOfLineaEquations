#pragma once
#include <graphics.h>
#include"Equation.h"
class Calculator
{
public:
	Equation equation;
	int GetNumber();		//获取数字
	void GetUsersMessage();	//获取用户使用信息
	void OpenMachine();
	void CloseMachine();
	void Menu();
	void InitEquation();
};

