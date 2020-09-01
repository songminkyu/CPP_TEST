#include <iostream>
#include <tuple>

/*

function... ��� �̺��� ���ΰ�? ��� ������ ���ΰ�? ���α׷��� ������ ���� ����~

*/

template <typename... Rs, typename ...Args>
auto marge_fn(Rs(*...fs)(Args)) {
	return[fs...](Args&&...args){
		using REST = std::tuple<Rs...>;
		return REST(fs(args)...);
	};
}

int t1(float) { return 10; }
float t2(char) { return 10.5f; }

int main() {
	auto rets = marge_fn(t1, t2)(10.5f, 'c' );
	std::cout << std::get<0>(rets) << std::endl;
	std::cout << std::get<1>(rets) << std::endl;
}