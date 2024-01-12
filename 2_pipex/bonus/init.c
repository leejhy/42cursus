
#include "pipex_bonus.h"

int	**init_pipe(int argc, char **argv, int *prc_cnt)
{
	int	**fds;
	int	i;

	i = 0;
	if (strncmp(argv[1], "here_doc", 8) == 0)
		*prc_cnt = argc - 4;
	else
		*prc_cnt = argc - 3;
	fds = malloc(sizeof(int *) * prc_cnt);
	if (!fds)
		malloc_failed();
	while (i < prc_cnt)
	{
		fds[i] = malloc(sizeof(int) * 2);
		if (!fds[i])
			malloc_failed();
		i++;
	}
	return (fds);
}
