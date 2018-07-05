/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 16:26:05 by alsomvil          #+#    #+#             */
/*   Updated: 2018/07/05 07:20:24 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
		nb++;
	tab = malloc(sizeof(char *) * (nb + 1));
	dirdoss = opendir(namedoss);
	while (i < nb && ((ent = readdir(dirdoss)) != NULL))
	{
		if (ent->d_name[0] != '.')
		{
			namedoss = ft_strjoin(directiontemp, "/");
			namedoss = ft_strjoin(namedoss, ent->d_name);
			tab[i] = ft_strdup(namedoss);
			i++;
		}
	}
	tab[i] = NULL;
	tab = order_tab(tab, saveoption);
	return (tab);
}

void	apply_small_option_r(char *tabdoss, t_temp *saveoption)
{
	int		i;
	DIR		*dirp;
	char	**tab;

	i = 0;
	if (!saveoption->l)
		apply_small_option(tabdoss, saveoption);
	else
		apply_long_option(tabdoss, saveoption);
	dirp = opendir(tabdoss);
	if (dirp != NULL)
	{
		tab = create_tab_test(tabdoss, dirp, saveoption);
		while (tab[i])
		{
			//printf("\n");
			if (opendir(tab[i]) != NULL)
				printf("\n%s: \n", tab[i]);
			apply_small_option_r(tab[i], saveoption);
			//if (tab[i + 1])
			//	printf("\n");
			i++;
		}
	}
}

void	apply_long_option_r(char *tabdoss, t_temp *saveoption)
{
}

void	apply_small_option(char *tab, t_temp *saveoption)
{
	int				i;
	struct dirent	*ent;
	DIR				*dirp;
	int				nb;

	i = 0;
	nb = 0;
	dirp = opendir(tab);
	if (dirp == NULL)
	{
		//printf("La direction %s est un fichier\n", tab);
		i++;
	}
	else
	{
		//printf("%d\n", dirp);
		while ((ent = readdir(dirp)) != NULL)
			if ((!saveoption->a && ent->d_name[0] != '.') || saveoption->a)
				nb++;
		if (nb != 0)
		{
			if (nb % 3 > 0)
				nb = (nb / 3) + 1;
			else
				nb = nb / 3;
			createbigtab(nb, tab, saveoption);
			order_bigtab(saveoption, tab);
		}
	}
}

void	apply_long_option(char *tab, t_temp *saveoption)
{
	int				i;
	struct dirent	*ent;
	DIR				*dirp;
	int				nb;

	nb = 0;
	i = 0;
	dirp = opendir(tab);
	if (dirp == NULL)
	{
		//printf("La direction %s est un fichier\n", tab);
		i++;
	}
	else
	{
		while ((ent = readdir(dirp)) != NULL)
			if (!saveoption->a && ent->d_name[0] != '.')
				nb++;
			else if (saveoption->a)
				nb++;
		if (nb != 0)
		{
			saveoption->tab_l = create_tab_l(nb, tab, saveoption);
			free(ent);
		}
		nb = 0;
		i++;
	}
}
