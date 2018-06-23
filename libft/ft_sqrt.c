/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 10:26:21 by alsomvil          #+#    #+#             */
/*   Updated: 2017/12/06 07:55:48 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int i;
	int tmp;

	tmp = 0;
	i = 0;
	if (nb <= 0)
		return (0);
	while (tmp < nb)
	{
		tmp = i * i;
		i++;
	}
	if (tmp > nb)
	{
		return (0);
	}
	else
		return (i - 1);
	return (0);
}
