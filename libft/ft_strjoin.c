/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:59:45 by alsomvil          #+#    #+#             */
/*   Updated: 2018/01/13 00:06:48 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	j++;
	i = i + j;
	j = 0;
	if (!(temp = malloc(sizeof(char) * i)))
		return (NULL);
	i = 0;
	while (s1[j])
	{
		temp[j] = s1[j];
		j++;
	}
	while (s2[i])
		temp[j++] = s2[i++];
	temp[j] = '\0';
	return (temp);
}
