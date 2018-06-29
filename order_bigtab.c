/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_bigtab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 07:43:17 by alsomvil          #+#    #+#             */
/*   Updated: 2018/06/29 08:03:11 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	order_bigtab(t_temp *saveoption)
{
	char	***tab;
	char	*temp;
	int		i;
	int		j;

	tab = saveoption->bigtab;
	i = 0;
	while (tab[i])
	{
		j = 0;
		if (saveoption->r == 1)
		{
			while (tab[i][j])
			{
				if (tab[i][j + 1] && ft_strcmp(tab[i][j], tab[i][j + 1]) < 0)
				{
					temp = tab[i][j + 1];
					tab[i][j + 1] = tab[i][j];
					tab[i][j] = temp;
					j = 0;
					i = 0;
				}
				else
					j++;
			}
			if (tab[i + 1] && tab[i][j - 1] && tab[i + 1][0] && ft_strcmp(tab[i][j - 1], tab[i + 1][0]) < 0)
			{
				temp = tab[i][j - 1];
				tab[i][j - 1] = tab[i + 1][0];
				tab[i + 1][0] = temp;
				j = 0;
				i = 0;
			}
			else
				i++;
		}
		else
		{
			while (tab[i][j])
			{
				if (tab[i][j + 1] && ft_strcmp(tab[i][j], tab[i][j + 1]) > 0)
				{
					temp = tab[i][j + 1];
					tab[i][j + 1] = tab[i][j];
					tab[i][j] = temp;
					j = 0;
					i = 0;
				}
				else
					j++;
			}
			if (tab[i + 1] && tab[i][j - 1] && tab[i + 1][0] && ft_strcmp(tab[i][j - 1], tab[i + 1][0]) > 0)
			{
				temp = tab[i][j - 1];
				tab[i][j - 1] = tab[i + 1][0];
				tab[i + 1][0] = temp;
				j = 0;
				i = 0;
			}
			else
				i++;
		}
	}
	saveoption->bigtab = tab;
}
