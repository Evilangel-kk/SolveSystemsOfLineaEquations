#pragma once

class Equation
{
private:
	int num;					//未知数个数
	int pi[10]={0};				//未知数顺序序列
	long double ci[10][10] = { 0 };	//系数矩阵
	long double xi[10]={0};			//未知数答案
	long double bi[10] = { 0 };		//常数列
public:	
	void SetNumber(int n);		//设置未知数个数
	void SetCoefficient();		//设置未知数的系数
	bool Solve();				//求解方程
	int FindMax(int n);			//找到第n列中最大的元素
	void Exchange(int m,int n);	//交换两行
	void Elimination(int i);	//消元过程
	void Inverse();				//回代过程
	void RightAnswer();			//输出结果
	void WrongAnswer();			//报错：无解或无数解
	long double GetNumber();	//获取数字
	void Print();				//检查增广矩阵
};

