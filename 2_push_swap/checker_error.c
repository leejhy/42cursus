
#include "checker.h"

void	ft_check_error(char *str)
{
	if (ft_strcmp(str, "Error\n") == 0)
	{
		write(2, "Error\n", 1);
		exit (1);
	}
}
