/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldamulel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 07:58:21 by ldamulel          #+#    #+#             */
/*   Updated: 2017/09/28 15:29:43 by ldamulel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*get_name(char *var)
{
	int		i;
	char	*name;

	i = 0;
	while (var[i] != '\0' && var[i] != '=')
		i++;
	name = (char *)malloc(sizeof(char) * (i + 1));
	if (name == NULL)
		return (NULL);
	i = 0;
	while (var[i] != '\0' && var[i] != '=')
	{
		name[i] = var[i];
		i++;
	}
	name[i] = '\0';
	return (name);
}
