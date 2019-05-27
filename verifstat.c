/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifstat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 22:05:59 by alsomvil          #+#    #+#             */
/*   Updated: 2018/08/09 11:46:18 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		verifstat(char *doss, char *name, t_temp *saveoption)
{
	struct stat	buf;
	char		*forfree;
	char		*temp;

	forfree = ft_strjoin(doss, "/");
	temp = ft_strjoin(forfree, name);
	if (lstat(temp, &buf) != -1 && (saveoption->a ||
				(!saveoption->a && name[0] != '.')))
	{
		free(temp);
		free(forfree);
		return (1);
	}
	else
	{
		free(temp);
		free(forfree);
		return (0);
	}
	return (0);
}
