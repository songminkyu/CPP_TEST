#include <iostream>

/*
variable template���� �迭 ����غ���
*/

template<typename T> T var = { };


int main()
{

	int i = 0;
	for (auto&& item : var<int[16]>) {
		item = i++;
	}

	for (auto&& item : var<int[16]>)
	{
		std::cout << item << " ";
	}
}
