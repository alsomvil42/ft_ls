/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 00:03:37 by alsomvil          #+#    #+#             */
/*   Updated: 2017/11/26 22:24:26 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	tmp;
	unsigned char	*tmpdest;
	unsigned char	*tmpsrc;

	i = 0;
	tmp = (unsigned char)c;
	tmpdest = (unsigned char *)dest;
	tmpsrc = (unsigned char *)src;
	while (i < n)
	{
		tmpdest[i] = tmpsrc[i];
		if (tmpsrc[i] == tmp)
			return (tmpdest + i + 1);
		i++;
	}
	return (NULL);
}
