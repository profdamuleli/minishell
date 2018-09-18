/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldamulel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 07:58:09 by ldamulel          #+#    #+#             */
/*   Updated: 2017/09/28 10:27:25 by ldamulel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		*ft_realloc(void *ptr, int size, int new_size)
{
	void	*new;

	new = ft_memalloc(new_size);
	new = ft_memcpy(new, ptr, size);
	free(ptr);
	return (new);
}

void		get_input(char **input)
{
	int		ret;
	int		i;
	int		count;
	char	buf;

	i = 0;
	count = 1;
	*input = (char *)malloc(sizeof(char));
	while ((ret = read(0, &buf, 1)) && buf != '\n')
	{
		*(*input + i++) = buf;
		*input = (char *)ft_realloc(*input, count, count + 1);
		count++;
	}
	*(*input + i) = '\0';
}
