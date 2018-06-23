/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 06:07:23 by alsomvil          #+#    #+#             */
/*   Updated: 2017/12/06 07:31:51 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t res;

	i = 0;
	j = 0;
	res = 0;
	if (!(size))
		return (ft_strlen(src));
	while (dst[i] && res < size)
	{
		res++;
		i++;
	}
	while (src[j] && i < size - 1)
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	if (res < size)
		dst[i] = '\0';
	return (res + ft_strlen(src));
}
