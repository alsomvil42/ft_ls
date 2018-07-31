/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 16:28:32 by alsomvil          #+#    #+#             */
/*   Updated: 2018/07/30 16:06:30 by alsomvil         ###   ########.fr       */
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
