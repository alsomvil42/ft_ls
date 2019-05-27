/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_option_l_fich.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 15:38:21 by alsomvil          #+#    #+#             */
/*   Updated: 2018/08/15 00:06:30 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

char		***create_tab_l_fich(char **tab, t_temp *saveoption)
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

void		ft_affich_tab_fich(char ***tab_l, int i, int j, t_temp *saveoption)
{
	if (saveoption->mode == 1)
	{
		ft_putstr("total ");
		ft_putnbr(saveoption->totalblock);
		saveoption->totalblock = 0;
		ft_putstr("\n");
		saveoption->mode = 0;
	}
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

char		*modif_test(int nbchar, char *test)
{
	int		i;

	i = 0;
	while (i < nbchar)
		i++;
	test[i] = '\0';
	return (test);
}

struct stat	fill_tab_l_two(char ***tab_l, int j)
{
	struct stat	buf;
	char		test[1023];
	char		*lnk;
	int			nbchar;

	if (lstat(tab_l[0][j], &buf) == 0 && S_ISLNK(buf.st_mode))
	{
		nbchar = readlink(tab_l[0][j], test, 1023);
		lnk = ft_strjoin(tab_l[0][j], " -> ");
		free(tab_l[0][j]);
		tab_l[0][j] = ft_strjoin(lnk, modif_test(nbchar, test));
		free(lnk);
	}
	return (buf);
}

void		apply_option_l_fich(t_temp *saveoption)
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
		buf = fill_tab_l_two(tab_l, j);
		saveoption->totalblock = saveoption->totalblock + buf.st_blocks;
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
	freebigtab(tab_l);
}
