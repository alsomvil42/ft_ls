/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 02:45:17 by alsomvil          #+#    #+#             */
/*   Updated: 2017/12/01 03:32:15 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	j;

	j = 0;
	while ((s1[j] == s2[j]) && s1[j] && s2[j])
		j++;
	if (!s1[j] && !s2[j])
		return (0);
	return ((unsigned char)s1[j] - (unsigned char)s2[j]);
}
