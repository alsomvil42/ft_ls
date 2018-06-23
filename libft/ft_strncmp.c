/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 03:33:16 by alsomvil          #+#    #+#             */
/*   Updated: 2017/12/01 03:53:02 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	j;

	j = 0;
	if (n == 0)
		return (0);
	while ((s1[j] == s2[j]) && s1[j] && s2[j] && j < n)
	{
		j++;
		if ((!s1[j] && !s2[j]) || j >= n)
			return (0);
	}
	return ((unsigned char)s1[j] - (unsigned char)s2[j]);
}
