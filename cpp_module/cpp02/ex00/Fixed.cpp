
#include "Fixed.hpp"

// Fixed();
// 	~Fixed();
// 	Fixed(const Fixed &fixed);
// 	Fixed &operator= (const Fixed &fixed);

Fixed::Fixed() : fp_number(0){
	std::cout << "Default constructor called" << std::endl;
	// this->fp_number = 0;
}

Fixed::Fixed(const Fixed &fixed){
	std::cout << "Copy constructor called" << std::endl;
	// *this = fixed;
	this->fp_number = fixed.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &fixed){
	std::cout << "Copy assignment operator called" << std::endl;
	this->fp_number = fixed.getRawBits();
	//this의 fp_number를 b의값으로 대체함
	return (*this);//this의 주소를 역참조해서 reference로 리턴시킨다
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fp_number);
}

void	Fixed::setRawBits( int const raw ){
	this->fp_number = raw;
}