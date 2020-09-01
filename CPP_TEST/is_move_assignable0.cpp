#include <iostream>
#include <type_traits>

struct D {
	D& operator=(const D&&) = delete;
	~D(){}
};

int main()
{
	std::cout
		<< std::boolalpha
		<< std::is_move_assignable_v<D&>;

}