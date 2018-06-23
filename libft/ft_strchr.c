/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 00:36:01 by alsomvil          #+#    #+#             */
/*   Updated: 2017/12/01 00:47:03 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
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
	while (tmps[i] != tmp)
	{
		i++;
		if (tmps[i] == '\0')
			return (NULL);
	}
	return (&tmps[i]);
}
