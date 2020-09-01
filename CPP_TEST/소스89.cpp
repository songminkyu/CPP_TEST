#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>

struct MyData {
	std::string str{};
	int val{};
};

template <class _Elem, class _Traits>
auto& operator>>(std::basic_istream<_Elem, _Traits >& ss, MyData& data) {
	ss >> data.str;
	ss >> data.val;
	return ss;
}

template <class _Elem, class _Traits>
auto& operator<<(std::basic_ostream<_Elem, _Traits >& ss, const MyData& data) {
	ss << data.str;
	ss << ' ';
	ss << data.val;
	return ss;
}

int main() {
	// �Է����� ����ϱ�
	std::string text = "Let 10 split 20 into 30";
	std::istringstream iss(text);

	std::vector<MyData> results(std::istream_iterator<MyData>{iss},
		std::istream_iterator<MyData>());
	for (auto&& item : results) {
		std::cout << item.str << "," << item.val << std::endl;
	}
	// ������� ����ϱ�

	std::stringstream oss{};
	std::ostream_iterator<MyData> itr(oss, " ");
	for (auto&& item : results) {
		itr = item;
	}
	std::cout << oss.str();
}