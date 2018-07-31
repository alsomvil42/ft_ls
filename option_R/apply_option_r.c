/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_option_r.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 22:58:04 by alsomvil          #+#    #+#             */
/*   Updated: 2018/07/30 11:05:36 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

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

char	**create_tab_test(char *namedoss, DIR *dirdoss, t_temp *saveoption)
{
	char	**tab;
	struct dirent	*ent;
	int		nb;
	int		i;
	char	*directiontemp;

	i = 0;
	nb = 0;
	tab = NULL;
	directiontemp = ft_strdup(namedoss);
	while ((ent = readdir(dirdoss)) != NULL)
		if (ent->d_name[0] != '.')
			nb++;
	tab = malloc(sizeof(char *) * (nb + 1));
	dirdoss = opendir(namedoss);
	while (i < nb && ((ent = readdir(dirdoss)) != NULL))
	{
		if (ent->d_name[0] != '.')
		{
			namedoss = forjoin(directiontemp, ent->d_name);
			tab[i] = ft_strdup(namedoss);
			free(namedoss);
			i++;
		}
	}
	free(directiontemp);
	closedir(dirdoss);
	tab[i] = NULL;
	tab = order_tab(tab, saveoption, 0, nb - 1);
	if (saveoption->r)
		tab = inversetab(tab);
	return (tab);
}

void	apply_option_r(char *tabdoss, t_temp *saveoption)
{
	int			i;
	int			ret;
	DIR			*dirp;
	char		**tab;
	struct stat	buf;

	i = 0;
	if (!saveoption->l)
		apply_small_option_doss(tabdoss, saveoption);
	else
		apply_next_doss(tabdoss, saveoption);
	if ((lstat(tabdoss, &buf) == 0) && S_ISDIR(buf.st_mode) == 1)
	{
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
}
