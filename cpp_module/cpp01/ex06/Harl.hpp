
#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

enum script{
	DEBUG = 1,
	INFO,
	WARNING,
	ERROR,
	ELSE
};

class Harl
{
	private :
		void	(Harl::*f[4])(void);
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
	public :
		void	complain(int level);
};

#endif