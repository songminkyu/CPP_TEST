#include <iostream>
/*
class template deduction guide�� aggregate type���� ������ �� �ֽ��ϴ�.
�ϳ� �����ϸ鼭�� ������ ���� ������ ���⿡������ ����ҵ�
*/
template<class T, std::size_t N>
struct AT {
    T data[N];
    void print() {
        for (auto&& mitem : data) {
            std::cout << mitem << std::endl;
        }
    }
};

int main() {
    AT at{ {1,2,3,4,5} };
    at.print();
}