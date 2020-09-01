#include <iostream>
#include <random>
#include <array>
using namespace std;

/*


���ø� Ŭ���� �������� ù ��° ���ڰ� ���� Ƚ�� k�� �ش��ϰ� �� ��° ���ڰ� ���� Ȯ�� p�� �ǹ��Ѵ�.
�����׺����� ���� ���� ���� �ᱹ ������ Ƚ���� �ȴ�.

*/

void main()
{
	//negative_binomial_distribution Ŭ������ ���

	array<int, 20> tmp = { 0, };

	random_device seed;

	default_random_engine eng(seed());

	negative_binomial_distribution<> dist(2, 0.4);

	for (int i = 0; i < 100000; ++i) {

		int t = dist(eng);

		if (t > 19) continue;

		++tmp[t];

	}

	for (int i : tmp) { cout << i << " "; }
}