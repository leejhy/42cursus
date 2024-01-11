#include "pipex.h"

int	main(void)
{
	int a = open("@2", O_RDWR);
	printf("%d\n", errno);
}