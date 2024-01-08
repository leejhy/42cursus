
#include "pipex.h"

void	ft_error(int err)
{
	char *str;

	str = strerror(err);
	write(1, str, ft_strlen(str));
	exit(1);
}
