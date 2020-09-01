#include <iostream>
#include <random>
#include <array>
using namespace std;

/*


0������ 9�������� ������ �������� ������ �Ϸķ� ������ �ִٰ� ��������. 
�̶� 0�� �������� 70%�� Ȯ���� �� �ڶ�� ����� �ܵ� �ְ�, 9�� �������� 
������ �������� ������ ����� ���� �ܵ� �� ���ڶ��ٰ� ��������. 0������ 
9������ �� ������ ����� ������ ������ �����ϰ� �ʹٸ� ��� ������ �� ������.



geometric_distribution Ŭ���� ����� ��
*/

void main()
{
	array<int, 14> tmp = { 0, };

	random_device seed;

	default_random_engine eng(seed());

	geometric_distribution<int> dist(0.7);

	for (int i = 0; i < 100000; ++i) {

		++tmp[dist(eng)];

	}

	for (int i : tmp) { cout << i << " "; }
}