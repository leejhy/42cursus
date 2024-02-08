/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include_header.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/07 21:09:56 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_HEADER_H
# define INCLUDE_HEADER_H
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <termios.h>
# include <sys/ioctl.h>

# define SAVE_MODE 0
# define LOAD_MODE 1
# define PROMPT "binishell$ "
# define PROMPT_ERROR "binishell: "

#endif
