
#include <iostream>

/*
C++20���� ���ٰ� unevaluated-context�� ����� �Ǹ鼭 �̷��� �ڵ��� �����������~. 
���� ����� �����Ϸ��� gcc��������..(�� ���� ���� �������� �ȴٰ��ؼ� �ֱ������� �˻��ؿ� ������~)

deleter�� comparator�� �׳� ���ٷ� �ܾ��ּ���~ ī�� �ܾ��ֵ�~

https://godbolt.org/z/xpyUqk
*/

#include <iostream>
#include <memory>
struct A {
};

using MY_PTR = std::unique_ptr <
	A,
	decltype([](auto p) { delete(p); std::cout << "called\n"; })
> ;

int main() {
	MY_PTR a{ new A };
}
