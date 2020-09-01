#include <iostream>

template<class T>
struct Base {
	// Injected-class-name �� type-name �Ǵ� template-name �̴�.
	Base* p;
};

template< class T>
struct Derived : public Base<T>
{
	// Injected-class-name �� type-name �Ǵ� template-name �̴�.
	typename Derived::Base* p;
};

template <
	class T,
	template<class> class U = T::template Base>

/*
T::template Base�� Derived�� injected-class-name(type-name)�� ��쿡
Base �� injected-class-name(template-name)�� ���� �Ѵ�.
*/
struct Third{
	Third() = default;
};


int main()
{
	Third< Derived< int > > t{};
}
