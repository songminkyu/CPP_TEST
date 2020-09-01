#include <iostream>

template<class T>					class A {/*.....*/ };
template<class T, class U = T>		class B {/*.....*/ };
template<class ... Types>			class C {/*.....*/ };

template<template<class> class P>	class X{/*....*/ };

/*
C++17���� �޶��� template �ƱԸ�Ʈ�� �ּ� ��Ī�� ����Ѵ�. �������� �ش� �Ծ��� �ı޷��� ����~
*/

int main()
{

	[[maybe_unused]] X<A> xa;
	[[maybe_unused]] X<B> xb;
	[[maybe_unused]] X<C> xc;
}