#include <iostream>

int main()
{
	alignas(128) char buffer[10];
	std::cout << (reinterpret_cast<int>(&buffer[0]) % 128);
	//buffer�� �޸� �ּҸ� 128 ��� ��ġ���� �����ϱ�



		
}