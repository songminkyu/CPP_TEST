#include <iostream>
#include <memory>

int main()
{
	std::shared_ptr<int> a{ new int{10} };
	std::shared_ptr<int> other = a;

	/*
	shared_from_this �Ӽ��� enable �ϴ� �ǹ̸� �˾ƺ���.
	�� �ڵ����� 
	a�� owner �� �޸� �ּҸ� p��� �θ���
	a���� �Ǵٸ� shared_ptr other�� ����� �ִ�(���� �����ڿ� ������ �ƴ�...)
	�̰��� "p�� ���� shared_from_this �Ӽ��� enable" �ϴٰ� ���Ѵ�.

	�⺻������ shared_ptr, weak_ptr �� shared_from_this �Ӽ��� enable �ϴ�.
	����� ���� �� Ÿ�Կ� ���ؼ��� enable_shared_from_this ���ø� Ŭ������ Ư��ȭ�� this
	�� ���� shred_from_this �Ӽ��� enable �ϰ� ���� �Ҽ� �ִ�.
	
	*/
}