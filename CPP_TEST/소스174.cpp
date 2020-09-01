#include <iostream>

/*
C++ ���ø��� �ſ� ������ ������ ���ʷ� �Ѵ�.
���� ���ΰ� �ϴ�,
���� ���
N+1�� 1+N�� ���ٰ� ���� �����Ѵ�.
�� ���� ������ ���� ��ȯ ��Ģ�� �����Ѵ�. �� ��� ���� ���� �׺��� ���� � ��Ģ�� �ٰ��ϰ� �� �ٽ� �Ϻ� ��Ģ�� �� �����Ѵ�.
�׷��� �� �Ϻ� ��Ģ�� �������� ����. �� �̻� � ��Ģ�� �������� �ʴ� ����. �ٷ� �� ����, �Ǵ� �� �������� �ܿ� ���� ������ C++ ���ø� ��Ģ�� �����Ѵ�. ������ �׷��ϴ�.
������ �������� ���� ���� �������� atomic expression�� �����ϳ�����. ���⼭ expression�� atomic�ϴٴ� ���� � ��Ģ�� �����ϱ� ���� expression�� ������ �� ���ٴ� �ǹ�. 
�� �ڽŸ� �ڽ��� expression�� ��ġ�� �� �ִ�.
*/

template<unsigned N> constexpr bool Atomic = true;
template<unsigned N> concept C = Atomic<N>;
template<unsigned N> concept Add1 = C < N + 1>;

template<unsigned N> void foo() requires Add1<1 + N == 1>
{ 
	std::cout << "#1" << std::endl; 
}

template<unsigned N> void foo() requires Add1<N + 1 == 2>
{
	std::cout << "#2" << std::endl;
}
int main()
{
	//foo<8>(); //error #1�� #2�� ���� �ٸ� �Լ� -> �������� ������� ����.	
}