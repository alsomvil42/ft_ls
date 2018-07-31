/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_small_option.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 23:28:34 by alsomvil          #+#    #+#             */
/*   Updated: 2018/07/30 16:08:26 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	apply_small_option(int ac, t_temp *saveoption)
{
	int		i;

	i = 0;
	apply_small_option_fich(saveoption->tabfich, saveoption);
	if (saveoption->nbdoss > 0 && saveoption->nbfich > 0)
		ft_putchar('\n');
	while (saveoption->tabdoss[i])
	{
		if (saveoption->nbdoss > 1 || saveoption->fail > 0
				|| saveoption->nbfich > 0)
		{
			ft_putstr(saveoption->tabdoss[i]);
			ft_putstr(":\n");
		}
		apply_small_option_doss(saveoption->tabdoss[i], saveoption);
		if (saveoption->tabdoss[i + 1])
			ft_putstr("\n");
		i++;
	}
}
