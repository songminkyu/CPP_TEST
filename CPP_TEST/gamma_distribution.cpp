#include <iostream>
#include <random>
#include <array>
#include <map>

using namespace std;

/*
gamma_distribution�� ����� ���Ŀ� ��Ÿ�� �����ڷ� ������ �̸� ��ȸ�� �� �ִ� alpha()�� beta() �ɹ� �Լ��� ������ �ְ� �ִ�. 
gamma_distribution�� 0���� ū ������ �����ϸ� ���ø� ���ڷ� ��� ���� ���� Ÿ���� �޴´�.
*/
void test(const double a, const double b) {

	std::mt19937 gen(1701);

	std::gamma_distribution<> distr(a, b);

	std::cout << std::endl;

	std::cout << "min() == " << distr.min() << std::endl;

	std::cout << "max() == " << distr.max() << std::endl;

	std::cout << "alpha() == " << distr.alpha() << std::endl;

	std::cout << "beta() == " << distr.beta() << std::endl;

	std::map<double, int> histogram;

	for (int i = 0; i < 10; ++i) {

		++histogram[distr(gen)];

	}

	int counter = 0;

	for (const auto& elem : histogram) {

		std::cout << ++counter << ": " << elem.first << std::endl;

	}

	std::cout << std::endl;

}

void test2()
{

	/*
	���İ��� ��Ÿ���� ���� 2.0�� �� ���������� �󵵸� ���ϱ� ���� ����� ��ŭ�� ������ �߻����� 
	�׷����� ���ϸ� gamma_distribution�� ���� ������ ���δٴ� ���� �� �� �ִ�.

	gamma_distribution�� �󵵸� ���ϴ� �ڵ��� ��
	*/
	std::default_random_engine eng;

	std::gamma_distribution<double> dist(2.0, 2.0);

	array<int, 10> tmp = { 0, };

	for (int i = 0; i < 10000; ++i) {

		double number = dist(eng);

		if (number < 10) ++tmp[int(number)];

	}

	for (int t : tmp) {

		std::cout << t << std::endl;

	}
}

int main()
{
	test(0.2, 4.9);
	test2();
}