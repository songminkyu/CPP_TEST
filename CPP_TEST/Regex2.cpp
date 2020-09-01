#include <iostream>
#include <regex>

int main()
{
    auto const regex = std::regex("(my|your) regex");

    auto const myText = std::string("A piece of text that contains my regex.");
    auto searchResults = std::smatch{};
    bool const myTextContainsRegex = std::regex_search(myText, searchResults, regex);

    std::cout << "position in searched text: " << searchResults.prefix().length() << '\n';
    // my ��� �ܾ ���° ��ġ�� �ִ��� Ȯ���Ҽ� ����.

}