#include "../minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_data		data;

	(void) argc;
	(void) argv;
	if (!ft_initialize(&data, envp))
	{
		ft_set_parent_interactive();
		while (1)
		{
			data.r_line = readline(PROMPT);
			if (data.r_line == NULL)
				break ;
			if (ft_strlen(data.r_line) > 0)
				add_history(data.r_line);
			ft_parser(&data);
			if ((ft_do_valid_redirections(&data) == RETURN_SUCCESS) 
				&& (ft_cycle_cmd(&data) == RETURN_EXIT))
					break ;
			ft_wait_for_kids(&data);
			free((void *) data.r_line);
			ft_delete_cmd(&data.c_line);
		}
	}
	else
	{
		printf("Allocation error.\n");
		data.errnum = 1;
	}
	ft_clear_mem(&data);
	return (data.errnum);
}

void	ft_clear_mem(t_data *data)
{
	t_command	*tmp;

	ft_delete_list(&data->envp);
	if (data->c_line)
	{
		tmp = ft_last_cmd(data->c_line);
		data->errnum = tmp->errnum;
		ft_delete_cmd(&data->c_line);
	}
	rl_clear_history();
	free((void *) data->pwd);
	if (data->r_line)
		free((void *) data->r_line);
	else
		ft_write_fd(STDOUT_FILENO, "exit\n");
}

void	ft_wait_for_kids(t_data *data)
{
	t_command	*tmp;
	int			status;

	if (!data->c_line)
		return ;
	tmp = data->c_line;
	status = 0;
	while (tmp)
	{
		if (tmp->pid != 0 && waitpid(tmp->pid, &status, 0) != RETURN_ERROR)
		{
			if (WIFEXITED(status))
				tmp->errnum = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				tmp->errnum = 128 + WTERMSIG(status);
		}
		tmp = tmp->next;
	}
	tmp = ft_last_cmd(data->c_line);
	data->errnum = tmp->errnum;
	ft_set_parent_interactive();
}

int	ft_initialize(t_data *data, char **envp)
{
	char	*output;
	t_envp	*tmp_envp;

	data->c_line = NULL;
	data->r_line = NULL;
	data->errnum = 0;
	data->envp = ft_copy_envp(envp);
	if (!data->envp)
		return (1);
	tmp_envp = ft_get_envp_element(data->envp, "PATH");
	if (!tmp_envp && ft_change_envp(data, DEFAULT_PATH))
			return (1);
	tmp_envp = ft_get_envp_element(data->envp, "PWD");
	if (!tmp_envp)
	{
		output = (char *) malloc(BUFFER_SIZE);
		if (!output)
			return (1);
		getcwd(output, BUFFER_SIZE);
		output = ft_realloc("PWD=", output, 0, 1);
		if (!output)
			return (1);
		data->pwd = output;
		if (ft_change_envp(data, output))
			return (1);
	}
	else
	{
		data->pwd = ft_string_dup(tmp_envp->var);
		if (!(data->pwd))
			return (0);
	}
	return (ft_change_envp(data, "SHELL=EZIO & MARC MINISHELL!"));
}

int	ft_cycle_cmd(t_data *data)
{
	t_command	*cmd;
	int			result;

	ft_set_parent_active();
	cmd = data->c_line;
	while (cmd)
	{
		if (cmd->result == RETURN_SUCCESS && cmd->cmd)
		{
			if (cmd->next)
				ft_create_pipe(cmd);
			result = ft_build_in_exe(cmd, data);
			if (result == RETURN_EXIT)
				return (RETURN_EXIT);
			if (result == RETURN_FALSE)
				ft_do_execve(cmd, data);
		}
		else if (cmd->result == RETURN_SUCCESS && !cmd->cmd)
			return (ft_print_error(cmd, ERR_SYNTAX, ""));
		ft_close_pipe(cmd);
		cmd = cmd->next;
	}
	return (RETURN_SUCCESS);
}
