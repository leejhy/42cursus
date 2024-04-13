
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private :
		int					fp_number;//fixed point nb
		static const int	frac_bits = 8;
	public :
		Fixed();
		Fixed(const int fp_number);
		Fixed(const float fp_number);
		Fixed(const Fixed& fixed);
		Fixed& operator= (const Fixed& fixed);
		~Fixed();

		float	toFloat( void ) const;
		int		toInt( void ) const;
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		bool	operator> (const Fixed& fixed);
		bool	operator< (const Fixed& fixed);
		bool	operator>= (const Fixed& fixed);
		bool	operator<= (const Fixed& fixed);
		bool	operator== (const Fixed& fixed);
		bool	operator!= (const Fixed& fixed);
		float	operator+ (const Fixed& fixed);
		float	operator- (const Fixed& fixed);
		float	operator* (const Fixed& fixed);
		float	operator/ (const Fixed& fixed);
		Fixed&	operator++ (void);
		Fixed	operator++ (int);
		Fixed&	operator-- (void);
		Fixed	operator-- (int);

		static Fixed& 		min(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static Fixed& 		max(Fixed& a, Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif