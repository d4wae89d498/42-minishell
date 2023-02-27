/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraldi <egiraldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:06:39 by egiraldi          #+#    #+#             */
/*   Updated: 2023/02/27 09:10:27 by egiraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
				if (ft_redirect_(cmd, re, ft_redirect_in) == RETURN_ERROR)
					break ;
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
