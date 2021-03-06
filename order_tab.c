/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 16:28:32 by alsomvil          #+#    #+#             */
/*   Updated: 2018/08/15 01:13:43 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**inversetab(char **tab)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (tab[i])
		i++;
	i--;
	while (j < i)
	{
		temp = tab[i];
		tab[i] = tab[j];
		tab[j] = temp;
		i--;
		j++;
	}
	return (tab);
}

t_temp	swap(t_temp s)
{
	s.tmp = s.tab[s.left];
	s.tab[s.left] = s.tab[s.right];
	s.tab[s.right] = s.tmp;
	s.left++;
	s.right--;
	return (s);
}

char	**order_tab(char **tab, t_temp *saveoption, int li_left, int li_right)
{
	t_temp	s;

	s.left = li_left;
	s.right = li_right;
	s.midd = tab[(s.left + s.right) / 2];
	s.tab = tab;
	while (s.left <= s.right)
	{
		while (ft_strcmp(s.tab[s.left], s.midd) < 0 && s.left < li_right)
			s.left++;
		while (ft_strcmp(s.midd, s.tab[s.right]) < 0 && s.right > li_left)
			s.right--;
		if (s.left <= s.right)
			s = swap(s);
	}
	if (li_left < s.right)
		order_tab(s.tab, saveoption, li_left, s.right);
	if (li_right > s.left)
		order_tab(s.tab, saveoption, s.left, li_right);
	return (s.tab);
}

char	**order_after_bigtab(int nb, char *doss, t_temp *saveoption)
{
	DIR				*dirp;
	char			**tab;
	int				i;
	struct dirent	*ent;
	char			*tempdoss;

	i = 0;
	dirp = opendir(doss);
	tab = malloc(sizeof(char *) * (nb + 2));
	while ((ent = readdir(dirp)) != NULL)
	{
		if (verifstat(doss, ent->d_name, saveoption) == 1)
			tab[i++] = ft_strdup(ent->d_name);
	}
	tab[i] = NULL;
	order_tab(tab, saveoption, 0, nb - 1);
	tempdoss = ft_strjoin(doss, "/");
	if (saveoption->t)
		tab = test_before_order_two(tempdoss, tab, saveoption, nb);
	if (saveoption->r)
		tab = inversetab(tab);
	closedir(dirp);
	free(tempdoss);
	return (tab);
}
