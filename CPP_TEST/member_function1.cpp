#include <iostream>
#include <type_traits>
#include <functional>

struct B { 

	int f() 
	{
		std::cout << "hellow world" << std::endl;
		return 0;
	} 

};

struct L: B{};
struct R : B {};
struct D : L,R {};

int main()
{

	B b;
	L l;
	R r;
	D d;


	int(B:: * pb)() = &B::f;
	//pb�κ��� ������ ��� �����͸� �����Ѵ�.

	int(L:: * pl)() = pb;
	int(R:: * pr)() = pb;

	int(D:: * pdl)() = pl;
	int(D:: * pdr)() = pr;

	std::cout << std::boolalpha;
	
	//�ɹ� ������ �� ������ true�ΰ��
	//(pd�� ���� �Ҵ� ���� pl�� pr�� pb�� ����.)	
	std::cout << (pl == pb) << "," << (pr == pb) << std::endl;

	//�ɹ� ������ �� ������ true�ΰ��
	//(pd�κ��� ����(pl �Ǵ� pr�� ������) �Ҵ� ���� pdl�� pdr�� ���� �ٸ���.)
	std::cout << (pdl == pdr) << std::endl;

	auto _pb = (b.*pb)();

	auto _pl = (l.*pb)();
	auto _pr = (r.*pb)();

	auto _pdl = (d.*pl)();
	auto _pdr = (d.*pr)();
	
	return 0;


}