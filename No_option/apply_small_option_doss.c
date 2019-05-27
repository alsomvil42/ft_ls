/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_small_option_doss.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 03:09:45 by alsomvil          #+#    #+#             */
/*   Updated: 2018/08/15 01:27:32 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	affich_tab_doss(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		ft_putstr(tab[i]);
		ft_putstr("\n");
		i++;
	}
}

void	apply_small_option_doss_two(int nb, char *doss, t_temp *saveoption)
{
	char	**tab;
	char	*temp;

	temp = ft_strjoin(doss, "/");
	tab = order_after_bigtab(nb, doss, saveoption);
	affich_tab_doss(tab);
	free(temp);
	freetab(tab);
}

void	apply_small_option_doss(char *doss, t_temp *saveoption)
{
	struct stat		buf;
	char			**tab;
	struct dirent	*ent;
	DIR				*dirp;
	int				nb;

	nb = 0;
	tab = NULL;
	if ((lstat(doss, &buf) == 0) && S_ISDIR(buf.st_mode))
	{
		dirp = opendir(doss);
		if (dirp == NULL)
		{
			ft_putstr("ls: ");
			ft_putstr(doss);
			ft_putstr(": Permission denied\n");
			return ;
		}
		while ((ent = readdir(dirp)) != NULL)
			if (verifstat(doss, ent->d_name, saveoption) == 1)
				nb++;
		if (nb != 0)
			apply_small_option_doss_two(nb, doss, saveoption);
		closedir(dirp);
	}
}
