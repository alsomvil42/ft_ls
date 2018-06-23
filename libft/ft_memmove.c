/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 00:51:02 by alsomvil          #+#    #+#             */
/*   Updated: 2017/11/30 07:04:18 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t		i;
	char		*tmpdest;
	const char	*tmpsrc;

	tmpdest = dest;
	tmpsrc = src;
	i = len;
	if (tmpsrc < tmpdest)
		while (i--)
			tmpdest[i] = tmpsrc[i];
	else
	{
		i = 0;
		while (i < len)
		{
			tmpdest[i] = tmpsrc[i];
			i++;
		}
	}
	return (tmpdest);
}
