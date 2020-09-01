#include <iostream>
#include <mutex>
#include <chrono>
#include "stop_token.hpp"
#include "jthread.hpp"
int main()
{
	/*
	
	std::jthread ���� �� �Ϲ����� �ڵ� ��Ÿ��
	���α׷��� ����ǿ� stop_source�� �δ� ���� �� �Ϲ����� ���.

	*/
	{
		using namespace std::literals;
		std::stop_source src{};
		std::stop_token p = src.get_token();

		std::jthread t(
			[&p]() {
				while (!p.stop_requested())
				{
					std::this_thread::sleep_for(1s);
					std::cout << "ehco\n";
				}
				std::cout << "endding\n";
			});
		std::this_thread::sleep_for(5s);
		src.request_stop();
	}

	return 0;
}