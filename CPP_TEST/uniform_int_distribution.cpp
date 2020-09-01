#include <iostream>
#include <random>
#include <array>
using namespace std;
/*
���� ����

���� ������ �������κ��� ��� ������ ���� ������ ������ ���ġ�� �ش�. 
�Ϲ������� rand() �Լ� ��� ���� %�� �̿��� ���ָ� �����Ͽ� ����� �κп� ���� ������ ����� �� �ִ�. 
���� �����⸦ ���� ���� ���� ���� ������ ���� �ǵ��� uniform_int_distribution Ŭ������ ���ø� ���ڿ� �ʿ��� �ִ�, 
�ּ� ���� �����Ѵ�. ���� �ڷ����� �Ǽ� Ÿ���̶�� uniform_real_distribution Ŭ������ ����� �� �ִ�.



������ ������ ����� ���� ���� Ŭ���� ���� ����� ��

CustomEngine Ŭ������ ���������� ������ �ּҰ����� �ִ밪���� ���� ������� ��ȯ�Ѵ�. �ᱹ CustomEngine�� 
�����ϰ� �յ� ���� ���� ��ȯ�ϱ� ������ ���� Ŭ������ ������� ���� Ȯ���� �� �ִ�. uniform_int_distribution�� 
���ø� Ŭ������ ���ָ� 0���� 9���� �����ϰ� CustomEngine�� �����Ų �� 
����� ū Ƚ����ŭ ������ �����ϸ� ��� ������ ���� ������ �̷�� ���� Ȯ���� �� �ִ�.
*/
class CustomEngine {

public:

	typedef unsigned int result_type;

	static result_type min() { return 0; }

	static result_type max() { return 100000000; }

	explicit CustomEngine() : cache_(0) { }

	result_type operator()() { return ++cache_; }

private:

	unsigned int cache_;

};

int main()

{

	array<int, 10> tmp = { 0, };

	CustomEngine ce;

	uniform_int_distribution<> dis(0, 9);

	for (int i = 0; i < 100000; ++i) {

		++tmp[dis(ce)];

	}

	for (int i : tmp) {

		cout << i << " ";

	}

}

