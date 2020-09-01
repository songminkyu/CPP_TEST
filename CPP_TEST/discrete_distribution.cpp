#include <iostream>
#include <random>
#include <array>
using namespace std;

/*
ǥ�� ���� �׷쿡�� �̻� ����(Discrete Distribution), �ǽ������� ��� ����(Piecewise Constant Distribution)), 
�ǽ������� ���Ͼ� ����(Piecewise Linear Distribution)�� �ִ�. �� ���� ������ �����ϴ�.

�̻� ������ Ư�� ������ ���� ������ ������ �� �� �ִ�. �̸� ���� discrete_distribution 
���ø� Ŭ������ ������ �ִ� ���� �������� initializer_list�� �޴� �����ڰ� �����Ѵ�.

*/
int main()
{
	//discrete_distribution Ŭ������ ���

	std::default_random_engine eng;
	
	std::discrete_distribution<int> dist = { 2, 2, 1, 1, 2, 2, 1, 1, 2, 2 };

	array<int, 10> tmp = { 0, };

	for (int i = 0; i < 100000; ++i) {

		int number = dist(eng);

		++tmp[number];

	}

	for (int t : tmp) {

		std::cout << t << std::endl;

	}
	/*
	����� ���� ���� ������ �����ϸ� discrete_distribution ���ø� 
	Ŭ������ ������ �� ���ڷ� �ο��� initializer_list�� ���� ��ŭ ��� ���� 
	������ �ݿ��� ������ �������� Ȯ���� �� �ִ�.
	*/
}