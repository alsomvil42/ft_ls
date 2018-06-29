/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 16:26:05 by alsomvil          #+#    #+#             */
/*   Updated: 2018/06/29 05:38:15 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	apply_small_optionR(char **tabdoss, t_temp *saveoption)
{
}

void	apply_long_optionR(char **tabdoss, t_temp *saveoption)
{
}

void	apply_small_option(char **tab, t_temp *saveoption)
{
	int		i;
	struct dirent	*ent;
	DIR			*dirp;
	int			nb;
	int		j;

	nb = 0;
	i = 0;
	while (tab[i])
	{
		dirp = opendir(tab[i]);
		while ((ent = readdir(dirp)) != NULL)
		{
			if (!saveoption->a && ent->d_name[0] != '.')
				nb++;
			else if (saveoption->a)
				nb++;
		}
		if (saveoption->lentab >= 2)
			printf("%s:\n", tab[i]);
		if (nb != 0)
		{
			if (nb % 3 > 0)
				nb = (nb / 3) + 1;
			else
				nb = nb / 3;
			saveoption->bigtab = createbigtab(nb, tab[i]);
			saveoption->bigtab = fill_bigtab(nb, tab[i], saveoption->bigtab, saveoption);
			order_bigtab(saveoption);
			ft_affich_tab(saveoption);
			free(saveoption->bigtab);
			free(ent);
		}
		if (tab[i + 1])
			printf("\n");
		nb = 0;
		i++;
	}
}

void	apply_long_option(char **tabdoss, t_temp *saveoption)
{
}

void	apply_option(char **tabdoss, t_temp *saveoption)
{
	if (!saveoption->R)
	{
		if (saveoption->l == 1)
		{
			apply_long_option(tabdoss, saveoption);
			return ;
		}
		else
		{
			apply_small_option(tabdoss, saveoption);
			return ;
		}
	}
	else
	{
		if (saveoption->l == 1)
		{
			apply_long_optionR(tabdoss, saveoption);
			return ;
		}
		else
		{
			apply_small_optionR(tabdoss, saveoption);
			return ;
		}
	}
}
