#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		fd2;
	char	*str;
	fd = open("41_with_nl", O_RDWR);
	str = get_next_line(fd);//leak
	printf("%s", str);
	free(str);
	fd2 = open("43_with_nl", O_RDWR);
	str = get_next_line(fd2);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	//printf("%s", str);
	free(str);
}
