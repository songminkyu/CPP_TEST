#include <iostream>
#include <optional>

void schrodinger()
{
	std::optional<bool> alive = false;

	//false�� �ָ� 2���� ���ǹ��� ����
	//true�� �ָ� ù��° ���ǹ��� ����
	// �ű��ϳ�...

	if (alive) {
		std::cout << "is a alive" << std::endl;
	}

	if (alive == false) {
		std::cout << "is a dead" << std::endl;
	}

}

int main()
{
	schrodinger();
}