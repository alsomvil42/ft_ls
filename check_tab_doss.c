/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tab_doss.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 16:34:58 by alsomvil          #+#    #+#             */
/*   Updated: 2018/06/29 05:13:43 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**order_tab(char **tab, t_temp *saveoption)
{
	char	*temp;
	int		i;

	i = 0;
	temp = NULL;
	while (tab[i])
	{
		if (saveoption->r == 0)
		{
			if (tab[i + 1] && ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				temp = tab[i + 1];
				tab[i + 1] = tab[i];
				tab[i] = temp;
				i = 0;
			}
			else
				i++;
		}
		else if (saveoption->r == 1)
		{
			if (tab[i + 1] && ft_strcmp(tab[i], tab[i + 1]) < 0)
			{
				temp = tab[i + 1];
				tab[i + 1] = tab[i];
				tab[i] = temp;
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
		if (opendir(av[i]) != NULL)
			saveoption->lentab++;
		i++;
	}
	i = 0;
	tab = malloc(sizeof(char *) * (saveoption->lentab + 2));
	if ((ac == 1 || (av[1] && av[1][0] == '-')) && ac < 3)
		tab[j++] = ft_strdup("./");
	while (av[i])
	{
		if (opendir(av[i]) != NULL)
			tab[j++] = ft_strdup(av[i]);
		i++;
	}
	tab[j] = 0;
	return (tab);
}
