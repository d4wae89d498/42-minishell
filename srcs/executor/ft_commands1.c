/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraldi <egiraldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 08:59:53 by egiraldi          #+#    #+#             */
/*   Updated: 2023/02/27 09:10:27 by egiraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
