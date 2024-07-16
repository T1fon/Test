#pragma once
#include "TestingClass.hpp"

int main()
{
	double t_global;
	std::cout << "Print actual temperature (in C) " << std::endl;
	std::cin >> t_global;
	Test1 test1(t_global);
	test1.startTest(0.01, 1);

	std::cout << std::endl;

	Test2 test2(t_global);
	test2.startTest(0.01, 1);
}