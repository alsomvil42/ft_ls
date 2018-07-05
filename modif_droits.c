/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_droits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 00:36:23 by alsomvil          #+#    #+#             */
/*   Updated: 2018/07/03 21:13:33 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*checkdroits(char *tab, struct stat *buf)
{
	char		*temp;

	temp = ft_strdup(ft_itoabase(buf->st_mode, 8));
	temp = modif_droits(temp);
	return (temp);
}

char	*modif_droits(char *temp)
{
	int		len;
	int		i;
	int		j;
	char	*str;
	char	*bin;

	str = ft_strdup("-rwxrwxrwx");
	len = ft_strlen(temp) - 1;
	i = len - 1;
	bin = ft_itoabase((temp[len] - 48), 2);
	while (i > len - 3)
		bin = ft_strjoin(ft_itoabase((temp[i--] - 48), 2), bin);
	if (i - 2 < 0)
		str[0] = 'd';
	i = 0;
	j = 1;
	while (bin[i])
	{
		if (bin[i++] == '0')
			str[j] = '-';
		j++;
	}
	return (str);
}
