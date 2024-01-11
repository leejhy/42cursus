
#include "pipex.h"

int	ft_open(char *filename, int option)
{
	int	fd;

	fd = open(filename, option);
	if (fd == -1)
		ft_error(errno);
	return (fd);
}