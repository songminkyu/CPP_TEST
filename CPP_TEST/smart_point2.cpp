#include <iostream>
#include <memory>


/*
����� ���� Ŭ������ shared_from_this �Ӽ� �ο��ϱ�

(�������� ���ִ� �ڵ��� �Ǿ���ȱ�. ��ġ �������̽� �����̳� ���� ������ �ڵ�)

*/
struct B {};
struct C {};

struct A : std::enable_shared_from_this<A> {
    A() = default;

    struct :B { } data_b{};
    struct :C { } data_c{};

    operator std::shared_ptr<A>() {
        std::cout << "called#1\n";
        return this->shared_from_this();
    }

    operator std::shared_ptr<B>() {
        std::cout << "called#2\n";
        return { this->shared_from_this(), &data_b };
    }
    operator std::shared_ptr<C>() {
        std::cout << "called#3\n";
        return { this->shared_from_this(), &data_c };
    }

    ~A() { std::cout << "~A\n"; }
};

int main() {
    std::shared_ptr<A> a{ new A{} };
    {
        std::shared_ptr<A> other1 = a;   // shared_ptr�� shared_from_this �Ӽ��� �����.
        std::shared_ptr<A> ohter_a = *a; // ����� ������ shared_from_this �Ӽ� ���.
        std::shared_ptr<B> other_b = *a;
        std::shared_ptr<C> other_c = *a;
    }
}