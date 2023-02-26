#include "../../minishell.h"

int	ft_first_cmd(t_command *cmd, t_data *data)
{
	if (cmd != data->c_line)
		return (0);
	return (1);
}

t_command	*ft_last_cmd(t_command *cmd)
{
	t_command	*tmp;

	tmp = cmd;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
