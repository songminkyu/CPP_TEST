#include <iostream>

enum struct COLOR {
	RED,
	GREEN
};

int main()
{
	int n{ 10 };
	switch (n)
	{
		std::cout << "may never called \n";//�ش� ������ ������� ����

	case 10:
		std::cout << n << std::endl;
		[[__fallthrough]];
	default:
		std::cout << "default \n";
	}
	//�Ʒ� ������ �ȵǴ°� C++20 �Ϻ��ϰ� ������Ʈ �ȵǾ��⶧��.... ���� �ɵ�.

	//COLOR color{ COLOR::RED };
	//switch (color)
	//{
	//using enum COLOR;
	//case RED: std::cout << "RED" << std::endl; break;
	//case GREEN: std::cout << "RED" << std::endl; break;
	//default:
	//	std::cout << "default \n";
	//	break;
	//}

}