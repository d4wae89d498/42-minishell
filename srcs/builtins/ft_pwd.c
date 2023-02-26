#include "../../minishell.h"

int	ft_pwd(t_data *data, t_command *cmd)
{
	ft_write_fd_nl(cmd->fd->out, &data->pwd[ft_pos_in_string
		(data->pwd, '=') + 1]);
	return (RETURN_SUCCESS);
}
