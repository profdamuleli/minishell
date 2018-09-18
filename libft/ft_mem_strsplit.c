/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_strsplit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldamulel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 08:01:58 by ldamulel          #+#    #+#             */
/*   Updated: 2017/09/28 20:05:53 by ldamulel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	count_strs(char *str, char delimiter, int *strs, int *i)
{
	char	c;

	if (str[i[0]] != '\'' && str[i[0]] != '"')
	{
		(strs[0])++;
		while (str[i[0]] != '\0' && str[i[0]] != delimiter)
			(i[0])++;
	}
	else
	{
		c = str[(i[0])++];
		(strs[0])++;
		while (str[i[0]] != '\0' && str[i[0]] != c)
			(i[0])++;
		(i[0])++;
	}
}

static void	alloc_mem_for_2d_arr(char ***result, char *str, char delimiter)
{
	int	strs;
	int	i;

	i = 0;
	strs = 0;
	while (str[i] != '\0')
	{
		if (str[i] != delimiter)
			count_strs(str, delimiter, &strs, &i);
		else
			i++;
	}
	result[0] = (char**)malloc(sizeof(char*) * strs + 1);
	result[0][strs] = (char*)'\0';
}

static void	count_chars(char ***res, char *str, int *strs, int *l)
{
	int		chars;
	char	c;

	c = str[(l[0])++];
	chars = 0;
	while (str[l[0]] != '\0' && str[(l[0])++] != c)
		chars++;
	(l[0])++;
	res[0][strs[0]] = ft_strnew(chars);
	(strs[0])++;
}

static void	alloc_mem_for_strings(char ***result, char *str, char delimiter)
{
	int		i;
	int		string;
	int		chars;

	i = 0;
	string = 0;
	while (str[i] != '\0')
	{
		if (str[i] != delimiter)
		{
			if (str[i] != '"' && str[i] != '\'')
			{
				chars = 0;
				while (str[i] != '\0' && str[i++] != delimiter)
					chars++;
				result[0][string] = ft_strnew(chars);
				string++;
			}
			else
				count_chars(result, str, &string, &i);
		}
		else
			i++;
	}
}

void		mem_split(char ***result, char *str, char delimiter)
{
	alloc_mem_for_2d_arr(result, str, delimiter);
	if (result[0] != NULL)
		alloc_mem_for_strings(result, str, delimiter);
}
