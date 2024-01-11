#include "pipex.h"

int	main(void)
{
	int		fd;
	char	*file;

	file = "test11";
	if (access((file), F_OK) == 0)
		fd = open(file, O_TRUNC);
	printf("%d\n", fd);
}
