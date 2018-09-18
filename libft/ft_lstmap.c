/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldamulel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 14:15:41 by ldamulel          #+#    #+#             */
/*   Updated: 2017/07/20 14:15:43 by ldamulel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*lnk;

	if (lst)
	{
		lnk = f(lst);
		lnk->next = ft_lstmap(lst->next, f);
		return (lnk);
	}
	return (NULL);
}
