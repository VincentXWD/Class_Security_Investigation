/*
����ķ���������public�У������ݳ�Ա����protected�б���������
���ַ��������Foo1����ȫ��������ʾx��y�ķ����з��ص���x��y�����á���������ȫ��
�޸�Ϊ����const�ᡰ��ȫ��
*/
#pragma once
#include <iostream>
using namespace std;
class Foo5
{
public:
	Foo5(int xx = 0, int yy = 0) : x(xx), y(yy) {}
	int add() { return x + y; }
	int sub() { return x - y; }
	int &showx() { return x; }
	//����������������ķ�����const int &showx() { return x; }
	//�������Ա�֤�����޷���Ϊ��ֵ��
	int &showy() { return y; }
	void changex(int);
	void changey(int);
private:
	int x;
	int y;
};

void Foo5::changex(int xx) {	//�������ǲ�������x����-1
	if (xx == -1) {
		cout << "x can not be -1 !" << endl;
		return;
	}
	x = xx;
}
void Foo5::changey(int yy) {	//�������ǲ�������x����-1
	if (yy == -1) {
		cout << "y can not be -1 !" << endl;
		return;
	}
	y = yy;
}