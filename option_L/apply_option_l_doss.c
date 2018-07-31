/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_option_l_doss.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 16:17:05 by alsomvil          #+#    #+#             */
/*   Updated: 2018/07/30 17:14:55 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_affich_tab_l(t_temp *saveoption, int i, int j, int mode)
{
	int		len;
	int		lenfill;

	j = -1;
	i = 6;
	if (mode == 0)
	{
		ft_putstr("total ");
		ft_putnbr(saveoption->totalblock);
		ft_putchar('\n');
	}
	while (saveoption->tab_l[0][++j])
	{
		while (i >= 0)
		{
			len = search_big_len_l(saveoption->tab_l[i]);
			if (saveoption->tab_l[i][j])
			{
				lenfill = ft_strlen(saveoption->tab_l[i][j]);
				if (i > 5)
				{
					ft_putstr(saveoption->tab_l[i][j]);
					while (lenfill++ < len)
						ft_putchar(' ');
				}
				else if (i > 0 && i < 6)
				{
					while (lenfill++ < len)
						ft_putchar(' ');
					ft_putstr(saveoption->tab_l[i][j]);
				}
				else
				{
					ft_putchar(' ');
					ft_putstr(saveoption->tab_l[i][j]);
				}
			}
			i--;
		}
		i = 6;
		ft_putchar('\n');
	}
}

void	fill_tab_l(char *direction, char ***tab_l, t_temp *saveoption)
{
	int				j;
	struct stat		buf;
	char			*directiontemp;
	char			*forfree;
	char			test[20];
	char			*lnk;

	j = 0;
	directiontemp = ft_strdup(direction);
	saveoption->totalblock = 0;
	while (tab_l[0][j])
	{
		direction = ft_strjoin(directiontemp, "/");
		forfree = ft_strjoin(direction, tab_l[0][j]);
		free(direction);
		lstat(forfree, &buf);
		if (S_ISLNK(buf.st_mode))
		{
			readlink(forfree, test, 20);
			lnk = ft_strjoin(tab_l[0][j], " -> ");
			free(tab_l[0][j]);
			tab_l[0][j] = ft_strjoin(lnk, test);
			free(lnk);
		}
		free(forfree);
		saveoption->totalblock = saveoption->totalblock + buf.st_blocks;
		tab_l[1][j] = creation_date(&buf);
		tab_l[2][j] = block_allocated(&buf);
		tab_l[3][j] = group_id(&buf);
		tab_l[4][j] = user_id(&buf);
		tab_l[5][j] = nb_node(&buf);
		tab_l[6][j] = checkdroits(&buf);
		j++;
	}
	saveoption->tab_l = tab_l;
	ft_affich_tab_l(saveoption, 0, -1, 0);
	free(directiontemp);
}

void	create_tab_l(int nb, char *tab, t_temp *saveoption)
{
	DIR				*dirp;
	int				i;
	int				j;
	char			***tab_l;
	struct dirent	*ent;

	dirp = opendir(tab);
	i = 0;
	j = 0;
	tab_l = malloc(sizeof(char **) * 8);
	while (i < 7)
		tab_l[i++] = malloc(sizeof(char *) * (nb + 1));
	i = 0;
	while (i < 7)
	{
		while (j < nb && ((ent = readdir(dirp)) != NULL))
			if ((!saveoption->a && ent->d_name[0] != '.') || saveoption->a)
				tab_l[i][j++] = ft_strdup(ent->d_name);
		tab_l[i++][j] = NULL;
	}
	tab_l[i] = NULL;
	closedir(dirp);
	tab_l[0] = order_tab(tab_l[0], saveoption, 0, j - 1);
	if (saveoption->r)
		tab_l[0] = inversetab(tab_l[0]);
	fill_tab_l(tab, tab_l, saveoption);
	i = 0;
	j = 0;
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

int		verifstat(char *doss, char *name, t_temp *saveoption)
{
	struct stat	buf;
	char		*forfree;
	char		*temp;

	forfree = ft_strjoin(doss, "/");
	temp = ft_strjoin(forfree, name);
	if (lstat(temp, &buf) == 0 && (saveoption->a || (!saveoption->a && name[0] != '.')))
	{
		free(temp);
		free(forfree);
		return (1);
	}
	else
	{
		free(temp);
		free(forfree);
		return (0);
	}
	return (0);
}

void	apply_next_doss(char *tab, t_temp *saveoption)
{
	int				i;
	struct dirent	*ent;
	DIR				*dirp;
	int				nb;
	struct stat		buf;

	nb = 0;
	i = 0;
	if (saveoption->nbdoss > 0 && lstat(tab, &buf))
	{
		dirp = opendir(tab);
		if (dirp == NULL)
		{
			ft_putstr("Access denied\n");
			return ;
		}
		while ((ent = readdir(dirp)) != NULL)
			if (verifstat(tab, ent->d_name, saveoption) == 1)
				nb++;
		if (nb != 0)
		{
			create_tab_l(nb, tab, saveoption);
			free(ent);
		}
		nb = 0;
		i++;
		closedir(dirp);
	}
}

void	apply_option_l_doss(int ac, t_temp *saveoption)
{
	int		i;

	i = 0;
	while (saveoption->tabdoss[i])
	{
		if (ac > saveoption->nboption + 2)
		{
			ft_putstr(saveoption->tabdoss[i]);
			ft_putstr(":\n");
		}
		apply_next_doss(saveoption->tabdoss[i], saveoption);
		if (saveoption->tabdoss[i + 1])
			ft_putstr("\n");
		i++;
	}
}
