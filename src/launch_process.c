/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldamulel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 07:55:40 by ldamulel          #+#    #+#             */
/*   Updated: 2017/09/28 10:28:48 by ldamulel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_err(char *name)
{
	ft_putstr("error: command not found: ");
	ft_putstr(name);
	ft_putendl(" ");
}

static void	run_new(char **args, char **envp)
{
	char	*path;

	if (access(args[0], F_OK) == -1)
	{
		path = found_in_path(args[0]);
		if (path != NULL)
		{
			execve(path, args, envp);
			ft_strdel(&path);
		}
		else
		{
			print_err(args[0]);
			exit(0);
		}
	}
	else
		execve(args[0], args, envp);
}

void		launch_process(char **args)
{
	pid_t	pid;
	int		stat;

	pid = fork();
	if (pid == 0)
	{
		run_new(args, g_env);
	}
	else if (pid < 0)
		ft_putendl("error could not start process");
	else
		waitpid(pid, &stat, WUNTRACED);
}
