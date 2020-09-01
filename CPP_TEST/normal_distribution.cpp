#include <iostream>
#include <random>
#include <array>
using namespace std;

/*
normal_distribution ���ø� Ŭ������ RealType�� Ÿ���� ������ �����Ѵ�. 
������ ��� �߻� Ȯ���� ����� mean�� �ο��� ���� �ǰ� �л��� S*S�� ���� ������ ������.
*/
int main()
{
	//normal_distribution ���ø� Ŭ���� ����� ��

	std::default_random_engine eng;

	std::normal_distribution<double> dist(5.0, 2.0);

	array<int, 10> tmp = { 0, };

	for (int i = 0; i < 10000; ++i) {

		double number = dist(eng);

		if ((number >= 0.0) && (number < 10.0)) ++tmp[int(number)];

	}

	for (const auto& nd : tmp)
		std::cout << nd << std::endl;
}