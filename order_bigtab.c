/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_bigtab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 07:43:17 by alsomvil          #+#    #+#             */
/*   Updated: 2018/07/03 01:01:10 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	***order_tab_nor(int i, int j, char ***tab, char *temp)
{
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j + 1] && ft_strcmp(tab[i][j], tab[i][j + 1]) > 0)
			{
				ft_swap_char(&tab[i][j], &tab[i][j + 1]);
				j = 0;
				i = 0;
			}
			else
				j++;
		}
		if (tab[i + 1] && tab[i][j - 1] && tab[i + 1][0]
				&& ft_strcmp(tab[i][j - 1], tab[i + 1][0]) > 0)
		{
			ft_swap_char(&tab[i][j - 1], &tab[i + 1][0]);
			j = 0;
			i = 0;
		}
		else
			i++;
	}
	return (tab);
}

char	***order_tab_r(int i, int j, char ***tab, char *temp)
{
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j + 1] && ft_strcmp(tab[i][j], tab[i][j + 1]) < 0)
			{
				ft_swap_char(&tab[i][j], &tab[i][j + 1]);
				j = 0;
				i = 0;
			}
			else
				j++;
		}
		if (tab[i + 1] && tab[i][j - 1] && tab[i + 1][0]
				&& ft_strcmp(tab[i][j - 1], tab[i + 1][0]) < 0)
		{
			ft_swap_char(&tab[i][j - 1], &tab[i + 1][0]);
			j = 0;
			i = 0;
		}
		else
			i++;
	}
	return (tab);
}

void	order_bigtab(t_temp *saveoption, char *temptab)
{
	char	***tab;
	char	*temp;
	int		i;
	int		j;

	tab = saveoption->bigtab;
	i = 0;
	j = 0;
	if (saveoption->r == 1)
		tab = order_tab_r(i, j, tab, temp);
	else
		tab = order_tab_nor(i, j, tab, temp);
	saveoption->bigtab = tab;
	ft_affich_tab(saveoption, i, j, temptab);
	free(saveoption->bigtab);
}
