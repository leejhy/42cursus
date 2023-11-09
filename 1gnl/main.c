#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("43_with_nl", O_RDWR);
	str = get_next_line(fd);
	printf("%s", str);
	// free(str);
	// str = get_next_line(fd);
	// printf("%s", str);

}