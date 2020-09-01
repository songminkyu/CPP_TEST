#include <iostream>
#include <concepts>

template<class T>
requires (!requires {typename T::difference_type; })
//requires-clause�� ������ '!' �� �տ� �־��ش�.
void test()
{
	std::cout << "#1" << std::endl;
}

template <class T>
void test() {
	std::cout << "#2" << std::endl;

}

int main()
{
	struct A {
		using difference_type = int;
	};

	test<A>();
	test<int>();
}