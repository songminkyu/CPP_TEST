#include <iostream>
#include <type_traits>
#include <algorithm>

//���� ������
template <typename ...Args>
struct A {
	alignas(Args...) char buffer[std::max({ sizeof(Args)... })];
};

int main()
{
	A<int, char, double> a{};
	std::cout << sizeof(a.buffer) << std::endl;
	std::cout << alignof(decltype(a)) << std::endl;
}