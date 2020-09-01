#include <iostream>

struct A
{
protected:
	struct ProtectedA {};
	void test();
};

template<typename T1, typename T2> struct X{ };

template<typename T1> struct X<T1, A::ProtectedA> : A {
	A::ProtectedA val = { }; //������ ���� ���Ǵ� ��ġ������ access üũ �Ѵ�, A�κ��� ��� �޴´�.
};
// template class specialization �� argument list�� access�� üũ ���� �ʴ´�.

void A::test() {
	X<int, A::ProtectedA> datas{  };
}

int main()
{
	X<int, A::ProtectedA> datas{};
	//������ ���� ��� �Ǵ� ��ġ������ access üũ�Ѵ�. Error!!!

	
}