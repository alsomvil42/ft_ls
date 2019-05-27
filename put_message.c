/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_message.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 23:51:46 by alsomvil          #+#    #+#             */
/*   Updated: 2018/08/15 00:27:17 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		put_message(char av)
{
	ft_putstr("./ft_ls: illegal option -- ");
	ft_putchar(av);
	ft_putchar('\n');
	ft_putstr("usage: ./ft_ls [-alrtR] [file ...]");
	ft_putchar('\n');
	return (1);
}

void	fonction_affich_error(t_temp *saveoption, char *str, char *tab)
{
	str = strerror(errno);
	if (ft_strcmp(str, "Permission denied") == 0)
	{
		ft_putstr("ft_ls: ");
		ft_putstr(tab);
		ft_putstr(": Permission denied\n");
		saveoption->fail++;
	}
	else if (ft_strcmp(str, "Is a directory") != 0)
		saveoption->fail++;
}

char	**finish_tab(char **tab)
{
	int		i;
	int		j;
	int		k;
	int		templen;
	char	*temp;

	i = 0;
	while (tab[i] != NULL)
	{
		j = 0;
		k = 0;
		templen = ft_strlen(tab[i]);
		temp = malloc(sizeof(char) * (templen + 1));
		while (tab[i][j] != ' ')
			j++;
		j++;
		while (tab[i][j])
			temp[k++] = tab[i][j++];
		temp[k] = '\0';
		free(tab[i]);
		tab[i++] = ft_strdup(temp);
		free(temp);
	}
	return (tab);
}

void	affich_all_two(int i, int j, char ***tab_l, t_temp *saveoption)
{
	if (i == 3)
	{
		ft_putstr("  ");
		ft_putstr(tab_l[i][j]);
		while (saveoption->lenfill++ < saveoption->len - 1)
			ft_putstr(" ");
	}
	else if (i == 2)
	{
		ft_putstr(" ");
		while (saveoption->lenfill++ < saveoption->len)
			ft_putstr(" ");
		ft_putstr(tab_l[i][j]);
	}
	else if (i == 1)
		ft_putstr(tab_l[i][j]);
	else if (i == 0)
	{
		ft_putstr(" ");
		ft_putstr(tab_l[i][j]);
	}
}

void	affich_all(int i, int j, char ***tab_l, t_temp *saveoption)
{
	if (i > 5)
		ft_putstr(tab_l[i][j]);
	else if (i == 5)
	{
		while (saveoption->lenfill++ < saveoption->len)
			ft_putstr(" ");
		ft_putstr(tab_l[i][j]);
	}
	else if (i == 4)
	{
		while (saveoption->lenfill++ < saveoption->len)
			ft_putstr(" ");
		ft_putstr(tab_l[i][j]);
	}
	affich_all_two(i, j, tab_l, saveoption);
}
