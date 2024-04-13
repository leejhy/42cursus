
#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(float x, float y) : x(x), y(y){}

Point::Point(const Point &point) : x(point.x), y(point.y){}

Point& Point::operator= (const Point& point){(void)point; return *this;}

Point::~Point(){}

Fixed const& Point::getX(void) const {
	return (this->x);
}

Fixed const& Point::getY(void) const {
	return (this->y);
}
