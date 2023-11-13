#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*str;
	fd = open("41_with_nl", O_RDWR);
	str = get_next_line(fd);//leak
	printf("%s", str);
	free(str);
	// while (i < 5)
	// {
	// 	str = get_next_line(fd);
	// 	// printf("%s", str);
	// 	free(str);
	// 	i++;
	// }
}
