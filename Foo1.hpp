/*
ֱ�ӽ����ݳ�Ա�Ͷ����ݵĲ���������public�
�����Ļ��ȿ���ͨ���������ڵķ������������ݳ�Ա�����������ϣ���Ĳ�����
Ҳ����ֱ�Ӷ��������ݳ�Ա���з��ʺ��޸ģ�
�������ȫ����ͬ��Ҳ������һ����������ķ�����
*/
#pragma once
#include <iostream>
using namespace std;
class Foo1
{
public:
	Foo1(int xx = 0, int yy = 0) : x(xx), y(yy) {}
	int add() { return x + y; }
	int sub() { return x - y; }
	void changex(int);
	void changey(int);
	int x;
	int y;
};

void Foo1::changex(int xx) {	//�������ǲ�������x����-1
	if (xx == -1) {
		cout << "x can not be -1 !" << endl;
		return;
	}
	x = xx;
}
void Foo1::changey(int yy) {	//�������ǲ�������x����-1
	if (yy == -1) {
		cout << "y can not be -1 !" << endl;
		return;
	}
	y = yy;
}