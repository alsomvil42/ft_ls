/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_morelongchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 17:16:19 by alsomvil          #+#    #+#             */
/*   Updated: 2018/06/27 17:20:41 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_morelongchar(char **tab)
{
	int		i;
	int		ret;
	int		len;

	i = 0;
	ret = 0;
	len = 0;
	while (tab[i])
	{
		if ((ret = ft_strlen(tab[i])) > len)
			len = ret;
		i++;
	}
	return (len);
}
