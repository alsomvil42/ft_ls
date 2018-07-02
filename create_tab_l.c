/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab_l.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 20:58:08 by alsomvil          #+#    #+#             */
/*   Updated: 2018/07/02 06:10:41 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		***fill_tab_l(char *direction, char ***tab_l, int k, t_temp *saveoption)
{
	int				j;
	struct stat		buf;
	char			*directiontemp;

	j = 0;
	directiontemp = ft_strdup(direction);
	tab_l[0] = order_tab(tab_l[0], saveoption);
	while (tab_l[0][j])
	{
		direction = ft_strjoin(directiontemp, "/");
		direction = ft_strjoin(direction, tab_l[0][j]);
		stat(direction, &buf);
		tab_l[1][j] = creation_date(tab_l[1][j], &buf);
		tab_l[2][j] = block_allocated(tab_l[2][j], &buf);
		tab_l[3][j] = group_id(tab_l[3][j], &buf);
		tab_l[4][j] = user_id(tab_l[4][j], &buf);
		tab_l[5][j] = nb_node(tab_l[5][j], &buf);
		tab_l[6][j] = checkdroits(tab_l[6][j], &buf);
		j++;
	}
	return (tab_l);
}

char		***create_tab_l(int nb, char *tab, t_temp *saveoption)
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
		{
			tab_l[i][j] = malloc(sizeof(char) * (ft_strlen(ent->d_name) + 1));
			if (!saveoption->a && ent->d_name[0] != '.')
				tab_l[i][j++] = ft_strdup(ent->d_name);
			else if (saveoption->a)
				tab_l[i][j++] = ft_strdup(ent->d_name);
		}
		tab_l[i][j] = NULL;
		i++;
	}
	tab_l[i] = NULL;
	i = 0;
	tab_l = fill_tab_l(tab, tab_l, i, saveoption);
	i = 0;
	j = 0;
	while (j < nb)
	{
		i = 6;
		while (i >= 0)
		{
			printf("%s  ", tab_l[i][j]);
			i--;
		}
		printf("\n");
		j++;
	}
	return (tab_l);
}
