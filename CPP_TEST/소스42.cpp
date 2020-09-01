#include <iostream>
#include <concepts>


/*
�̷��� �ϸ� ������ bounded type-template parameter�� ����������.

�̷��� ���ø� �Ķ���Ϳ��� type-contraint���� immediately-declared constraint�� ����Ѵٰ� �Ѵ�.

���⼭ �����ܺ����� �κ��� �Ѱ��� �� �ִµ�, concept ���𿡼� ...Us�� �ְ�, ���ø��� ���� �� ... 
Ts�� �� �ִµ�, �� ... ������ ��� ���·� �ռ��Ǵ��� ������ ������ �Ѵ�. ���� ǥ�� �������� ������ �ڱ��ϴ� ��Ʈ �߿� �ϳ��� ... 
������ ������ ��� �����ұ�?��� �� �� �ִ�. ��ġ �� ���Ͱ��� ������ �����Ұų�, ������ ������ ����.. �ƴϸ� �� ���������� ������� Cartesian coordinate system�̳�..
*/
template<typename T, typename ...Us>
concept AcceptTypes = (std::is_same_v<Us, T> || ...);


struct AcceptType1 {};
struct AcceptType2 {};

template <AcceptTypes< AcceptType1, AcceptType2>>
struct S5{};

int main() {
	[[maybe_unsued]] S5< AcceptType1 > a; //ok
	[[maybe_unsued]] S5< AcceptType2 > b; //ok
	//S5<int >error1;					 //error
}
