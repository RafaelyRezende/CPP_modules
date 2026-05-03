#include "Point.h"

static Fixed crossProduct(Point const& a, Point const& b, Point const& c) {
	return (b.getX() - a.getX()) * (c.getY() - a.getY()) - (b.getY() - a.getY()) * (c.getX() - a.getX());
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed d1 = crossProduct(a, b, point);
	Fixed d2 = crossProduct(b, c, point);
	Fixed d3 = crossProduct(c, a, point);
	
	bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
	
	// Strictly inside: all same sign and none exactly zero (not on edge or vertex)
	return !(has_neg && has_pos) && (d1 != 0) && (d2 != 0) && (d3 != 0);
}
