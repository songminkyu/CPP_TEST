#include <iostream>


// variable template�� explicit specialization �غ���

template<typename T> T var = {};
template<> int var<int[3][2]>[3][2] = {
	{1,2},
	{3,4},
	{5,6}
};
int main()
{
	for (auto&& rows : var<int[3][2]>)
	{
		for (auto&& item : rows)
		{
			std::cout << item << ' ';
		}
	}
}
