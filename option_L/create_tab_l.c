/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab_l.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 23:01:41 by alsomvil          #+#    #+#             */
/*   Updated: 2018/08/15 00:25:22 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

char		*modif_test_two(int nbchar, char *test)
{
	int		i;

	i = 0;
	while (i < nbchar)
		i++;
	test[i] = '\0';
	return (test);
}

struct stat	fill_tab_l_three(char ***tab_l, char *direction, int j)
{
	struct stat	buf;
	char		test[1023];
	char		*lnk;
	int			nbchar;

	if (lstat(direction, &buf) == 0 && S_ISLNK(buf.st_mode))
	{
		nbchar = readlink(direction, test, 1023);
		lnk = ft_strjoin(tab_l[0][j], " -> ");
		free(tab_l[0][j]);
		tab_l[0][j] = ft_strjoin(lnk, modif_test_two(nbchar, test));
		free(lnk);
	}
	return (buf);
}

void		refill_tab(char ***tab_l, char *direction,
		t_temp *saveoption, int j)
{
	struct stat		buf;
	char			*forfree;
	char			*temp;

	forfree = ft_strjoin(direction, "/");
	temp = ft_strjoin(forfree, tab_l[0][j]);
	buf = fill_tab_l_three(tab_l, temp, j);
	saveoption->totalblock = saveoption->totalblock + buf.st_blocks;
	free(forfree);
	tab_l[1][j] = creation_date(&buf);
	tab_l[2][j] = block_allocated(&buf);
	tab_l[3][j] = group_id(&buf);
	tab_l[4][j] = user_id(&buf);
	tab_l[5][j] = nb_node(&buf);
	tab_l[6][j] = checkdroits(&buf);
	free(temp);
}

void		for_split(char *tab, t_temp *saveoption, int nb, char ***tab_l)
{
	int				i;
	int				j;
	char			*temp;
	struct dirent	*ent;
	DIR				*dirp;

	j = 0;
	dirp = opendir(tab);
	while (j < nb && ((ent = readdir(dirp)) != NULL))
		if ((!saveoption->a && ent->d_name[0] != '.') || saveoption->a)
			tab_l[0][j++] = ft_strdup(ent->d_name);
	i = 0;
	while (i < 7)
		tab_l[i++][j] = NULL;
	temp = ft_strjoin(tab, "/");
	tab_l[0] = order_tab(tab_l[0], saveoption, 0, nb - 1);
	if (saveoption->t)
		tab_l[0] = test_before_order_two(temp, tab_l[0], saveoption, nb);
	if (saveoption->r)
		tab_l[0] = inversetab(tab_l[0]);
	j = 0;
	while (j < nb)
		refill_tab(tab_l, temp, saveoption, j++);
	free(temp);
	closedir(dirp);
}

void		create_tab_l(int nb, char *tab, t_temp *saveoption)
{
	int				i;
	char			***tab_l;

	i = 0;
	tab_l = NULL;
	if (!(tab_l = (char ***)malloc(sizeof(char **) * 8)))
		exit(0);
	while (i <= 6)
	{
		if (!(tab_l[i] = (char **)malloc(sizeof(char *) * (nb + 1))))
			exit(0);
		i++;
	}
	tab_l[7] = NULL;
	for_split(tab, saveoption, nb, tab_l);
	saveoption->mode = 1;
	ft_affich_tab_fich(tab_l, 6, -1, saveoption);
	freebigtab(tab_l);
}
