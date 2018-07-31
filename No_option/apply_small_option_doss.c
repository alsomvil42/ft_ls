/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_small_option_doss.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 03:09:45 by alsomvil          #+#    #+#             */
/*   Updated: 2018/07/30 16:37:09 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	affich_big_tab_doss(char ***bigtab)
{
	int		i;
	int		j;
	int		len;
	int		lenfill;

	i = 0;
	j = 0;
	lenfill = 0;
	while (bigtab[i])
	{
		len = search_big_len_l(bigtab[i]);
		if (len > lenfill)
			lenfill = len;
		i++;
	}
	i = 0;
	while (bigtab[i][j])
	{
		while (bigtab[i] && bigtab[i][j] && (len = ft_strlen(bigtab[i][j])))
		{
			ft_putstr(bigtab[i][j]);
			while (len < lenfill)
			{
				ft_putstr(" ");
				len++;
			}
			i++;
		}
		i = 0;
		ft_putstr("\n");
		j++;
	}
}

char	**order_after_bigtab(int nb, char *doss, t_temp *saveoption)
{
	DIR				*dirp;
	char			**tab;
	int				i;
	struct dirent	*ent;

	i = 0;
	dirp = opendir(doss);
	tab = malloc(sizeof(char *) * (nb + 1));
	while ((ent = readdir(dirp)) != NULL)
	{
		if (verifstat(doss, ent->d_name, saveoption) == 1)
			tab[i++] = ft_strdup(ent->d_name);
	}
	tab[i] = NULL;
	order_tab(tab, saveoption, 0, nb - 1);
	if (saveoption->r)
		tab = inversetab(tab);
	closedir(dirp);
	return (tab);
}

void	createbigtabdoss(int nb, char **tab, t_temp *saveoption)
{
	int				i;
	int				j;
	int				k;
	char			***bigtab;

	i = 0;
	k = 0;
	bigtab = malloc(sizeof(char **) * 4);
	while (i < 3)
		bigtab[i++] = malloc(sizeof(char *) * (nb + 1));
	bigtab[i] = NULL;
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < nb && tab[k])
		{
			bigtab[i][j++] = ft_strdup(tab[k++]);
		}
		while (j < nb)
			bigtab[i][j++] = NULL;
		bigtab[i][j] = NULL;
		i++;
	}
	saveoption->tab_l = bigtab;
}

void	apply_small_option_doss(char *doss, t_temp *saveoption)
{
	struct stat		buf;
	char			**tab;
	struct dirent	*ent;
	DIR				*dirp;
	int				nb;

	nb = 0;
	tab = NULL;
	if ((lstat(doss, &buf) == 0) && S_ISDIR(buf.st_mode))
	{
		dirp = opendir(doss);
		if (dirp == NULL)
		{
			ft_putstr("Access Denied\n");
			return ;
		}
		while ((ent = readdir(dirp)) != NULL)
		{
			if (verifstat(doss, ent->d_name, saveoption) == 1)
				nb++;
		}
		if (nb != 0)
		{
			tab = order_after_bigtab(nb, doss, saveoption);
			if (nb % 3 > 0)
				nb = (nb / 3) + 1;
			else
				nb = nb / 3;
			createbigtabdoss(nb, tab, saveoption);
			affich_big_tab_doss(saveoption->tab_l);
			freetab(tab);
			freebigtab(saveoption->tab_l);
		}
		closedir(dirp);
	}
}
