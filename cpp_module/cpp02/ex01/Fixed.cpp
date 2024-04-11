
#include "Fixed.hpp"

// Fixed();
// 	~Fixed();
// 	Fixed(const Fixed &fixed);
// 	Fixed &operator= (const Fixed &fixed);

Fixed::Fixed() : fp_number(0){
	std::cout << "Default constructor called" << std::endl;
	// this->fp_number = 0;
}

Fixed::Fixed(const int fp_number){
	std::cout << "Int constructor called" << std::endl;
	this->fp_number = fp_number * (1 << this->frac_bits);//sign 비트 때문에 1 << 8 한 뒤에 곱하기
}

Fixed::Fixed(const float fp_number){
	//float로 들어온거 비트연산해서 int에 저장?
	std::cout << "Float constructor called" << std::endl;
	this->fp_number = fp_number * (1 << this->frac_bits);//sign 비트 때문에 1 << 8 한 뒤에 곱하기
	//float값을 int에다가 값 손실 없이 저장하기위함
}

Fixed::Fixed(const Fixed& fixed){
	std::cout << "Copy constructor called" << std::endl;
	// *this = fixed;
	this->fp_number = fixed.getRawBits();
}

Fixed &Fixed::operator=(const Fixed& fixed){
	std::cout << "Copy assignment operator called" << std::endl;
	this->fp_number = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits( void ) const{
	return (this->fp_number);
}

void	Fixed::setRawBits( int const raw ){
	this->fp_number = raw;
}

float	Fixed::toFloat( void ) const{
	//this->fp_number to float;
	float	tmp;

	tmp = (float)this->fp_number / (1 << this->frac_bits);
	// std::cout << "toFloat ";
	return (tmp);
}

int		Fixed::toInt( void ) const{
	int	tmp;

	tmp = this->fp_number / (1 << this->frac_bits);
	return (tmp);
}

std::ostream& operator<< (std::ostream& os, const Fixed& fixed){
	int	tmp;

	tmp = fixed.toInt();
	os << tmp;
	return (os);
}