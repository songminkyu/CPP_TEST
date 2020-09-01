#include <iostream>
#include <type_traits>


/*

����
1.�ι�°�� false�ƴѰ���?
move assinable�� delete�ε�..
2.ù��° ������ copy assinable�� ���� assignable��
���ϴ°� �˰ڴµ� �̰� �׳� �ʽ��ڷμ� �ܿ�⸸ �ؼ���..-,-;;
Ư���� ������ �ֳ���?
�̷��� �ΰ��� ����� ������ ������....

����
move semantic �ǹ̺��� �ϴ� ��Ȯ�ϰ� ������ �ʿ䰡 �ֽ��ϴ�.
�̵��� ��ü�� ���������� ���� �ǿ����ڿ� ���°� �Ű����ϴ�. 
������ ������ �ǿ����ڴ� ��ü ��ü�� ������������ ��ü�� ���´� Ư���� �� �����ϴ�. 
���� �����Ϸ��� observation ��� �Լ��� ���� �˻������ν� ��ü�� ���¸� Ư���ϰ�, 
���Ŀ� ������ ����ؾ� �մϴ�.
���� copy semantics�� ���� ����� �����ϰ� ��ü�� ���¸� Ư���� �� �ֽ��ϴ�. 
�ᱹ move ������ delete���� �ʴ� �̻� copy semantics���� ��ü�� �� �ֽ��ϴ�.

std::is_assignable<T&, T&&>::value�� �ٷ� is_move_assignable�� �ε� �־��� 
T�� &�� �߰��� Ÿ���� ���ʿ�, &&�� �߰��� Ÿ���� �����ʿ� ���� ������ ����Ѵٴ� �ǹ�����.
���� T�� A��� A& = A&& �����̴� ���� ���ϴ� move ����������. ������ T ��ü�� A&��� 
A&+&�� A&��, A&&+&�� A&�� ���Ǹ� A&=A& ��, ���� copy operator�� �۵��մϴ�.

*/


struct A {
    A& operator=(const A&) { return *this; }
    ~A() {}
};

struct D {
    D& operator=(D&&) = delete;
    D& operator=(const D&) = default;
    ~D() {}
};

int main() {
    std::cout
        << std::boolalpha
        << std::is_move_assignable_v<A> << std::endl;


    std::cout
        << std::boolalpha
        << std::is_move_assignable_v<D&> << std::endl;
}