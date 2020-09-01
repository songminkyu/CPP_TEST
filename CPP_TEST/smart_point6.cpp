#include <iostream>
#include <memory>

/*
shared_ptr�� �̿��ؼ�

ownership�� ����� �����͸� �ٸ��� �������� ����.
*/

struct B {
    virtual void test() {}
    ~B() { std::cout << "~B\n"; }
};

struct A {
    struct :B {
        void test() override { std::cout << ":\n"; }
    } datas{};

    ~A() { std::cout << "~A\n"; }

    void log() { std::cout << "A::log\n"; }
    operator B* () { return &datas; }
};


int main() {
    std::shared_ptr<A> a{ new A{} };
    std::shared_ptr<B> b{ a, *a };

    b->test();
    a->log();
}
