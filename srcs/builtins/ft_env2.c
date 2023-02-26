#include "../../minishell.h"

char	*ft_getenv(char *var, t_envp *envp_list)
{
	while (!ft_str_var_cmp(var, envp_list->var))
	{
		envp_list = envp_list->next;
		if (envp_list == NULL)
			return (NULL);
	}
	return (&envp_list->var[ft_pos_in_string(envp_list->var, '=') + 1]);
}
