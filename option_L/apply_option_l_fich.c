/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_option_l_fich.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 15:38:21 by alsomvil          #+#    #+#             */
/*   Updated: 2018/07/21 15:18:29 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	***create_tab_l_fich(char **tab, t_temp *saveoption)
{
	int				i;
	int				j;
	char			***tab_l;

	i = 0;
	j = 0;
	tab_l = malloc(sizeof(char **) * 8);
	while (i < 7)
		tab_l[i++] = malloc(sizeof(char *) * (saveoption->nbfich + 1));
	tab_l[i] = NULL;
	i = 0;
	while (i < 7)
	{
		while (j < saveoption->nbfich)
		{
			tab_l[0][j] = ft_strdup(tab[j]);
			j++;
		}
		tab_l[i++][j] = NULL;
	}
	return (tab_l);
}

void	affich_all(int i, int j, char ***tab_l, t_temp *saveoption)
{
	if (i > 5)
	{
		ft_putstr(tab_l[i][j]);
		while (saveoption->lenfill++ < saveoption->len)
			ft_putchar(' ');
	}
	else if (i > 0 && i < 6)
	{
		while (saveoption->lenfill++ < saveoption->len)
			ft_putchar(' ');
		ft_putstr(tab_l[i][j]);
	}
	else
	{
		ft_putchar(' ');
		ft_putstr(tab_l[i][j]);
	}
}

void	ft_affich_tab_fich(char ***tab_l, int i, int j, t_temp *saveoption)
{
	while (tab_l[0][++j])
	{
		while (i >= 0)
		{
			saveoption->len = search_big_len_l(tab_l[i]);
			if (tab_l[i][j])
			{
				saveoption->lenfill = ft_strlen(tab_l[i][j]);
				affich_all(i, j, tab_l, saveoption);
			}
			i--;
		}
		i = 6;
		ft_putchar('\n');
	}
}

void	apply_option_l_fich(t_temp *saveoption)
{
	int			i;
	int			j;
	struct stat	buf;
	char		***tab_l;

	i = 0;
	j = 0;
	tab_l = create_tab_l_fich(saveoption->tabfich, saveoption);
	while (tab_l[0][j])
	{
		lstat(tab_l[0][j], &buf);
		tab_l[1][j] = creation_date(&buf);
		tab_l[2][j] = block_allocated(&buf);
		tab_l[3][j] = group_id(&buf);
		tab_l[4][j] = user_id(&buf);
		tab_l[5][j] = nb_node(&buf);
		tab_l[6][j] = checkdroits(&buf);
		tab_l[7] = NULL;
		j++;
	}
	ft_affich_tab_fich(tab_l, 6, -1, saveoption);
	j = 0;
	i = 0;
	while (tab_l[i])
	{
		while (tab_l[i][j])
			free(tab_l[i][j++]);
		j = 0;
		i++;
	}
	i = 0;
	while (tab_l[i])
		free(tab_l[i++]);
	free(tab_l);
}
