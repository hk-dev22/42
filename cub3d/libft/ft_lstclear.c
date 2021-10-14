/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 18:37:17 by hkortbi           #+#    #+#             */
/*   Updated: 2020/11/22 18:37:19 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *node;

	if (!lst || !del)
		return ;
	while (*lst != NULL)
	{
		node = (*lst)->next;
		ft_lstdelone((*lst), del);
		(*lst) = node;
	}
}
