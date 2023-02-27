#include "../minishell.h"

static int	ft_set_pwd(t_data *data)
{
	char	*output;

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
	return (0);
}

static int	ft_initialize(t_data *data, char **envp)
{
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
	if (!tmp_envp && ft_set_pwd(data))
		return (1);
	else
	{
		data->pwd = ft_string_dup(tmp_envp->var);
		if (!(data->pwd))
			return (1);
	}
	return (ft_change_envp(data, "SHELL=EZIO & MARC MINISHELL!"));
}

// TODO : fixme
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

int	main(int argc, char **argv, char **envp)
{
	t_data		data;

	(void) argc;
	(void) argv;
	if (!ft_initialize(&data, envp))
	{
		ft_set_parent_interactive();
		ft_read_loop(&data);
	}
	else
	{
		printf("Allocation error.\n");
		data.errnum = 1;
	}
	ft_clear_mem(&data);
	return (data.errnum);
}
