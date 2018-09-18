/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_in_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldamulel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 07:56:45 by ldamulel          #+#    #+#             */
/*   Updated: 2017/09/28 10:25:58 by ldamulel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*join_strs(char *name, char *path)
{
	char	*tmp;
	char	*result;

	tmp = ft_strjoin(path, "/");
	result = ft_strjoin(tmp, name);
	ft_strdel(&tmp);
	return (result);
}

char		*found_in_path(char *name)
{
	char	**path;
	char	*tmp;
	int		i;
	int		found;

	path = get_path();
	i = 0;
	found = -1;
	if (path == NULL)
		return (NULL);
	while (path[i] != '\0')
	{
		tmp = join_strs(name, path[i]);
		found = access(tmp, F_OK);
		if (found != -1)
		{
			del_strs(&path);
			return (tmp);
		}
		ft_strdel(&tmp);
		i++;
	}
	del_strs(&path);
	return (NULL);
}
