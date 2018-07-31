/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:21:49 by alsomvil          #+#    #+#             */
/*   Updated: 2018/07/30 16:22:02 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	stock_arg(int ac, char **av, t_temp *saveoption)
{
	int		i;

	i = 0;
	check_tab_doss(i, ac, av, saveoption);
}

void	check_option(char **av, t_temp *saveoption)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (av[j] && av[j][i] == '-')
	{
		saveoption->nboption++;
		while (av[j][i])
		{
			if (av[j][i] == 'l')
				saveoption->l = 1;
			if (av[j][i] == 'r')
				saveoption->r = 1;
			if (av[j][i] == 'a')
				saveoption->a = 1;
			if (av[j][i] == 't')
				saveoption->t = 1;
			if (av[j][i] == 'R')
				saveoption->R = 1;
			i++;
		}
		i = 0;
		j++;
	}
}

void	initstruct(t_temp *saveoption)
{
	saveoption->l = 0;
	saveoption->r = 0;
	saveoption->a = 0;
	saveoption->t = 0;
	saveoption->R = 0;
	saveoption->nboption = 0;
	saveoption->nbfich = 0;
	saveoption->nbdoss = 0;
	saveoption->fail = 0;
	saveoption->totalblock = 0;
	saveoption->lenfill = 0;
	saveoption->len = 0;
	saveoption->tabdoss = NULL;
	saveoption->tabfich = NULL;
	saveoption->tab_l = NULL;
}

void	pasdeplace(t_temp *saveoption, int i)
{
	if (saveoption->l)
		apply_option_l_fich(saveoption);
	else
		apply_small_option_fich(saveoption->tabfich, saveoption);
	while (saveoption->tabdoss[i])
	{
		if (saveoption->nbfich > 0 || saveoption->nbdoss > 1)
		{
			ft_putstr(saveoption->tabdoss[i]);
			ft_putstr(":\n");
		}
		apply_option_r(saveoption->tabdoss[i++], saveoption);
		if (saveoption->tabdoss[i])
			ft_putstr("\n");
	}
}

int		main(int ac, char **av)
{
	t_temp	saveoption;
	int		i;

	i = 0;
	initstruct(&saveoption);
	check_option(av, &saveoption);
	stock_arg(ac, av, &saveoption);
	if (saveoption.l && !saveoption.R)
		apply_option_l(ac, &saveoption);
	else if (!saveoption.l && !saveoption.R)
		apply_small_option(ac, &saveoption);
	else if (saveoption.R)
	{
		pasdeplace(&saveoption, i);
	}
	freesave(&saveoption);
	initstruct(&saveoption);
	return (0);
}
