#include <iostream>
#include <concepts>
#include <type_traits>

template<typename ...Ts>
void test(Ts...) { std::cout << "#1" << std::endl; }

/*
�ּ� 2��, �ִ� 4�� ���ڸ� �䱸.
*/
template<typename ... Ts>
void test(Ts...) requires (sizeof ...(Ts) >= 2) && (sizeof ...(Ts) <= 4)
{
	std::cout << "#2" << std::endl;
}

int main()
{
	test(1, 2, 3);
	test(1, 2, 3, 5, 6, 7, 8);
}