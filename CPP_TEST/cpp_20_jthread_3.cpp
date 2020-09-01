#include <iostream>
#include <sstream>
#include <chrono>
#include <jthread.hpp>

/*
    https://wandbox.org/permlink/01m2qklaJ21TPGM3 (std::thread ����)
    https://wandbox.org/permlink/LLq4OxGPNPyICrDE (std::jthread ����)

    std::jthread�� ���� �� �Ϲ�ȭ�� ������ ActiveObject(�����带 ���� ǰ�� �ִ� ������ �ִ� Ŭ����) ���°���. 
    �Ʒ�ó��. �翬�� std::thread�� �����ص� ��������. � ���µ��� ����ϱ� ����!!
    stop_source�� stop ��ȣ�� ������ atomic�ϰ� stop_requested()�� �о �� ����(stop ���¸� �����ϴ� ����, 
    promise-future ���� ������ ����).�� �ϳ��� �������� �����带 �������� ���� ����. 
    10�� �����带 ��ϸ鼭 ���ÿ� ���� �ñ׳��� �����ִ� ����~

*/
//ǥ�� thread�� ����

class Actor_thread {
public:

	[[nodiscard]]
	std::stop_source run(std::uint64_t cnt) {
		std::stop_source src{};
		std::stop_token p = src.get_token();

		using namespace std::literals;
		while (cnt-- > 0) {
			std::thread(
				[p]() {
					while (!p.stop_requested())
					{
						std::this_thread::sleep_for(500ms);
						std::stringstream ss;
						ss << "echo:\t" << std::this_thread::get_id() << '\n'; //�ش� ������ ���̵� ������
						std::cout << ss.str(); //echo �� ������ ���̵� ���
					}
					std::stringstream ss;
					ss << "endding:\t" << std::this_thread::get_id() << '\n';
					std::cout << ss.str();
				}
			).detach();
		}
		return src;
	}
};

class Actor_jthread {
	std::vector<std::jthread> ths;
public:	
	void run(std::uint64_t cnt) {
		using namespace std::literals;

		while (cnt-- > 0){
			ths.emplace_back(
				[](std::stop_token p) {
					while (!p.stop_requested()){
						std::this_thread::sleep_for(500ms);
						std::stringstream ss;
						ss << "echo : \t" << std::this_thread::get_id() << '\n';
						std::cout << ss.str();
					}
					std::stringstream ss;
					ss << "ending :\t" << std::this_thread::get_id() << '\n';
					std::cout << ss.str();
				}
			);
		}
	}
};

int actor_thread_test()
{
	{
		Actor_thread actor{};
		auto ender = actor.run(10);
		std::cin.get();
		ender.request_stop();
	}
	std::cin.get();
	return 0;
}

int actor_jthread_test()
{
	{
		Actor_jthread actor{};
		actor.run(10);
		std::cin.get();		
	}
	std::cin.get();
	return 0;
}
int main()
{

/*
   true  : actor_thread_test
   false : actor_jthread_test
*/
	
#if false
	actor_thread_test();
#else
	actor_jthread_test();
#endif
}