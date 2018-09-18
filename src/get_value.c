/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldamulel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 08:32:31 by ldamulel          #+#    #+#             */
/*   Updated: 2017/09/28 12:38:20 by ldamulel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*get_value(char *var)
{
	int		i;
	int		sign;
	char	*tmp;

	i = 0;
	while (g_env[i] != '\0')
	{
		tmp = get_name(g_env[i]);
		if (ft_strcmp(tmp, var) == 0)
		{
			sign = ft_strlen(tmp) + 1;
			ft_strdel(&tmp);
			return (ft_strdup(&(g_env[i][sign])));
		}
		ft_strdel(&tmp);
		i++;
	}
	return (NULL);
}
