/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_small_option_fich.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 03:08:30 by alsomvil          #+#    #+#             */
/*   Updated: 2018/07/30 16:36:27 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	createbigtab(int nb, char **tabfich, t_temp *saveoption)
{
	int			i;
	int			j;
	int			k;
	char		***bigtab;

	i = 0;
	j = 0;
	k = 0;
	bigtab = malloc(sizeof(char **) * 4);
	while (i < 3)
		bigtab[i++] = malloc(sizeof(char *) * (nb + 1));
	bigtab[i] = NULL;
	i = 0;
	while (tabfich[k])
	{
		while (j < nb && tabfich[k])
			bigtab[i][j++] = ft_strdup(tabfich[k++]);
		while (j < nb)
			bigtab[i][j++] = NULL;
		bigtab[i][j] = NULL;
		j = 0;
		i++;
	}
	while (i < 3)
	{
		while (j < nb)
			bigtab[i][j++] = NULL;
		j = 0;
		i++;
	}
	affich_big_tab_doss(bigtab);
	freebigtab(bigtab);
}

void	apply_small_option_fich(char **tabfich, t_temp *saveoption)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (tabfich[nb])
		nb++;
	if (nb != 0)
	{
		if (nb % 3 > 0)
			nb = (nb / 3) + 1;
		else
			nb = nb / 3;
		createbigtab(nb, tabfich, saveoption);
	}
}
