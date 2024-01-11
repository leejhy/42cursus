#include "pipex.h"

void	wait_process(int process_cnt)
{
	int	i;
	int status;

	i = 0;
	while (i < process_cnt)
	{
		if (wait(&status) == -1)
			ft_error(errno);
		i++;
	}
}