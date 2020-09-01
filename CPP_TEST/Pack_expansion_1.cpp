#include <iostream>
/*

C++20������ ���� �ʱ�ȭ ������ Pack expansion�� �����մϴ�
(msvc 19.22 ������ �ݿ���.)

*/
template <class...Args>
auto delay_invoke_foo(Args... args)
{
	return[args...]()-> decltype(auto){
		(std::cout << ... << args) << std::endl;
	};
}

int main()
{
	delay_invoke_foo(1, 2, 3, 4)();
	return 0;
}