#include "../../minishell.h"

void	ft_err_cd_folder(t_command *cmd, char *token)
{
	ft_write_fd(cmd->fd->err, cmd->cmd);
	ft_write_fd(cmd->fd->err, ": ");
	ft_write_fd(cmd->fd->err, token);
	ft_write_fd(cmd->fd->err, ": No such file or directory\n");
	cmd->errnum = 1;
}

void	ft_err_else(t_command *cmd, int errnum)
{
	ft_write_fd(cmd->fd->err, cmd->cmd);
	ft_write_fd(cmd->fd->err, ": ");
	ft_write_fd_nl(cmd->fd->err, strerror(errnum));
	cmd->errnum = errnum;
}

void	ft_err_fd(t_command *cmd, char *token)
{
	ft_write_fd(cmd->fd->err, token);
	ft_write_fd(cmd->fd->err, ": No such file or directory\n");
	cmd->errnum = 1;
}

void	ft_err_file(t_command *cmd)
{
	ft_write_fd(cmd->fd->err, cmd->cmd);
	ft_write_fd(cmd->fd->err, ": No such file or directory\n");
	cmd->errnum = 127;
}
