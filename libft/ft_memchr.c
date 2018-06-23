/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 07:04:36 by alsomvil          #+#    #+#             */
/*   Updated: 2017/11/30 07:40:30 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		tmp;
	const unsigned char	*tmps;

	i = 0;
	tmp = (unsigned char)c;
	tmps = s;
	while (i < n)
	{
		if (tmps[i] == tmp)
			return ((void *)&tmps[i]);
		i++;
	}
	return (NULL);
}
