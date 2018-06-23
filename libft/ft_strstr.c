/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 00:57:34 by alsomvil          #+#    #+#             */
/*   Updated: 2017/12/01 02:35:13 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	int		temp;
	char	*temphay;

	i = 0;
	j = 0;
	temphay = (char *)haystack;
	if (needle[i] == '\0')
		return (temphay);
	while (temphay[j])
	{
		if (needle[i] == temphay[j])
		{
			temp = j;
			while (needle[i++] == temphay[j++])
				if (needle[i] == '\0')
					return (&temphay[temp]);
			j = temp;
			i = 0;
		}
		j++;
	}
	return (NULL);
}
