
#include "Fixed.hpp"

// Fixed();
// 	~Fixed();
// 	Fixed(const Fixed &fixed);
// 	Fixed &operator= (const Fixed &fixed);

Fixed::Fixed() : fp_number(0){
	// std::cout << "Default constructor called" << std::endl;
	// this->fp_number = 0;
}

Fixed::Fixed(const int fp_number){
	// std::cout << "Int constructor called" << std::endl;
	this->fp_number = fp_number * (1 << this->frac_bits);//sign 비트 때문에 1 << 8 한 뒤에 곱하기
}

Fixed::Fixed(const float fp_number){
	//float로 들어온거 비트연산해서 int에 저장?
	// std::cout << "Float constructor called" << std::endl;
	this->fp_number = roundf(fp_number * (1 << this->frac_bits));//sign 비트 때문에 1 << 8 한 뒤에 곱하기
	//float값을 int에다가 값 손실 없이 저장하기위함
	//반올림 해서 저장?
}

Fixed::Fixed(const Fixed& fixed){
	// std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed& Fixed::operator=(const Fixed& fixed){
	// std::cout << "Copy assignment operator called" << std::endl;
	this->fp_number = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed(){
	// std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits( void ) const{
	return (this->fp_number);
}

void	Fixed::setRawBits( int const raw ){
	this->fp_number = raw;
}

float	Fixed::toFloat( void ) const{
	float	tmp;

	tmp = (float)this->fp_number / (1 << this->frac_bits);
	return (tmp);
}

int		Fixed::toInt( void ) const{
	int	tmp;

	tmp = this->fp_number / (1 << this->frac_bits);
	return (tmp);
}

std::ostream& operator<< (std::ostream& os, const Fixed& fixed){
	os << fixed.toFloat();
	return (os);
}

bool	Fixed::operator>(const Fixed& fixed){
	// 나랑 이후에 들어온 객체랑 연산함
	return (this->getRawBits() > fixed.getRawBits());
}

bool	Fixed::operator< (const Fixed& fixed){
	return (this->getRawBits() < fixed.getRawBits());
}

bool	Fixed::operator>= (const Fixed& fixed){
	return (this->getRawBits() >= fixed.getRawBits());
}

bool	Fixed::operator<= (const Fixed& fixed){
	return (this->getRawBits() <= fixed.getRawBits());
}

bool	Fixed::operator== (const Fixed& fixed){
	if (this->getRawBits() == fixed.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!= (const Fixed& fixed){
	return (this->getRawBits() != fixed.getRawBits());
}

float	Fixed::operator+ (const Fixed& fixed){
	float tmp;

	tmp = this->toFloat() + fixed.toFloat();
	return (tmp);
}

float	Fixed::operator- (const Fixed& fixed){
	float tmp;

	tmp = this->toFloat() - fixed.toFloat();
	return (tmp);
}

float	Fixed::operator* (const Fixed& fixed){
	float tmp;

	tmp = this->toFloat() * fixed.toFloat();
	return (tmp);
}

float	Fixed::operator/ (const Fixed& fixed){
	float tmp;

	tmp = this->toFloat() / fixed.toFloat();
	return (tmp);
}

Fixed&	Fixed::operator++ (void){//전위
	this->fp_number += 1;
	return *this;
}

Fixed	Fixed::operator++ (int){//후위
	Fixed	tmp(*this);

	this->fp_number += 1;
	return tmp;
}

Fixed&	Fixed::operator-- (void){
	this->fp_number -= 1;
	return *this;
}

Fixed	Fixed::operator-- (int){
	Fixed	tmp(*this);

	this->fp_number -= 1;
	return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b){
	if (a.getRawBits() > b.getRawBits())
		return b;
	return a;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b){
	if (a.getRawBits() > b.getRawBits())
		return b;
	return a;
}

Fixed& Fixed::max(Fixed& a, Fixed& b){
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b){
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}
