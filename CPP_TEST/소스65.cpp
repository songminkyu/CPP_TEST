
#include <iostream>
#include <vector>
#include <type_traits>


/* consteval�� �߰������ν� ������ �ð����� ��İ��� ���� ����~*/
template<class T, auto M, auto N> constexpr auto determinant(T const(&vals)[M][N])
requires (M == 2 && N == 2)
{
	return vals[0][0] * vals[1][1] - vals[0][1] * vals[1][0];
}

/*
gcc �� ���� ���� ������, ���� msvc ����Ǹ� �������� ���� �ҵ�. ���� constexpr �� ��ü
*/
//
///* consteval�� �߰������ν� ������ �ð����� ��İ��� ���� ����~*/
//template<class T, auto M, auto N> consteval auto determinant(T const(&vals)[M][N])
//requires (M == 2 && N == 2)
//{
//	return vals[0][0] * vals[1][1] - vals[0][1] * vals[1][0];
//}
//

int main() {
	auto del
		= determinant({
			{1,2},
			{3,4}
			});
	std::cout << del;
}