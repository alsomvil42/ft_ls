/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:21:49 by alsomvil          #+#    #+#             */
/*   Updated: 2018/08/15 00:57:44 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		check_exist_option(char *av, int i, t_temp *saveoption)
{
	if (av[i] && LETTER || LETTERTWO)
	{
		if (av[i] == '\0')
		{
			ft_putstr("ERREUR");
			return (2);
		}
		while (av[i])
		{
			if (NOTLETTER && NOTLETTERTWO)
				return (put_message(av[i]));
			else if (av[i] == '\0')
			{
				saveoption->nboption++;
				return (0);
			}
			i++;
		}
		saveoption->nboption++;
	}
	else
		return (put_message(av[i]));
	return (0);
}

int		check_option(char **av, t_temp *saveoption, int i, int j)
{
	while (av[j] && av[j][i] == '-')
	{
		if (check_exist_option(av[j], i + 1, saveoption) == 1)
			return (1);
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
				saveoption->big_r = 1;
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

void	initstruct(t_temp *saveoption)
{
	saveoption->l = 0;
	saveoption->r = 0;
	saveoption->a = 0;
	saveoption->t = 0;
	saveoption->big_r = 0;
	saveoption->mode = 0;
	saveoption->nboption = 0;
	saveoption->nbfich = 0;
	saveoption->nbdoss = 0;
	saveoption->fail = 0;
	saveoption->totalblock = 0;
	saveoption->lenfill = 0;
	saveoption->len = 0;
	saveoption->tabdoss = NULL;
	saveoption->tabfail = NULL;
	saveoption->forfree = NULL;
	saveoption->tabfich = NULL;
	saveoption->tab_l = NULL;
	saveoption->direction = NULL;
	saveoption->directiontemp = NULL;
	saveoption->nb = 0;
}

void	pasdeplace(t_temp *saveoption, int i)
{
	if (saveoption->l && saveoption->nbfich > 0)
		apply_option_l_fich(saveoption);
	else if (saveoption->nbfich > 0)
		apply_small_option_fich(saveoption->tabfich, saveoption);
	if (saveoption->nbfich > 0 && saveoption->nbdoss > 0)
		ft_putstr("\n");
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
	if (check_option(av, &saveoption, 0, 1) == 1)
		return (0);
	check_tab_doss(saveoption.nboption + 1, ac, av, &saveoption);
	if (saveoption.l && !saveoption.big_r)
		apply_option_l(ac, &saveoption);
	if (!saveoption.l && !saveoption.big_r)
		apply_small_option(ac, &saveoption);
	else if (saveoption.big_r)
		pasdeplace(&saveoption, i);
	freesave(&saveoption);
	initstruct(&saveoption);
	return (0);
}
