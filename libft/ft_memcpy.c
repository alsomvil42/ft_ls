/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:15:22 by alsomvil          #+#    #+#             */
/*   Updated: 2017/11/24 20:27:55 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*tmpdest;
	char	*tmpsrc;

	i = 0;
	tmpdest = (char *)dest;
	tmpsrc = (char *)src;
	while (i < n)
	{
		tmpdest[i] = tmpsrc[i];
		i++;
	}
	return (dest);
}
