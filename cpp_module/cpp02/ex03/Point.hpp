
#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private :
		Fixed const x;
		Fixed const y;
	public :
		Point();
		Point(float x, float y);
		Point(const Point &point);
		Point& operator=(const Point& point);

		Fixed const&	getX(void) const;//멤버변수가 const 객체여서 const함수여야함
		Fixed const&	getY(void) const;//
		~Point();
};

bool	bsp( Point const a, Point const b, Point const c, Point const point);
#endif