#include <random>
#include <iostream>

/*
Produces random floating-point values i, 
uniformly distributed on the interval [a, b), 
that is, distributed according to the probability density function:
*/
int main()
{
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_real_distribution<> dis(1.0, 2.0);
	for (int n = 0; n < 10; ++n) {
		// Use dis to transform the random unsigned int generated by gen into a 
		// double in [1, 2). Each call to dis(gen) generates a new random double
		std::cout << dis(gen) << ' ';
	}
	std::cout << '\n';
}