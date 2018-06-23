/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 05:08:45 by alsomvil          #+#    #+#             */
/*   Updated: 2017/12/06 06:12:16 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*temp;
	void	*tempcont;

	if (!(temp = ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		temp->content = NULL;
		temp->content_size = 0;
	}
	else
	{
		if (!(tempcont = ft_memalloc(content_size)))
			return (NULL);
		ft_memcpy(tempcont, content, content_size);
		temp->content = tempcont;
		temp->content_size = content_size;
	}
	temp->next = NULL;
	return (temp);
}
