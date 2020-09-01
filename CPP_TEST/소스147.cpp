#include <string>
#include <ostream>
#include <iostream>

//http://www.vishalchovatiya.com/prototype-design-pattern-in-modern-cpp/

using namespace std;

struct Office {
    string      m_street;
    string      m_city;
    int32_t     m_cubical;
};
class Employee {
    string      m_name;
    Office* m_office;
    // Private constructor, so direct instance can not be created except for `class EmployeeFactory`
    Employee(string n, Office* o) : m_name(n), m_office(o) {}
    friend class EmployeeFactory;
public:
    Employee(const Employee& rhs) : m_name{ rhs.m_name }, m_office{ new Office{*rhs.m_office} }
    { }
    Employee& operator=(const Employee& rhs) {
        if (this == &rhs) return *this;
        m_name = rhs.m_name;
        m_office = new Office{ *rhs.m_office };
        return *this;
    }
    friend ostream& operator<<(ostream& os, const Employee& o) {
        return os << o.m_name << " works at "
            << o.m_office->m_street << " " << o.m_office->m_city << " seats @" << o.m_office->m_cubical;
    }
};
class EmployeeFactory {
    static Employee     main;
    static Employee     aux;
    static unique_ptr<Employee> NewEmployee(string n, int32_t c, Employee& proto) {
        auto e = make_unique<Employee>(proto);
        e->m_name = n;
        e->m_office->m_cubical = c;
        return e;
    }
public:
    static unique_ptr<Employee> NewMainOfficeEmployee(string name, int32_t cubical) {
        return NewEmployee(name, cubical, main);
    }
    static unique_ptr<Employee> NewAuxOfficeEmployee(string name, int32_t cubical) {
        return NewEmployee(name, cubical, aux);
    }
};
// Static Member Initialization 
Employee EmployeeFactory::main{ "", new Office{"123 East Dr", "London", 123} };
Employee EmployeeFactory::aux{ "", new Office{"RMZ Ecoworld ORR", "London", 123} };
int main() {
    auto jane = EmployeeFactory::NewMainOfficeEmployee("Jane Doe", 125);
    auto jack = EmployeeFactory::NewAuxOfficeEmployee("jack Doe", 123);
    cout << *jane << endl << *jack << endl;
    return EXIT_SUCCESS;
}