#include <iostream>

/*
lambda capture ������ pack�� pack expansion �����غ���
*/
template<typename ...Ts>
void test(Ts... ts)
{
	[...args = ts] (){
		(std::cout << ... << args);
		
	}();
}
template<typename ...Ts>
void test2(Ts... ts)
{
	[ts...] (){
		(std::cout << ... << ts);

	}();
}

int main()
{
	test("hello","\n", 12, "\n", 10.5,"\n");
	test2("hello", "\n", 12, "\n", 10.5);
}