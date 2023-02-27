/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraldi <egiraldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 08:59:24 by egiraldi          #+#    #+#             */
/*   Updated: 2023/02/27 09:10:27 by egiraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

size_t	ft_replace_in_string(char *s, char c_replace, char c_with)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s == c_replace)
		{
			*s = c_with;
			count++;
		}
		s++;
	}
	return (count);
}
