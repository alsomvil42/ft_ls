/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_big_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 19:21:43 by alsomvil          #+#    #+#             */
/*   Updated: 2018/06/29 08:10:47 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	***fill_bigtab(int nb, char *tab, char ***bigtab, t_temp *saveoption)
{
	int		i;
	int		j;
	struct dirent	*ent;
	DIR		*dirp;

	i = 0;
	j = 0;
	dirp = opendir(tab);
	while (i < 3)
	{
		while (j < nb && ((ent = readdir(dirp)) != NULL))
		{
			if (!saveoption->a && ent->d_name[0] != '.')
				bigtab[i][j++] = ft_strdup(ent->d_name);
			else if (saveoption->a)
				bigtab[i][j++] = ft_strdup(ent->d_name);
		}
		bigtab[i][j] = NULL;
		j = 0;
		i++;
	}
	bigtab[i] = NULL;
	return (bigtab);
}

char	***createbigtab(int nb, char *tab)
{
	DIR		*dirp;
	int		i;
	int		j;
	char	***bigtab;
	struct dirent	*ent;

	dirp = opendir(tab);
	i = 0;
	j = 0;
	bigtab = malloc(sizeof(char **) * 4);
	while (i < 3)
	{
		bigtab[i] = malloc(sizeof(char *) * (nb + 1));
		i++;
	}
	i = 0;
	while (i < 3)
	{
		while (j < nb && ((ent = readdir(dirp)) != NULL))
			bigtab[i][j++] = malloc(sizeof(char) * (ft_strlen(ent->d_name) + 1));
		j = 0;
		i++;
	}
	return (bigtab);
}
