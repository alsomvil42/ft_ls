/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affich_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 08:41:14 by alsomvil          #+#    #+#             */
/*   Updated: 2018/07/02 04:59:04 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		search_big_len(char ***tab)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = 0;
	while (tab[i])
	{
		while (tab[i][j])
		{
			if (ft_strlen(tab[i][j]) > len)
			{
				len = ft_strlen(tab[i][j]);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (len + 1);
}

void	ft_affich_tab(t_temp *saveoption)
{
	int		len;
	int		lenfill;
	int		i;
	int		j;

	i = 0;
	j = -1;
	lenfill = 0;
	len = search_big_len(saveoption->bigtab);
	while (saveoption->bigtab[i][++j])
	{
		while (i < 3)
		{
			if (saveoption->bigtab[i][j])
			{
				lenfill = ft_strlen(saveoption->bigtab[i][j]);
				ft_putstr(saveoption->bigtab[i][j]);
				while (lenfill++ < len)
					ft_putchar(' ');
			}
			i++;
		}
		i = 0;
		printf("\n");
	}
}
