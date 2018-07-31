/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forfreetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 15:51:24 by alsomvil          #+#    #+#             */
/*   Updated: 2018/07/30 15:52:05 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	freetab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	freebigtab(char ***tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		while (tab[i][j])
			free(tab[i][j++]);
		j = 0;
		i++;
	}
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	freesave(t_temp *saveoption)
{
	int		i;

	i = 0;
	while (saveoption->tabdoss[i])
	{
		free(saveoption->tabdoss[i]);
		i++;
	}
	free(saveoption->tabdoss);
	i = 0;
	while (saveoption->tabfich[i])
		free(saveoption->tabfich[i++]);
	free(saveoption->tabfich);
}
