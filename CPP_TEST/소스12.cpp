#include <iostream>
#include <concepts>

/*
concepts ���� ������ �ƴ�����
concpets�� hello world �ڵ��� �� ������~
*/
template <typename T, typename U>
concept can_add = requires(T t, U u) { t + u; };

template <typename T, typename U> requires can_add<T,U>
auto add(T t, U u)
{
	return t + u;
}

int main()
{
	auto p = add(10, 14.5);
	std::cout << p << std::endl;
}