#include "Point.h"

Point::Point() : _x(0), _y(0) {}

Point::Point(float const x, float const y) : _x(x), _y(y) {}

Point::Point(Point const& other) : _x(other._x), _y(other._y) {}

// _x and _y are const and cannot be reassigned after construction.
Point& Point::operator=(Point const& other) {
	(void)other;
	return *this;
}

Point::~Point() {}

Fixed const& Point::getX(void) const {
	return this->_x;
}

Fixed const& Point::getY(void) const {
	return this->_y;
}
