#include <iostream>

int main() {
	alignas(char) alignas(double) char buffer[sizeof(double)];
	std::cout << reinterpret_cast<int>(buffer) % alignof(double);

	/*
	char ������ �޸𸮿� ������ double Ÿ���� ���������� ����Ѵٸ� : 
	char�� ���� �Ծ�� double ���� �Ծ��� ��� �ؼ� �ϵ��� �޸��� ���� ��ġ�� �����ϱ�
	*/
}