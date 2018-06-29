/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:21:49 by alsomvil          #+#    #+#             */
/*   Updated: 2018/06/29 04:57:07 by alsomvil         ###   ########.fr       */
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
	/*while (tabdoss[i])
	{
		printf("%s\n", tabdoss[i]);
		i++;
	}*/
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
	apply_option(tabdoss, &saveoption);
	free(tabdoss);
	return (0);
}
