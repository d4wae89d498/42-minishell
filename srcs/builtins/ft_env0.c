#include "../../minishell.h"

t_envp	*ft_copy_envp(char **envp)
{
	t_envp	*output;
	int		i;

	output = ft_lstnew(envp[0]);
	if (!output)
		return (0);
	i = 1;
	while (envp[i])
	{
		if (!ft_lstadd_back(&output, ft_lstnew(envp[i])))
		{
			ft_delete_list(&output);
			return (0);
		}
		i++;
	}
	return (output);
}

t_envp	*ft_lstnew(char *content)
{
	t_envp	*new_element;

	new_element = (t_envp *) malloc(sizeof(t_envp));
	if (!new_element)
		return (NULL);
	new_element->var = ft_string_dup(content);
	new_element->next = NULL;
	return (new_element);
}

t_envp	*ft_lstlast(t_envp *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

t_envp	*ft_lstadd_back(t_envp **lst, t_envp *new)
{
	if (!*lst)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
	return (new);
}

void	ft_delete_list(t_envp **lst)
{
	t_envp	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free((void *) tmp->var);
		free((void *) tmp);
	}
	*lst = NULL;
}
