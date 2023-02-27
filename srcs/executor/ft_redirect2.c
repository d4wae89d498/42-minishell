#include "../../minishell.h"

void	ft_do_redirections(t_command *cmd, t_re *re)
{
	while (cmd)
	{
		re = cmd->re;
		while (re)
		{
			if (ft_strcmp(re->direct, "<"))
			{
				printf("a");
				if (ft_redirect_(cmd, re, ft_redirect_in) == RETURN_ERROR)
				{
					printf("b");

					break ;
				}
			}
			else if (ft_strcmp(re->direct, ">"))
			{
				if (ft_redirect_(cmd, re, ft_redirect_out) == RETURN_ERROR)
					break ;
			}
			else if (ft_strcmp(re->direct, ">>"))
			{
				if (ft_redirect_(cmd, re, ft_redirect_out_out) == RETURN_ERROR)
					break ;
			}
			re = re->next;
		}
		cmd = cmd->next;
	}
}
