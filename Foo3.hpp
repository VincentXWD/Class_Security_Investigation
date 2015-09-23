/*
将类的方法声明在public中，将数据成员放入protected中保护起来。
这种方法相对于Foo1更安全，但是显示x和y的方法中返回的是x和y的值。这样也不安全。
*/
#pragma once
#include <iostream>
using namespace std;
class Foo3
{
public:
	Foo3(int xx = 0, int yy = 0) : x(xx), y(yy) {}
	int add() { return x + y; }
	int sub() { return x - y; }
	int showx() { return x; }
	int showy() { return y; }
	void changex(int);
	void changey(int);
private:
	int x;
	int y;
};

void Foo3::changex(int xx) {	//假设我们不允许让x等于-1
	if (xx == -1) {
		cout << "x can not be -1 !" << endl;
		return;
	}
	x = xx;
}
void Foo3::changey(int yy) {	//假设我们不允许让x等于-1
	if (yy == -1) {
		cout << "y can not be -1 !" << endl;
		return;
	}
	y = yy;
}