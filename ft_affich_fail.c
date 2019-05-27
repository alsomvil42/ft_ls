/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affich_fail.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 23:29:23 by alsomvil          #+#    #+#             */
/*   Updated: 2018/08/13 06:51:09 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_affich_fail(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		ft_putstr("ls: ");
		ft_putstr(tab[i]);
		ft_putstr(": No such file or directory");
		ft_putstr("\n");
		i++;
	}
}
