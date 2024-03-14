#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char *argv[])
{
	int	fd;

	if (argc != 2)
		return (0);
	fd = open("./test.cub", O_RDONLY);
	if (fd < 0)
		return (0);
	printf("%s\n", argv[1]);
	return (0);
}
