/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_before_order.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 02:54:32 by alsomvil          #+#    #+#             */
/*   Updated: 2018/08/15 01:16:04 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		check_time(char *tab1, char *tab2, t_temp *saveoption)
{
	char		*temp1;
	char		*temp2;
	long int	test1;
	long int	test2;
	struct stat	buf;

	test1 = 0;
	test2 = 0;
	temp1 = ft_strjoin(saveoption->direction, tab1);
	temp2 = ft_strjoin(saveoption->direction, tab2);
	if (lstat(temp1, &buf) < 0)
	{
		free(temp1);
		free(temp2);
		return (0);
	}
	test1 = buf.st_mtime;
	lstat(temp2, &buf);
	test2 = buf.st_mtime;
	free(temp1);
	free(temp2);
	return (test1 - test2);
}

int		fonctiontime(char *tab1, char *tab2, t_temp *saveoption)
{
	if (check_time(tab1, tab2, saveoption) > 0)
		return (1);
	else if (check_time(tab1, tab2, saveoption) == 0)
		return (ft_strcmp(tab1, tab2) < 0);
	else
		return (0);
	return (0);
}

char	**order_temp_tab(char **tab, t_temp *saveoption,
		int li_left, int li_right)
{
	t_temp	s;

	s.left = li_left;
	s.right = li_right;
	s.midd = tab[(s.left + s.right) / 2];
	s.tab = tab;
	while (s.left <= s.right)
	{
		while (fonctiontime(s.tab[s.left], s.midd, saveoption) > 0 &&
				s.left < li_right)
			s.left++;
		while (fonctiontime(s.midd, s.tab[s.right], saveoption) > 0 &&
				s.right > li_left)
			s.right--;
		if (s.left <= s.right)
			s = swap(s);
	}
	if (li_left < s.right)
		order_temp_tab(s.tab, saveoption, li_left, s.right);
	if (li_right > s.left)
		order_temp_tab(s.tab, saveoption, s.left, li_right);
	return (s.tab);
}

char	**test_before_order_two(char *direction, char **tab,
		t_temp *saveoption, int max)
{
	saveoption->direction = ft_strdup(direction);
	tab = order_temp_tab(tab, saveoption, 0, max - 1);
	free(saveoption->direction);
	return (tab);
}

char	**test_before_order(char **tab, t_temp *saveoption, int max)
{
	saveoption->direction = ft_strdup("./");
	tab = order_temp_tab(tab, saveoption, 0, max - 1);
	free(saveoption->direction);
	return (tab);
}
