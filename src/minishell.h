/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldamulel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 07:59:23 by ldamulel          #+#    #+#             */
/*   Updated: 2017/09/28 12:36:11 by ldamulel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include "../libft/libft.h"

char	**g_env;
void	env_dup(void);
void	env_display(char **s);
char	**str_split(char *str, char d);
void	mem_for_str_split(char ***result, char *str, char deleimiter);
void	del_strs(char ***strs);
void	resize_str(char **str, size_t new_size);
void	get_input(char **input);

char	get_char(void);

void	func_cd(char **args);
void	func_env(char **args);
void	func_echo(char **args);

char	**get_path(void);
char	*found_in_path(char *name);

void	execute_command(char **args);
void	launch_process(char **args);

char	**set_env(char **info, char *key, char *value);
char	**unset_env(char **info, char *key);
char	*get_name(char *var);
char	*get_value(char *var);
void	print_environ(void);

#endif
