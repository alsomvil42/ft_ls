/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:21:49 by alsomvil          #+#    #+#             */
/*   Updated: 2018/07/02 04:46:58 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**stock_arg(int ac, char **av, t_temp *saveoption)
{
	int		nb_doss;
	char	**tabdoss;
	int		i;

	i = 0;
	tabdoss = check_tab_doss(ac, av, saveoption);
	tabdoss = order_tab(tabdoss, saveoption);
	return (tabdoss);
}

void	check_option(char **av, t_temp *saveoption)
{
	int		i;

	i = 0;
	if (av[1] && av[1][0] == '-')
	{
		while (av[1][i])
		{
			if (av[1][i] == 'l')
				saveoption->l = 1;
			if (av[1][i] == 'r')
				saveoption->r = 1;
			if (av[1][i] == 'a')
				saveoption->a = 1;
			if (av[1][i] == 't')
				saveoption->t = 1;
			if (av[1][i] == 'R')
				saveoption->R = 1;
			i++;
		}
	}
}

void	initstruct(t_temp *saveoption)
{
	saveoption->l = 0;
	saveoption->r = 0;
	saveoption->a = 0;
	saveoption->t = 0;
	saveoption->R = 0;
	saveoption->lentab = 0;
}

int		main(int ac, char **av)
{
	t_info	info;
	t_temp	saveoption;
	char	**tabdoss;

	initstruct(&saveoption);
	saveoption.begin_info = &info;
	check_option(av, &saveoption);
	tabdoss = stock_arg(ac, av, &saveoption);
	if (!saveoption.l && !saveoption.R)
		apply_small_option(tabdoss, &saveoption);
	else if (!saveoption.R)
		apply_long_option(tabdoss, &saveoption);
	free(tabdoss);
	return (0);
}
