/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldamulel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 08:02:59 by ldamulel          #+#    #+#             */
/*   Updated: 2017/09/28 19:10:34 by ldamulel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	resize_str(char **str, size_t new_size)
{
	char	*tmp;

	tmp = str[0];
	str[0] = ft_strnew(new_size);
	if (str[0] != NULL)
	{
		ft_strcpy(str[0], tmp);
		ft_strdel(&tmp);
	}
}
