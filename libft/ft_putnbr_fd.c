/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 14:33:53 by alsomvil          #+#    #+#             */
/*   Updated: 2017/12/06 04:50:45 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	int nbr;

	if (nb == -2147483648)
	{
		ft_putnbr_fd(-2, fd);
		ft_putnbr_fd(147483648, fd);
		return ;
	}
	if (nb < 0)
	{
		nb = nb * -1;
		ft_putchar_fd('-', fd);
		nbr = (nb % 10) + '0';
		if (nb >= 10)
			ft_putnbr_fd(nb / 10, fd);
		ft_putchar_fd(nbr, fd);
		return ;
	}
	if (nb >= 0)
	{
		nbr = (nb % 10) + '0';
		if (nb >= 10)
			ft_putnbr_fd(nb / 10, fd);
		ft_putchar_fd(nbr, fd);
	}
}
