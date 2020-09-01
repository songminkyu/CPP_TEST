#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>


/*

binary_function, std::not2... �� �Լ����� ��� lambda�� std::bind�� �� ȿ�������� ���� �� �ִ�. 
�̷��� ������ C++17���� ��� deprecated�Ǿ��� C++20���� removed�� ���´�.

�̷��� ������ ���� �������� C++20�� ���׷��̵��ϸ� ���� ������ ���� �ϰ� ������ 
������ �̵� �Լ��� ã�� �� ���ٴ� �����̴�. 
������ �Ʒ� ����ó�� ������ std::bind�� lambda�� Ǯ���ָ� �ȴ�.

              C++17���� �̳� ������(std::binary_function) 
                            ��
struct same : std::binary_function<int,int,bool>
{
   do something....
}
                                                       C++17���� �̳� ������(std::not2) 
																  ��
std::transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), std::not2(same()));

*/
struct same
{
	bool operator()(int a, int b) const { return a == b; }
};

int main()
{
	std::vector<int> v1{ 0,1,2,3,4,5,6,7,8,9,10 };
	std::vector<int> v2{ 10,9,8,7,6,5,4,3,2,1,0 };
	std::vector<bool> v3( v1.size() );

	std::transform(v1.begin(), v1.end(), v2.begin(), v3.begin(),
		[](auto&& a, auto&& b) {return !same{}(a, b); }
	);

	std::cout << std::boolalpha;

	for (std::size_t i = 0; i < v1.size(); ++i)
	{
		std::cout << v1[i] << ' ' << v2[i] << ' ' << v3[i] << '\n';
	}
}