#include <iostream>


/*

�̰��� ������ �ſ���. �̷� �ڵ��� ��� �����ϴ���.. ����
 ���� ���� ������ 3�� ���� ��Ȯ�ϰ� �˰� ���� ���� ������ �ڵ�...
TYPE:action ���·� Ư�� Ÿ�԰� action�� ������ �ð��� �������ִ� ���.

����� �ڵ��� 13��.. std::cout�� �ٲٴ��� 25��..


������ �ð����� �����ϰ� ������ �ð��� ����Ѵٸ� ����~ 
����� �ڵ��� ���� ��� ����� ����� ��ó�� �����ִ� 
����(����ȭ�� ģȭ���� ����).

�׷����� ������ �ð��� deterministic function composition�� ����� ���ϳ��� ����������~
*/

class tag;

template<class>
struct type { friend constexpr auto get(type); };

template< class TKey, class TValue>
struct set { friend constexpr auto get(TKey) { return TValue{}; } };

void foo() {
	if constexpr(false)
		if (false) {
			constexpr auto call = [](auto value) {std::cout << "called " << value; };
			void(set<type<tag>, decltype(call)>{ });
		}
}

int main()
{
	get(type<tag>{})(42);
}