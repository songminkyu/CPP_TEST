#include <iostream>
#include <random>
#include <array>
using namespace std;

/*
�������� ������ ���

�������� ������ bernoulli_distribution Ŭ������ ����ϸ� ������ 
Ư�� Ȯ���� �� �̳� ������ �Ǵ��� �� ����Ѵ�. ���� ������ó�� ��/��, ����/����, 
����/������ ������ ���� �� �ִ� ���̴�. ������� ���� ���ο��� �ٸ� ������ ĳ���Ϳ��� ��ȭ�� �Ǵٸ�
�ش� ���� ĳ���Ͱ� ���������� ���� ���ڷ� 0.5�� ���ڷ� ���� �������� ������ ����� �� ������ �ֻ����� ������ �� 
6�� �����°��� ���� ���ڷ� ���� �����ڿ� 1 / 6�� Ȯ�������� ���� �������� ������ ����� �� ���� ���̴�.



30%�� Ȯ���� true Ȥ�� false�� �������� ���� �� �ִ�.
*/

void main()
{
	array<int, 2> tmp = { 0, };

	random_device seed;

	default_random_engine eng(seed());

	bernoulli_distribution dist(0.3);

	bool result = dist(eng);

	for (int i = 0; i < 100000; ++i) {

		if (dist(eng)) { ++tmp[1]; }

		else { ++tmp[0]; }

	}

	for (int i : tmp) { cout << i << " "; }
}