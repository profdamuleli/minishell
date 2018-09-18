/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldamulel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 07:59:06 by ldamulel          #+#    #+#             */
/*   Updated: 2017/09/28 11:25:31 by ldamulel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(void)
{
	char		**args;
	char		*line;

	env_dup();
	while (1)
	{
		ft_putstr("$> ");
		get_input(&line);
		args = str_split(line, ' ');
		if (ft_strlen(line) > 0 && args[0] != NULL)
		{
			if (ft_strcmp(args[0], "exit") == 0)
			{
				ft_strdel(&line);
				del_strs(&args);
				return (0);
			}
			execute_command(args);
			ft_strdel(&line);
			del_strs(&args);
		}
	}
	return (0);
}
