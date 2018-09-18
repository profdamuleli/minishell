/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldamulel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 07:57:34 by ldamulel          #+#    #+#             */
/*   Updated: 2017/09/28 15:02:16 by ldamulel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_err(char *dir)
{
	ft_putstr("error: could not change to '");
	ft_putstr(dir);
	ft_putendl("' directory");
}

static void	change_dir(char *path)
{
	char	*pwd;

	pwd = ft_strnew(1024);
	getcwd(pwd, 1024);
	if (chdir(path) != 0)
		print_err(path);
	else
	{
		if (pwd != NULL)
		{
			set_env(g_env, "OLDPWD", pwd);
			ft_strdel(&pwd);
		}
		else
			unset_env(g_env, "OLDPWD");
	}
}

static void	handle_home(char **args)
{
	char	*home;
	char	*tmp;

	home = get_value("HOME");
	if (home != NULL)
	{
		if (args[1] == NULL || ft_strlen(args[1]) == 1)
			change_dir(home);
		else
		{
			tmp = ft_strjoin(home, "/");
			home = ft_strjoin(tmp, &(args[1][2]));
			change_dir(home);
			ft_strdel(&tmp);
		}
		ft_strdel(&home);
	}
}

void		func_cd(char **args)
{
	char	*last_dir;

	if (args[1] != NULL && args[1][0] != '~')
	{
		if (args[1][0] == '-')
		{
			last_dir = get_value("OLDPWD");
			ft_putendl(last_dir);
			if (last_dir == NULL)
				ft_putendl("error: OLDPWD not set");
			else
			{
				change_dir(last_dir);
				ft_strdel(&last_dir);
			}
		}
		else
			change_dir(args[1]);
	}
	else
		handle_home(args);
}
