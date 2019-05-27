/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_option_l.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 14:11:30 by alsomvil          #+#    #+#             */
/*   Updated: 2018/08/14 18:22:29 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	apply_option_l(int ac, t_temp *saveoption)
{
	if (ac == saveoption->nboption + 1)
	{
		saveoption->nbdoss++;
		apply_next_doss("./", saveoption);
	}
	else
	{
		apply_option_l_fich(saveoption);
		if (saveoption->nbfich > 0 && saveoption->nbdoss > 0)
			ft_putstr("\n");
		apply_option_l_doss(ac, saveoption);
	}
}
