/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 13:58:32 by alsomvil          #+#    #+#             */
/*   Updated: 2017/12/04 14:12:03 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		len;
	int		i;
	char	*tab;

	len = 0;
	i = 0;
	while (s[len])
		len++;
	len++;
	if (!(tab = malloc(sizeof(char) * len)))
		return (NULL);
	while (s[i])
	{
		tab[i] = f(s[i]);
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
