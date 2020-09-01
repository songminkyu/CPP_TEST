#include <boost/flyweight.hpp>
#include <iostream>
#include <string>
using namespace std;
//http://www.vishalchovatiya.com/flyweight-design-pattern-in-modern-cpp/
//�ҽ�164.cpp ���� �� �����ϰ� �ö��̿���Ʈ ������ �����ϴ±���...

struct User {
    boost::flyweight<string>   m_first_name, m_last_name;
    User(string f, string l) : m_first_name(f), m_last_name(l) { }
};
int main() {
    User john_doe{ "John", "Doe" };
    User jane_doe{ "Jane", "Doe" };
    cout << boolalpha;
    cout << (&jane_doe.m_first_name.get() == &john_doe.m_first_name.get()) << endl;    // False
    cout << (&jane_doe.m_last_name.get() == &john_doe.m_last_name.get()) << endl;      // True
    return EXIT_SUCCESS;
}