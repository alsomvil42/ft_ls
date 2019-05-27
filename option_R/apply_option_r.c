/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_option_r.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 22:58:04 by alsomvil          #+#    #+#             */
/*   Updated: 2018/08/15 00:07:46 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*forjoin(char *dir, char *name)
{
	char	*forfree;
	char	*namedoss;

	if (ft_strcmp(dir, "/") != 0)
		forfree = ft_strjoin(dir, "/");
	else
		forfree = ft_strdup(dir);
	namedoss = ft_strjoin(forfree, name);
	free(forfree);
	return (namedoss);
}

void	create_tab_test_two(t_temp *saveoption, char *directiontemp,
		char **tab, char *namedoss)
{
	int				i;
	struct dirent	*ent;
	DIR				*dirdoss;

	dirdoss = opendir(namedoss);
	i = 0;
	while (i < saveoption->nb && ((ent = readdir(dirdoss)) != NULL))
	{
		if (ent->d_name[0] != '.' ||
				(saveoption->a && ft_strcmp(ent->d_name, ".") != 0
				&& ft_strcmp(ent->d_name, "..") != 0))
		{
			namedoss = forjoin(directiontemp, ent->d_name);
			tab[i] = ft_strdup(namedoss);
			i++;
			free(namedoss);
		}
	}
	tab[i] = NULL;
	free(directiontemp);
	closedir(dirdoss);
}

char	**create_tab_test(char *namedoss, DIR *dirdoss, t_temp *saveoption)
{
	char			**tab;
	struct dirent	*ent;
	int				nb;
	char			*directiontemp;
	struct stat		buf;

	nb = 0;
	tab = NULL;
	directiontemp = ft_strdup(namedoss);
	while ((ent = readdir(dirdoss)) != NULL)
		if (ent->d_name[0] != '.' || (saveoption->a &&
					ft_strcmp(ent->d_name, ".") != 0 &&
					ft_strcmp(ent->d_name, "..") != 0))
			nb++;
	saveoption->nb = nb;
	tab = malloc(sizeof(char *) * (nb + 1));
	create_tab_test_two(saveoption, directiontemp, tab, namedoss);
	tab = order_tab(tab, saveoption, 0, nb - 1);
	if (saveoption->t)
		tab = test_before_order_two("", tab, saveoption, nb);
	if (saveoption->r)
		tab = inversetab(tab);
	return (tab);
}

void	apply_option_r_two(char **tab, struct stat buf,
		t_temp *saveoption, char *tabdoss)
{
	DIR		*dirp;
	int		i;

	i = 0;
	dirp = opendir(tabdoss);
	if (dirp == NULL)
		return ;
	tab = create_tab_test(tabdoss, dirp, saveoption);
	while (tab[i])
	{
		lstat(tab[i], &buf);
		if (S_ISDIR(buf.st_mode))
		{
			ft_putstr("\n");
			ft_putstr(tab[i]);
			ft_putstr(":\n");
			apply_option_r(tab[i], saveoption);
		}
		i++;
	}
	freetab(tab);
	closedir(dirp);
}

void	apply_option_r(char *tabdoss, t_temp *saveoption)
{
	int			i;
	int			ret;
	char		**tab;
	struct stat	buf;
	DIR			*dir;

	i = 0;
	if (!saveoption->l)
	{
		apply_small_option_doss(tabdoss, saveoption);
	}
	else
		apply_next_doss(tabdoss, saveoption);
	if ((lstat(tabdoss, &buf) == 0) && S_ISDIR(buf.st_mode) == 1 &&
			(dir = opendir(tabdoss)) != NULL)
	{
		apply_option_r_two(tab, buf, saveoption, tabdoss);
		closedir(dir);
	}
}
