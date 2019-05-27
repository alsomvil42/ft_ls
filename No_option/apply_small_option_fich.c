/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_small_option_fich.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 03:08:30 by alsomvil          #+#    #+#             */
/*   Updated: 2018/08/14 23:58:09 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

char	**finish_tab_two(char **tab)
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

char	**before_order_two(char **tab, t_temp *saveoption)
{
	int			i;
	struct stat	buf;
	char		*date;
	char		*temp;

	i = 0;
	while (tab[i])
	{
		lstat(tab[i], &buf);
		saveoption->forfree = ft_itoa(1600000000L - buf.st_mtime);
		date = ft_strjoin(saveoption->forfree, " ");
		free(saveoption->forfree);
		temp = ft_strjoin(date, tab[i]);
		free(tab[i]);
		free(date);
		tab[i++] = temp;
	}
	tab = order_tab(tab, saveoption, 0, saveoption->nbfich - 1);
	tab = finish_tab_two(tab);
	return (tab);
}

void	apply_small_option_fich(char **tabfich, t_temp *saveoption)
{
	int		i;

	i = 0;
	tabfich = order_tab(tabfich, saveoption, 0, saveoption->nbfich - 1);
	if (saveoption->t)
		tabfich = before_order_two(tabfich, saveoption);
	if (saveoption->r)
		tabfich = inversetab(tabfich);
	affich_tab_doss(tabfich);
}
