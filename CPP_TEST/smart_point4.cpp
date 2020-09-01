#include <iostream>
#include <memory>

/*
owner_before�� owner ��ü�� �����Ϳ� ���� strict weak ordering ����.
*/
struct A {
    ~A() { std::cout << "~A\n"; }
};


int main() {
    std::shared_ptr<A> a{ new A{} };
    std::shared_ptr<void> avoid{ a, nullptr };

    std::cout << a.owner_before(avoid) << std::endl;
    std::cout << avoid.owner_before(a) << std::endl;
}