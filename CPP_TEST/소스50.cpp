#include <iostream>
#include <type_traits>
#include <concepts>

/*
GCC 10�� concepts�� �����Ǿ�� �ִ�. �̹� �������� �ǰ�, concepts core 
�κа� ���̺귯���� �����ϰ� �ִ� msvc�� �Ѿ� concepts ���� 
�������� �̹� ������ ����.
*/
template<typename T> concept C1 = true;
template<typename T> concept C2 = true;
template<typename... Ts> concept C3 = true;

void g1(const C1 auto*, C2 auto&) {};
void g2(C1 auto&...) {};
void g3(C3 auto...) {};
void g4(C3 auto) {};

auto add(auto a, auto b) { return a + b; }
template<typename T, typename U> concept ltest = std::same_as<T, U>;

template<ltest<int> A>
struct Test{};

int main() {
	auto z = add(1, 2);
	std::cout << z;

	Test<int> a;
}