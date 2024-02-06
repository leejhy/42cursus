
#include "executing.h"

t_info	*init_info(void)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
	{
		printf("malloc failed\n");
		exit(1);
	}
	info->exitcode = 0;
	return (info);
}

t_pipe	*init_vars(void)
{
	t_pipe	*vars;

	vars = malloc(sizeof(t_pipe));
	if (!vars)
	{
		printf("malloc failed\n");
		exit(1);
	}
	vars->exe_argv = 0;
	vars->exe_envp = 0;
	vars->prev_pipe[0] = -1;
	vars->prev_pipe[1] = -1;
	return (vars);
}