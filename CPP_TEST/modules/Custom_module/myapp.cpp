import util;

/*
��� ����� ���

https://devblogs.microsoft.com/cppblog/cpp-modules-in-visual-studio-2017/

�ڼ��� ������ Advenced_module �� �ҽ� ����
cl /EHsc /std:c++latest /MD /c /experimental:module cst_mdl.ixx

cl /EHsc /std:c++latest /MD /experimental:module /module:reference util.ifc cst_mdl.obj myapp.cpp

*/
int main()
{
	std::cout << "sum from 1 to 10 is " <<
		sum(1, 2, 3, 4, 5, 6, 7, 8, 10)
		<< std::endl;

	return 0;
}