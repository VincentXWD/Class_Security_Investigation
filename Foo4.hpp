/*
数据成员类型不一样？不一样也同样会获取地址。
即使是const也被修改了。
*/
#pragma once
#include <iostream>
using namespace std;
class Foo4
{
public:
	Foo4(int xx = 0, double yy = 0) : x(xx), y(yy) {}
	double add() { return x + y; }
	double sub() { return x - y; }
	const int showx() const{ return x; }
	const double showy() { return y; }
	void changex(int);
	void changey(double);
private:
	int x;
	double y;
};

void Foo4::changex(int xx) {	//假设我们不允许让x等于-1
	if (xx == -1) {
		cout << "x can not be -1 !" << endl;
		return;
	}
	x = xx;
}
void Foo4::changey(double yy) {	//假设我们不允许让x等于-1
	if (yy == -1) {
		cout << "y can not be -1 !" << endl;
		return;
	}
	y = yy;
}