/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_option_l_doss.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 16:17:05 by alsomvil          #+#    #+#             */
/*   Updated: 2018/08/14 23:58:53 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	apply_next_doss(char *tab, t_temp *saveoption)
{
	struct dirent	*ent;
	DIR				*dirp;
	int				nb;
	struct stat		buf;

	nb = 0;
	if (saveoption->nbdoss > 0 && lstat(tab, &buf) == 0)
	{
		dirp = opendir(tab);
		if (dirp == NULL)
		{
			ft_putstr("Access denied\n");
			return ;
		}
		while ((ent = readdir(dirp)) != NULL)
			if (verifstat(tab, ent->d_name, saveoption) == 1)
				nb++;
		if (nb != 0)
			create_tab_l(nb, tab, saveoption);
		closedir(dirp);
	}
}

void	apply_option_l_doss(int ac, t_temp *saveoption)
{
	int		i;

	i = 0;
	while (saveoption->tabdoss[i])
	{
		if (ac > saveoption->nboption + 2)
		{
			ft_putstr(saveoption->tabdoss[i]);
			ft_putstr(":\n");
		}
		apply_next_doss(saveoption->tabdoss[i], saveoption);
		if (saveoption->tabdoss[i + 1])
			ft_putstr("\n");
		i++;
	}
}
