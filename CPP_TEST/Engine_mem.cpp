#include <iostream>
#include <random>
using namespace std;

/*
ǥ�� C++ ���� ���̺귯��

ǥ�� ���� ���̺귯���� �̿��ϱ� ���ؼ��� #include <random>�� �ҽ��ڵ忡 �����Ѵ�. �ش� ���̺귯������ �׵��� C ������ 
���̺귯������ ������ ��� ���� ���̺귯������ ���� �پ��ϰ� ������ ���� �����⸦ ������ �ش�. ǥ�� ���̺귯���� ����������� 
�⺻������ �յ� ���� ������(uniform random number generator)�̸� ����(Engine)�� ����(Distribution)��� �� ���� �������� �и��Ͽ� 
�����Ǿ� ����.

������ �յ� ����(Uniform Distribution)�Ǵ� �ּҰ��� �ִ밪 ������ ������ �߻���Ų��. ���� ��� Ư�� ������ �ּҰ��� �ִ밪�� ���� 
1�� 10���� �����ߴٸ� �� ������ �̿��Ͽ� 1���� 10������ ������ ���� �� �ִ�. �Ϲ����� ����������� ���������� ������ 
�õ� ���� ������ �� ������ �õ� ���� ������ �� �ٸ� �������� ���� ��� ������ ����� ���� �ִ�.

*/
void foo(unsigned int seed) {

	default_random_engine engine;

	engine.seed(seed);

	default_random_engine::result_type v = engine();

	default_random_engine::result_type min = engine.min();

	default_random_engine::result_type max = engine.max();

	default_random_engine::result_type defaultSeed

		= default_random_engine::default_seed;

	cout << "min : " << min << endl << "max : " << max << endl;

	cout << "value : " << v << endl;

	engine.seed();

	cout << "Default seed : " << defaultSeed << endl;

	cout << "value : " << engine() << endl;

	cout << "value : " << engine() << endl;

	engine.seed();

	cout << "value : " << engine() << endl;

}

int main()
{
	foo(12345);
}