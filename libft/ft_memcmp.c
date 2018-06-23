/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 07:40:58 by alsomvil          #+#    #+#             */
/*   Updated: 2017/11/30 07:58:36 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*tmps1;
	unsigned char	*tmps2;

	i = 0;
	tmps1 = (unsigned char *)s1;
	tmps2 = (unsigned char *)s2;
	while (i < n)
	{
		if (tmps1[i] == tmps2[i])
			i++;
		else
			return (tmps1[i] - tmps2[i]);
	}
	return (0);
}
