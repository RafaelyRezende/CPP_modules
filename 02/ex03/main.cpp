#include <iostream>
#include "Point.h"

int main(void) {
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(0.0f, 10.0f);
	
	Point inside(1.0f, 1.0f);
	Point outside(10.0f, 10.0f);
	Point onEdge(5.0f, 0.0f);
	Point vertex(0.0f, 0.0f);
	
	std::cout << "Triangle: A(0,0), B(10,0), C(0,10)" << std::endl;
	std::cout << "Inside (1,1):   " << bsp(a, b, c, inside) << std::endl;
	std::cout << "Outside (10,10):" << bsp(a, b, c, outside) << std::endl;
	std::cout << "On edge (5,0):  " << bsp(a, b, c, onEdge) << std::endl;
	std::cout << "On vertex (0,0):" << bsp(a, b, c, vertex) << std::endl;
	
	return 0;
}
