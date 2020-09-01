
#include <iostream>
/*
T(&)[N]������ template argument deduction���� N�� �迭�� ���̷� �߷еǰ�, 
���������� ����� �� element�κ��� ������ T�� �߷еǾ�� �Ѵ�.

T(&)[10]������ template argument deduction������ �迭 ���̴� �߷����� �ʰ� 
���������� ����� �� element�κ���  ������ T�� �߷еǸ� �ȴ�.
*/

template<class T> void j(T const(&datas)[4]) {

	for (auto&& item : datas) {
		std::cout << item << std::endl;
	}
}

int main() {
	j( { 1,2,0,0 } );
}