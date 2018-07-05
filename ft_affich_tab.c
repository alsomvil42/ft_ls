/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affich_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 08:41:14 by alsomvil          #+#    #+#             */
/*   Updated: 2018/07/05 06:42:20 by alsomvil         ###   ########.fr       */
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
		if (ft_strlen(tab[i]) > len)
			len = ft_strlen(tab[i]);
		i++;
	}
	return (len + 1);
}

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
		j = 0;
		while (tab[i][j])
		{
			if (ft_strlen(tab[i][j]) > len)
				len = ft_strlen(tab[i][j]);
			j++;
		}
		i++;
	}
	return (len + 1);
}

void	ft_affich_tab_l(t_temp *saveoption, int i, int j, char *tab)
{
	int		len;
	int		lenfill;

	j = -1;
	i = 6;
	printf("total %d\n", saveoption->totalblock);
	while (saveoption->tab_l[0][++j])
	{
		while (i >= 0)
		{
			len = search_big_len_l(saveoption->tab_l[i]);
			if (saveoption->tab_l[i][j])
			{
				lenfill = ft_strlen(saveoption->tab_l[i][j]);
				if (i > 5)
				{
					ft_putstr(saveoption->tab_l[i][j]);
					while (lenfill++ < len)
						ft_putchar(' ');
				}
				else if (i > 0 && i < 6)
				{
					while (lenfill++ < len)
						ft_putchar(' ');
					ft_putstr(saveoption->tab_l[i][j]);
				}
				else
				{
					ft_putchar(' ');
					ft_putstr(saveoption->tab_l[i][j]);
				}
			}
			i--;
		}
		i = 6;
		ft_putchar('\n');
	}
}

void	ft_affich_tab(t_temp *saveoption, int i, int j, char *tab)
{
	int		len;
	int		lenfill;

	j = -1;
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
		ft_putchar('\n');
	}
}
