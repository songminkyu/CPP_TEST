#include <iostream>
#include <string>


/*
���� ������ �дٰ� incomplete type�� ���� �Ƿ��ϰ� ���Ǵ� ������ 
template argument �����̶�� ����� ���� ������~.

���� ���Ǵ� ����(�ν��Ͻ��� �䱸�Ǵ� ����)������ complete type���� 
�����ϴ� ������ ������.

C++20�� smart pointer�� incomplete type�� ���� ���� Ȱ���ϰ�~

*/
template<class T>
struct A {
	static T datas[]; // T[]�� �ҿ��� Ÿ��.
};

template<class T>
T A<T>::datas[1] = {};

template<>
int A<int>::datas[2] = { 1,2 };

template<>
double A<double>::datas[3] = { 1.1, 2.2, 3.3 };

template<>
std::string A<std::string>::datas[4] = { "test1","test2", "test3", "test4" };

int main() {
	for (auto&& item : A<int>::datas) std::cout << item << ' '; std::cout << '\n';
	for (auto&& item : A<double>::datas) std::cout << item << ' '; std::cout << '\n';
	for (auto&& item : A<std::string>::datas) std::cout << item << ' '; std::cout << '\n';
}