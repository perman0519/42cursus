#include<iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main(void) {
    Point a(-2.0f, -5.0f);
    Point b(-4.0f, 1.0f);
    Point c(2.0f, 7.0f);

    Point P1(3.0f, 3.0f);
    Point P2(10.0f, 10.0f);
    Point P3(2.0f, 2.00f);
    Point P4(-1.0f, 4.0f);
    Point P5(-1.0f, -1.00f);
    Point P6(-2.0f, 1.00f);

    std::cout << bsp(a,b,c,P1) << std::endl;
    std::cout << bsp(a,b,c,P2) << std::endl;
    std::cout << bsp(a,b,c,P3) << std::endl;
	std::cout << bsp(a,b,c,P4) << std::endl;
	std::cout << bsp(a,b,c,P5) << std::endl;
	std::cout << bsp(a,b,c,P6) << std::endl;
    return 0;
}