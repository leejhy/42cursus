
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
		Fixed &operator= (const Fixed& fixed);
		~Fixed();

		float	toFloat( void ) const;
		int		toInt( void ) const;
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif