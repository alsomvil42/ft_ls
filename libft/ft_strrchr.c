/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 00:48:03 by alsomvil          #+#    #+#             */
/*   Updated: 2017/12/01 00:56:12 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*tmps;
	char	tmp;

	i = 0;
	tmps = (char *)s;
	tmp = (const char)c;
	if (tmp == '\0')
	{
		while (tmps[i])
			i++;
		return (&tmps[i]);
	}
	while (tmps[i])
		i++;
	while (tmps[i] != tmp)
	{
		i--;
		if (i < 0)
			return (NULL);
	}
	return (&tmps[i]);
}
