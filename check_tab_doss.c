/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tab_doss.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 16:34:58 by alsomvil          #+#    #+#             */
/*   Updated: 2018/07/05 04:14:41 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <fcntl.h>

char	**order_tab(char **tab, t_temp *saveoption)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		if (saveoption->r == 0)
			if (tab[i + 1] && ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				ft_swap_char(&tab[i + 1], &tab[i]);
				i = 0;
			}
			else
				i++;
		else if (saveoption->r == 1)
		{
			if (tab[i + 1] && ft_strcmp(tab[i], tab[i + 1]) < 0)
			{
				ft_swap_char(&tab[i + 1], &tab[i]);
				i = 0;
			}
			else
				i++;
		}
	}
	return (tab);
}

char	**check_tab_doss(int ac, char **av, t_temp *saveoption)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	while (av[i])
	{
		if (av[i] && (opendir(av[i]) != NULL || open(av[i], O_WRONLY) > 0))
			saveoption->lentab++;
		else if (av[i] && i != 1)
			printf("ls: %s: %s\n", av[i], "No such file or directory");
		i++;
	}
	i = 0;
	tab = malloc(sizeof(char *) * (saveoption->lentab + 2));
	if ((ac == 1 || (av[1] && av[1][0] == '-')) && ac < 3)
		tab[j++] = ft_strdup("./");
	if (av[1] && av[1][0] == '-')
		i++;
	i++;
	while (av[i])
	{
		if (av[i] && (opendir(av[i]) != NULL || open(av[i], O_WRONLY) > 0))
			tab[j++] = ft_strdup(av[i]);
		i++;
	}
	tab[j] = 0;
	return (tab);
}
