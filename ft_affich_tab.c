/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affich_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 08:41:14 by alsomvil          #+#    #+#             */
/*   Updated: 2018/06/29 04:05:58 by alsomvil         ###   ########.fr       */
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
	char	***tab;
	int		len;
	int		lenfill;
	int		i;
	int		j;

	i = 0;
	j = 0;
	lenfill = 0;
	tab = saveoption->bigtab;
	len = search_big_len(tab);
	//printf("%d\n", len);
	while (tab[i][j])
	{
		while (i < 3)
		{
			if (tab[i][j])
			{
				lenfill = ft_strlen(tab[i][j]);
				ft_putstr(tab[i][j]);
				while (lenfill++ < len)
					ft_putchar(' ');
			}
			i++;
		}
		i = 0;
		j++;
		printf("\n");
	}
}
