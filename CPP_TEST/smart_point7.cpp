#include <iostream>
#include <memory>

/*
���� ������ empty shared_ptr ���� ������ �־� ����� �� ����.

empty shared_ptr��
ownership�� ������
����� �����ʹ� �ִ� shared_ptr�̴�.
(ownership�� �����ϴ� �����͸� ���� �ٸ��� ���� ���� ���� �ſ� ������ �� �ִ�. ���� �ڵ�����)

std::cout���� �ּҸ� ����� �����ϴ� �����͸� Ȯ���� �� �ִ�. ������ ownership�� ������ �Ҹ��ڰ� ȣ����� �ʴ´�.

13���� �ڵ��� �ٽ��̶�� �� �� �ִµ� ù���ڴ� ownership�� share�� ����̰�, �ι�° ���ڴ� ������ �����ʹ�. 
�̶� ù���ڷ� empty shared_ptr�� �־��ָ� ����� �� �� �ִ�.

*/

struct A {
	~A() { std::cout << "~A" << std::endl; }
};

int main()
{
	A* a = new A();
	{
		std::shared_ptr<A> nullA1{};
		std::shared_ptr<A> nullA2{ nullA1,a };
		std::cout << nullA2 << std::endl;
	}
	delete a;
}