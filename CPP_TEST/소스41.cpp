#include <iostream>
#include <string>
#include <concepts>

template<typename T, typename U>
concept CS = sizeof(T) > sizeof(U);

template <CS<char>...Ts>
struct S5 {

};

/*
CS<char>...Ts��
 ( CS<Ts,char>&&...) �� folding �ȴ�.
 ���� char ���� ū ����� ���� 
 type-parameter�� ���� �� �ִ�.
*/

int main() {
	S5<int, double, short> a; // ok
	S5<char,int> b;          //error
}