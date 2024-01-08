#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>


//pipex.c

//pipex_utils.c
size_t	ft_strlen(char *str)
//error.c
void	ft_error(int errno);

#endif