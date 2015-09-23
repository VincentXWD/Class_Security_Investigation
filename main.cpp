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
	foo1.y = -1;	//���Բ���������ƺõķ�����ǿ���޸�ֵΪ-1
	cout << "Change something." << endl;
	cout << foo1.x << " + " << foo1.y << " = " << foo1.add() << endl;
	cout << foo1.x << " - " << foo1.y << " = " << foo1.sub() << endl;
}

void Foo2oper() {
	Foo2 foo2(2, 6);
	Foo2 *ptr = &foo2;
	cout << "x = " << foo2.showx() << " y = " << foo2.showy() << endl;
	foo2.showx() = -1;//����ͨ����foo2.showx()�ķ���ֵ��ֵ���޸ĺ�����Ա��
	cout << "x = " << foo2.showx() << " y = " << foo2.showy() << endl;
	//������ǵó�һ�����ۣ���Ҫ�ó�Ա��������һ���ǳ����ã�ָ�룩��
}

void Foo3oper() {
	Foo3 foo3(2, 6);
	cout << "x = " << foo3.showx() << " y = " << foo3.showy() << endl;
	Foo3 *ptr = &foo3;	//��ȡfoo3�ĵ�ַ
	//ptr->x = -1;		//����ֱ���޸�
	decltype(foo3.showx()) *px = (decltype(foo3.showx())*)ptr;//��ȡ��������
	*px = -1;
	cout << "x = " << foo3.showx() << " y = " << foo3.showy() << endl;
	px += 1;	//��ȡFoo3�ĵ�һ�����ݵĶ̳�	��������px������һ�����ݳ�Ա
	*px = -1;	//�޸���һ�����ݳ�Ա
	cout << "x = " << foo3.showx() << " y = " << foo3.showy() << endl;

}

void Foo4oper() {
	Foo3 foo4(2, 6.0);
	cout << "x = " << foo4.showx() << " y = " << foo4.showy() << endl;
	Foo3 *ptr = &foo4;	//��ȡfoo4�ĵ�ַ
	decltype(foo4.showx()) *px = (decltype(foo4.showx())*)ptr;//��ȡ��������
	*px = -1;
	cout << "x = " << foo4.showx() << " y = " << foo4.showy() << endl;
	decltype(foo4.showy()) *py = (decltype(foo4.showy())*)(px + 1);
	*py = -1;	//�޸���һ�����ݳ�Ա
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
