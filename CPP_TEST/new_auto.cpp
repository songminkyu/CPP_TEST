#include <iostream>

int main() {
	//MS���� �� �ȵ���....?
	auto fn = new auto{
		[](int r) { std::cout << "hello world!!" << r;  }
	};

	(*fn)(10);

	delete fn;

}