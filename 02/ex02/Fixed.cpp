#include "Fixed.h"
#include <cmath>

Fixed::Fixed() : _rawBits(0) {}

Fixed::Fixed(const int n) : _rawBits(n << _fractionalBits) {}

Fixed::Fixed(const float f) : _rawBits(roundf(f * (1 << _fractionalBits))) {}

Fixed::Fixed(const Fixed& other) : _rawBits(other._rawBits) {}

Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other) {
		this->_rawBits = other._rawBits;
	}
	return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const {
	return this->_rawBits;
}

void Fixed::setRawBits(int const raw) {
	this->_rawBits = raw;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(this->_rawBits) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
	return this->_rawBits >> _fractionalBits;
}

// ------------------------------------------------------------------ //
// Comparison operators
// ------------------------------------------------------------------ //
bool Fixed::operator>(const Fixed& other) const {
	return this->_rawBits > other._rawBits;
}

bool Fixed::operator<(const Fixed& other) const {
	return this->_rawBits < other._rawBits;
}

bool Fixed::operator>=(const Fixed& other) const {
	return this->_rawBits >= other._rawBits;
}

bool Fixed::operator<=(const Fixed& other) const {
	return this->_rawBits <= other._rawBits;
}

bool Fixed::operator==(const Fixed& other) const {
	return this->_rawBits == other._rawBits;
}

bool Fixed::operator!=(const Fixed& other) const {
	return this->_rawBits != other._rawBits;
}

// ------------------------------------------------------------------ //
// Arithmetic operators
// ------------------------------------------------------------------ //
Fixed Fixed::operator+(const Fixed& other) const {
	Fixed result;
	result.setRawBits(this->_rawBits + other._rawBits);
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
	Fixed result;
	result.setRawBits(this->_rawBits - other._rawBits);
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
	Fixed result;
	long long temp = static_cast<long long>(this->_rawBits) * other._rawBits;
	result.setRawBits(static_cast<int>(temp >> _fractionalBits));
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
	Fixed result;
	long long temp = (static_cast<long long>(this->_rawBits) << _fractionalBits) / other._rawBits;
	result.setRawBits(static_cast<int>(temp));
	return result;
}

// ------------------------------------------------------------------ //
// Increment / decrement operators (smallest epsilon = 1 raw bit = 1/256)
// ------------------------------------------------------------------ //
Fixed& Fixed::operator++() {
	++this->_rawBits;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed old(*this);
	++this->_rawBits;
	return old;
}

Fixed& Fixed::operator--() {
	 --this->_rawBits;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed old(*this);
	--this->_rawBits;
	return old;
}

// ------------------------------------------------------------------ //
// Min / max
// ------------------------------------------------------------------ //
Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}

// ------------------------------------------------------------------ //
// Stream insertion operator
// ------------------------------------------------------------------ //
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}
