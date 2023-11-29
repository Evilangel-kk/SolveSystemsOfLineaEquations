#pragma once

class Equation
{
private:
	int num;					//δ֪������
	int pi[10]={0};				//δ֪��˳������
	long double ci[10][10] = { 0 };	//ϵ������
	long double xi[10]={0};			//δ֪����
	long double bi[10] = { 0 };		//������
public:	
	void SetNumber(int n);		//����δ֪������
	void SetCoefficient();		//����δ֪����ϵ��
	bool Solve();				//��ⷽ��
	int FindMax(int n);			//�ҵ���n��������Ԫ��
	void Exchange(int m,int n);	//��������
	void Elimination(int i);	//��Ԫ����
	void Inverse();				//�ش�����
	void RightAnswer();			//������
	void WrongAnswer();			//�����޽��������
	long double GetNumber();	//��ȡ����
	void Print();				//����������
};

