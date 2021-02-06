/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 13:55:46 by hkortbi           #+#    #+#             */
/*   Updated: 2020/11/22 13:55:48 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *node;

	if (!alst || !new)
		return ;
	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	node = *alst;
	while (node->next != NULL)
		node = node->next;
	node->next = new;
}
