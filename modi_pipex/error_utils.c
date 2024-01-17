
#include "pipex_bonus.h"
#include "pipex.h"

int	check_cmd(char **cmd)
{
	char	*str;
	size_t	i;

	i = 0;
	if (cmd == NULL)
		return (1);
	str = cmd[0];
	if (*str == '\0')
		return (1);
	while (str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}