#include <utility>
#include <cstdio>
#include <iostream>

/*
tuple�� �̷��� ���� ���� ���������±� ����.
���� ��ü�� ... ������ ���������鼭 ������ ����� ����~
���� ���̺귯�� �������� �� �Ƿ��� ���̳�. ļ~.
������ �ð� ������..
*/
template <typename ... Ts>
constexpr auto tuple(Ts&& ... ts)
{
	return[...ts = std::forward<Ts>(ts)](auto&& f) { return f(ts...); };
}

template <unsigned I, typename T, typename ... Ts>
constexpr auto get_val(const T& t, const Ts& ... ts)
{
	if constexpr (I == 0) return t;
	else return get_val<I - 1>(ts...);
}

template <unsigned I, typename T>
constexpr decltype(auto) get(T&& t)
{
	return t([](auto&& ... vs) { return get_val<I>(std::forward<decltype(vs)>(vs)...); });
}

template <typename T>
constexpr auto size(T&& t)
{
	return t([](const auto& ... ts) { return sizeof...(ts); });
}

int main()
{
	constexpr auto t = tuple(1, "foo", 3.14);
	constexpr auto n = size(t);
	std::cout << get<0>(t) << std::endl;
	std::cout << get<1>(t) << std::endl;
	std::cout << get<2>(t) << std::endl;

	return get<n - 1>(t) - get<0>(t);
}