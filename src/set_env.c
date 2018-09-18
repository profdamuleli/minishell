/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldamulel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 07:53:57 by ldamulel          #+#    #+#             */
/*   Updated: 2017/09/28 16:07:30 by ldamulel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int	func_count(char **info)
{
	int		i;

	i = 0;
	while (info[i])
		i++;
	return (i);
}

char		**set_env(char **info, char *key, char *value)
{
	char	*env_value;
	char	**ret;
	int		i;

	if (!key || !value)
		return (info);
	env_value = ft_strjoin(key, "=");
	i = -1;
	while (info[++i])
	{
		if (ft_strncmp(env_value, info[i], ft_strlen(env_value)) == 0)
		{
			free(info[i]);
			info[i] = ft_strjoin(env_value, value);
			free(env_value);
			return (info);
		}
	}
	ret = (char **)malloc(sizeof(char *) * (func_count(info) + 2));
	i = -1;
	while (info[++i])
		ret[i] = ft_strdup(info[i]);
	ret[i] = ft_strjoin(env_value, value);
	g_env = ret;
	return (ret);
}
