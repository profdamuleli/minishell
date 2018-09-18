/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldamulel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 07:54:44 by ldamulel          #+#    #+#             */
/*   Updated: 2017/09/28 12:10:42 by ldamulel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			**unset_env(char **info, char *key)
{
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (info[i])
		i++;
	tmp = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (info[i])
	{
		if (!((ft_strncmp(info[i], key, ft_strlen(key)) == 0)
					&& (info[i][ft_strlen(key)] == '=')))
			tmp[j++] = ft_strdup(info[i]);
		i++;
	}
	return (tmp);
}
