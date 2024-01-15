#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

pid_t	get_pid(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		exit(1);
	return (pid);
}
int	main(void)
{
	pid_t	pid;

	pid = get_pid();
	if (pid == 0)
		printf("hellllllo\n");
	if (pid > 0)
		printf("mother\n");
	r
}
