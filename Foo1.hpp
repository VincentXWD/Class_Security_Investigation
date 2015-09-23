/*
直接将数据成员和对数据的操作都放在public里，
这样的话既可以通过调用类内的方法对类内数据成员进行类设计者希望的操作，
也可以直接对类内数据成员进行访问和修改，
这是最不安全，但同样也是最方便的一种类的声明的方法。
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

void Foo1::changex(int xx) {	//假设我们不允许让x等于-1
	if (xx == -1) {
		cout << "x can not be -1 !" << endl;
		return;
	}
	x = xx;
}
void Foo1::changey(int yy) {	//假设我们不允许让x等于-1
	if (yy == -1) {
		cout << "y can not be -1 !" << endl;
		return;
	}
	y = yy;
}