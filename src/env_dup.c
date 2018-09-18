/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldamulel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 12:41:40 by ldamulel          #+#    #+#             */
/*   Updated: 2017/09/28 10:25:29 by ldamulel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_dup(void)
{
	int				i;
	extern	char	**environ;

	i = 0;
	while (environ[i])
		i++;
	g_env = (char **)malloc(sizeof(char *) * i + 1);
	i = 0;
	while (environ[i])
	{
		g_env[i] = ft_strdup(environ[i]);
		i++;
	}
	g_env[i] = NULL;
}
