/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldamulel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 07:52:51 by ldamulel          #+#    #+#             */
/*   Updated: 2017/09/28 12:47:09 by ldamulel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_command(char **args)
{
	if (ft_strcmp("cd", args[0]) == 0)
		func_cd(args);
	else if (ft_strcmp("echo", args[0]) == 0)
		func_echo(args);
	else if (ft_strcmp("setenv", args[0]) == 0)
		g_env = set_env(g_env, args[1], args[2]);
	else if (ft_strcmp("unsetenv", args[0]) == 0)
		g_env = unset_env(g_env, args[1]);
	else if (ft_strcmp("env", args[0]) == 0)
		env_display(g_env);
	else
		launch_process(args);
}
