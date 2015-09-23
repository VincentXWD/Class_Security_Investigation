#include <iostream>
#include "Foo1.hpp"
#include "Foo2.hpp"
#include "Foo3.hpp"
#include "Foo4.hpp"
#include "Foo5.hpp"

using namespace std;

void Foo1oper() {
	Foo1 foo1(2, 6);
	cout << "Original" << endl;
	cout << foo1.x << " + " << foo1.y << " = " << foo1.add() << endl;
	cout << foo1.x << " - " << foo1.y << " = " << foo1.sub() << endl;
	foo1.x = -1;
	foo1.y = -1;	//可以不按照类设计好的方法，强行修改值为-1
	cout << "Change something." << endl;
	cout << foo1.x << " + " << foo1.y << " = " << foo1.add() << endl;
	cout << foo1.x << " - " << foo1.y << " = " << foo1.sub() << endl;
}

void Foo2oper() {
	Foo2 foo2(2, 6);
	Foo2 *ptr = &foo2;
	cout << "x = " << foo2.showx() << " y = " << foo2.showy() << endl;
	foo2.showx() = -1;//可以通过对foo2.showx()的返回值赋值来修改函数成员。
	cout << "x = " << foo2.showx() << " y = " << foo2.showy() << endl;
	//因此我们得出一个结论：不要让成员函数返回一个非常引用（指针）。
}

void Foo3oper() {
	Foo3 foo3(2, 6);
	cout << "x = " << foo3.showx() << " y = " << foo3.showy() << endl;
	Foo3 *ptr = &foo3;	//获取foo3的地址
	//ptr->x = -1;		//不能直接修改
	decltype(foo3.showx()) *px = (decltype(foo3.showx())*)ptr;//获取参数类型
	*px = -1;
	cout << "x = " << foo3.showx() << " y = " << foo3.showy() << endl;
	px += 1;	//获取Foo3的第一个数据的短长	，并且让px跳到下一个数据成员
	*px = -1;	//修改下一个数据成员
	cout << "x = " << foo3.showx() << " y = " << foo3.showy() << endl;

}

void Foo4oper() {
	Foo3 foo4(2, 6.0);
	cout << "x = " << foo4.showx() << " y = " << foo4.showy() << endl;
	Foo3 *ptr = &foo4;	//获取foo4的地址
	decltype(foo4.showx()) *px = (decltype(foo4.showx())*)ptr;//获取参数类型
	*px = -1;
	cout << "x = " << foo4.showx() << " y = " << foo4.showy() << endl;
	decltype(foo4.showy()) *py = (decltype(foo4.showy())*)(px + 1);
	*py = -1;	//修改下一个数据成员
	cout << "x = " << foo4.showx() << " y = " << foo4.showy() << endl;
}

void Foo5oper() {
	Foo5 foo5(2, 6);
	cout << "x = " << foo5.showx() << " y = " << foo5.showy() << endl;
	Foo5 *ptr = &foo5;
	cout << "x = " << foo5.showx() << " y = " << foo5.showy() << endl;
	decltype(foo5.showx()) px = (decltype(foo5.showx()))ptr;
	px = -1;
}

int main() {
	//Foo1oper();
	//Foo2oper();
	//Foo3oper();
	//Foo4oper();
	Foo5oper();
}
