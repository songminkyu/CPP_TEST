#include <iostream>


/*
C++20������ generic lambdas ������ template-parameter-list�� 
�����մϴ�(msvc 19.22������ �ݿ���).

*/
int main()
{
	auto f = []<typename ...T>(int z, T&& ...args) {
		std::cout << z << std::endl;
		(std::cout << ... << std::forward<T>(args)) << std::endl;
	};

	f(1, 2, 3);

	return 0;
}