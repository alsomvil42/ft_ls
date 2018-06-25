/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 02:14:26 by alsomvil          #+#    #+#             */
/*   Updated: 2017/12/06 04:58:55 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_fillstr(char *str, int nb, int neg, int base)
{
	int	i;

	i = 0;
	while (nb >= base)
	{
		str[i++] = (nb % base < 10) ? (nb % base) + '0' : (nb % base) + 55;
		nb = nb / base;
	}
	str[i++] = (nb % base < 10) ? (nb % base) + '0' : (nb % base) + 55;
	if (neg)
		str[i++] = '-';
	str[i] = '\0';
}

static int	ft_lenum(int nb, int base)
{
	int	i;

	i = 0;
	while (nb >= base)
	{
		nb = nb / base;
		i++;
	}
	return (i + 1);
}

char		*ft_itoabase(int nb, int base)
{
	int		len;
	int		neg;
	char	*str;

	neg = 0;
	if (nb == -2147483648 && base == 10)
		return (ft_strdup("-2147483648"));
	if (nb < 0 && base == 10)
	{
		neg = 1;
		nb = nb * -1;
	}
	len = ft_lenum(nb, base);
	if (!(str = ft_memalloc(sizeof(char) * (len + 1 + neg))))
		return (NULL);
	ft_fillstr(str, nb, neg, base);
	ft_strrev(str);
	return (str);
}
