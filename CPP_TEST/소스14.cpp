#include <iostream>

int i = 100;
struct A {
private : 
	inline static int i = 500;
public:
	void test(int p = i) { // i�� ���� ������ ? test�� ���� ���Ѱ� ����.
		std::cout << p << std::endl;
	}

};

int main()
{
	A a;
	a.test();
}