/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_big_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 16:09:39 by alsomvil          #+#    #+#             */
/*   Updated: 2018/07/12 00:41:11 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		search_big_len_l(char **tab)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (tab[i])
	{
		if (tab[i] && ft_strlen(tab[i]) > len)
			len = ft_strlen(tab[i]);
		i++;
	}
	return (len + 1);
}
