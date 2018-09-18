/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldamulel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 07:58:35 by ldamulel          #+#    #+#             */
/*   Updated: 2017/09/28 10:28:23 by ldamulel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		**get_path(void)
{
	char		*tmp;
	char		**result;

	tmp = get_value("PATH");
	if (tmp != NULL)
	{
		result = str_split(tmp, ':');
		ft_strdel(&tmp);
		if (result != NULL)
			return (result);
	}
	return (NULL);
}
