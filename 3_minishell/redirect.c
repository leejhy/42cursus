#include "minishell.h"

typedef struct s_token
{
	int		type;
	char	*value;
	char	*exp_value;
	int		is_ambiguous;
}	t_token;

typedef struct s_cmd
{
	t_list			*redirect;
	t_list			*simple_cmd;
	int				next_pipe;
}	t_cmd;

void	set_inredirect(t_token token)
{

}

int	main(void)
{//자식 프로세스 내에서 작동한다고 판단
	t_cmd	cmd;
	t_token token;

	token = cmd.redirect;
	set_inredirect(token);
}