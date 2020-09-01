#include <iostream>
#include <random>
#include <array>
/*
������� ���� ������(Non-deterministic Random Generator)

�Ϲ������� ���� ������� �õ� ���� ������� ���� ������ �����Ѵ�. �õ� ���� �ݵ�� ���������� �Է��ؾ� �ϴ� ���̴�. 
seed��� �ɹ��� ���ڷ� ���� �����ϱ� �����̴�. ǥ�� ���� ���̺귯���� ������� ���� ������ ���ø� Ŭ������ random_device�� ������ �ش�.
random_device�� ����� ���� ������ �õ� ���� �ʿ� ���� �������� �ϹǷ� �ý������� ���̳� �ü�� Ȥ�� �ϵ���� ���ҽ��� ����Ѵ�.

*/
int main() {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(0, 99);
	std::cout << dist(mt) << std::endl;

	/************************************************/

	//random_device ���� �յ� ������ ���δ�
	std::random_device randomDevice;
	std::array<int, 10> test = { 0, };
	std::uniform_int_distribution<int> _dist(0, 9);
	for (int n = 0; n < 1000000; ++n) {
		++test[_dist(randomDevice)];	
	}

	for (const auto& arr : test)
	{
		std::cout << arr << std::endl;
	}
}