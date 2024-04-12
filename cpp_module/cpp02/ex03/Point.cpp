
#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(float x, float y) : x(x), y(y){}

Point::Point(const Point &point){
	*this = point;
}

Point& Point::operator= (const Point& point){
	return *this;
}
//이거어케함

Point::~Point(){}

Fixed const& Point::getX(void) const {
	return (this->x);
}

Fixed const& Point::getY(void) const {
	return (this->y);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point){
//abc넓이 구하고
//pab+ pbc+ pac가 abc보다 크면 끝 
//point 가 abc삼각형 내에 있으면 1, else 0(꼭짓점, edge에 있어도 0)
	float ax, ay, bx, by, cx, cy, px, py;
	float s1, s2, tmp_s;
	float tmp1, tmp2;
	ax = a.getX().toFloat();
	ay = a.getY().toFloat();
	bx = b.getX().toFloat();
	by = b.getY().toFloat();
	cx = c.getX().toFloat();
	cy = c.getY().toFloat();
	px = point.getX().toFloat();
	py = point.getY().toFloat();

	tmp1 = ax*by + bx*cy + cx*ay;
	tmp2 = ay*bx + by*cx + cy*ax;
	tmp_s = tmp1 - tmp2;
	if (tmp_s < 0)
		tmp_s *= -1;
	s1 = tmp_s / 2;

	tmp1 = px*by + bx*cy + cx*py;
	tmp2 = py*bx + by*cx + cy*px;
	tmp_s = tmp1 - tmp2;
	if (tmp_s < 0)
		tmp_s *= -1;
	s2 = tmp_s / 2;

	tmp1 = px*ay + ax*by + bx*py;
	tmp2 = py*ax + ay*bx + by*px;
	tmp_s = tmp1 - tmp2;
	if (tmp_s < 0)
		tmp_s *= -1;
	s2 += (tmp_s / 2);

	tmp1 = px*ay + ax*cy + cx*py;
	tmp2 = py*ax + ay*cx + cy*px;
	tmp_s = tmp1 - tmp2;
	if (tmp_s < 0)
		tmp_s *= -1;
	s2 += (tmp_s / 2);
	if (s2 != s1)//밖이면 무조건 큼, 내부면 무조건 같음
		return (false);
	//edge도 같은데 tmp1 , tmp2중 하나라도 0이면 edge or 꼭지점임
	return (true);
}