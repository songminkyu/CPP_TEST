#include <iostream>
#include <memory>


/*
shared_ptr ��ü�� get()�� ��ȯ���� nullptr�Ǵ� �Ͱ� use_count()�� ��ȯ���� 0�� �Ǵ� ���� ����!!
*/
struct A {
    ~A() { std::cout << "~A\n"; }
};


int main() {
    std::shared_ptr<A> a{ new A{} };
    std::shared_ptr<void> avoid{ a, nullptr };
    std::cout << "use_count:" << avoid.use_count() << std::endl;
    if (avoid) {
        std::cout << "avoid.get()!=nullptr\n";
    }
    else {
        std::cout << "avoid.get()==nullptr\n";
    }
}