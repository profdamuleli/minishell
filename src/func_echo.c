/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldamulel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 07:57:48 by ldamulel          #+#    #+#             */
/*   Updated: 2017/09/28 10:26:34 by ldamulel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		echo_env(char *arg)
{
	char	*str;

	str = get_value(arg);
	if (str != NULL)
		ft_putstr(str);
}

static void		func_print(char **args, int i, int k)
{
	while (args[i] != NULL)
	{
		k = 0;
		if (args[i][0] == '$')
			echo_env(&(args[i][1]));
		while (args[i][k] != '\0' && args[i][0] != '$')
		{
			if (args[i] == args[0])
				i++;
			write(1, &args[i][k], 1);
			k++;
		}
		write(1, " ", 1);
		i++;
	}
}

static void		echo_loop(char **args, int k)
{
	while (args[1][k] != '\0')
	{
		write(1, &args[1][k], 1);
		k++;
	}
}

static int		check_args(char **args)
{
	if (args[1] == NULL)
	{
		ft_putchar('\n');
		return (1);
	}
	return (-1);
}

void			func_echo(char **args)
{
	int				i;
	int				k;

	k = 0;
	i = 1;
	if (check_args(args) == 1)
		return ;
	else
	{
		if (args[1] && !(args[2]))
		{
			if (ft_strcmp(args[1], "-n") == 0)
				return ;
			if (args[1][0] == '$')
				echo_env(&args[1][1]);
			else
				echo_loop(args, k);
		}
		else
			func_print(args, i, k);
	}
	if (ft_strcmp(args[1], "-n") != 0)
		write(1, "\n", 1);
}
