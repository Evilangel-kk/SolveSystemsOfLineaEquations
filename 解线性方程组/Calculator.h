#pragma once
#include <graphics.h>
#include"Equation.h"
class Calculator
{
public:
	Equation equation;
	int GetNumber();		//��ȡ����
	void GetUsersMessage();	//��ȡ�û�ʹ����Ϣ
	void OpenMachine();
	void CloseMachine();
	void Menu();
	void InitEquation();
};

