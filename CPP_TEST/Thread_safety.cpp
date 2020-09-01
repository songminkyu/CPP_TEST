#include <iostream>
#include <thread>
#include <atomic>
#include <string>
#include <chrono>
#include <future>

class SystemCall {
    static inline std::atomic_bool active_ = false;
public:
    static int _raw_call(std::string cmd) noexcept {
        using namespace std::literals;
        bool expected = false;
        while (
            !active_.compare_exchange_weak(
                expected,
                true,
                std::memory_order_release,
                std::memory_order_relaxed
            )
            )
        {
            expected = false;
            std::this_thread::sleep_for(10ms);
            // C++20�� �߰��� atomic_update ���� �Լ��� ����ϸ� �� ���� ���� ���� ����
        }
        ///****
        auto ret = std::system(cmd.c_str());
        ///****
        active_.store(false, std::memory_order_release);
        return ret;
    }

    static auto call(std::string str) noexcept {
        return std::async(SystemCall::_raw_call, str);
    }
};

struct syscmd_tag {}    syscmd;
struct mt_syscmd_tag {} mt_syscmd;
auto operator<< (const syscmd_tag, const std::string& cmd) {
    return SystemCall::_raw_call(cmd);
}

auto operator<< (const mt_syscmd_tag, const std::string& cmd) {
    return SystemCall::call(cmd);
}

int main()
{
    // thread�� ������ �ʰ� ����: ������ thread safety
    syscmd << "dir";
    for (auto i = 0; i < 100; ++i) {
        syscmd << "dir";
    }

    // ���� thread���� ���� ������ thread safety
    mt_syscmd << "dir";
    for (auto i = 0; i < 100; ++i) {
        mt_syscmd << "dir";
    }

    return 0;
}