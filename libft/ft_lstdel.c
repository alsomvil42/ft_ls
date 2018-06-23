/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 06:25:32 by alsomvil          #+#    #+#             */
/*   Updated: 2017/12/06 06:37:44 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;
	t_list	*destroy;

	temp = *alst;
	while (temp != NULL)
	{
		destroy = temp->next;
		ft_lstdelone(&temp, del);
		temp = destroy;
	}
	*alst = NULL;
}
