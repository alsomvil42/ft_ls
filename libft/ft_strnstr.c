/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 02:38:43 by alsomvil          #+#    #+#             */
/*   Updated: 2017/12/06 07:43:44 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	size_t	j;
	int		temp;
	char	*temphay;

	i = 0;
	j = 0;
	temphay = (char *)haystack;
	if (needle[i] == '\0' || needle == haystack)
		return (temphay);
	while (temphay[j] && j < len)
	{
		if (needle[i] == temphay[j])
		{
			temp = j;
			while (temphay[j] && needle[i++] == temphay[j])
				if (j++ < len && needle[i] == '\0')
					return (&temphay[temp]);
			j = temp;
			i = 0;
		}
		j++;
	}
	return (NULL);
}
