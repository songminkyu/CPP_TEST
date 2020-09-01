#include <iostream>

#include <vector>

#include <type_traits>

//#include <concepts>



template<class T>

struct A {

	A(T&&) { std::cout << typeid(*this).name() << std::endl; } //#1

	// class T�� �Բ� ������� �ʴ� �Ķ���ʹ� forwarding reference�� �ƴϴ�.

	// �� ���� ������ T�� &&�� ������ Ÿ���� ������ ��, forwarding reference�� �ƴϴ�.

};



template<class T>

struct B {

	B(T&&) { std::cout << typeid(*this).name() << std::endl; } //#1�� ����.

};

template<class T> B(T&&)->B<T>; //#2 T&&�� forwarding reference



int main() {

	int i{ 10 };

	//A a1{ i }; // ERROR: A<int>�� �Ǹ� #1 ������ ���� A(T&&)�� rvalue reference�� �ȴ�.

	A a2{ 0 };   // rvalue reference������ ��������. 

	// print: struct A<int> 



	B b1{ i };  // #2���� T�� int&�� �߷��� �� ������ ȣ��. ���� B(T&&)�� B(int&)�� ���

	// print: struct B<int &> 



	B b2{ 0 };  // #2���� T�� int�� �߷��� �� ������ ȣ��. ���� B(T&&)�� B(int&&);

	// print: struct B<int> 

}