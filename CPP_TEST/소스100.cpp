#include <iostream>
#include <tuple>

/*
std namespace�� ���ο� declaration�̳� definition�� �߰��ϰų� std ���ο� ���ο� 
namespace�� ����� ���� undefined behavior�� ���Ѵ�.

������ std ���ο� ���α׷��Ӱ� ���� �䱸 ������ �����Ѵٸ� class template�� ����
template specialization�� ���Ƿ� �߰��ϴ� ���� ����Ѵ�.

�ι�° ���� ������ ������ ����!!
*/


struct A
{
protected:
	int a = 1;
	int b = 2;
};
struct MyStruct : A {
protected:
	int c = 3;
	int d = 4;
public:
	template<std::size_t N>
	decltype(auto) get() const {
		
		if constexpr (N == 0) return a;
		else if constexpr (N == 1) return b;
		else if constexpr (N == 2) return c;
		else if constexpr (N == 3) return d;

	}
};

namespace std {
	template<>
	struct tuple_size<MyStruct> : std::integral_constant<std::size_t, 4> {};
	template<std::size_t N>
	struct tuple_element<N, MyStruct> {
		using type = decltype(std::declval<MyStruct>().get<N>());
	};
}
int main()
{
	MyStruct z{};
	auto [a, b, c, d] = z;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
}