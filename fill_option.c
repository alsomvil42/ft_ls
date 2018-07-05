/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 00:50:49 by alsomvil          #+#    #+#             */
/*   Updated: 2018/07/03 23:19:22 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*convert_hour(int hour, int min)
{
	char	*temp_hour;
	char	*temp_min;

	if (hour < 10)
		temp_hour = ft_strjoin("0", ft_itoa(hour));
	else
		temp_hour = ft_itoa(hour);
	if (min < 10)
		temp_min = ft_strjoin("0", ft_itoa(min));
	else
		temp_min = ft_itoa(min);
	temp_hour = ft_strjoin(temp_hour, ":");
	temp_hour = ft_strjoin(temp_hour, temp_min);
	return (temp_hour);
}

char	*convert_day(int nbday)
{
	if (ft_strlen(ft_itoa(nbday)) == 1)
	{
		return (ft_strjoin(" ", ft_itoa(nbday)));
	}
	return (ft_itoa(nbday));
}

char	*convert_mon(int nbmon)
{
	if (nbmon == 0)
		return (ft_strdup("Jan"));
	if (nbmon == 1)
		return (ft_strdup("Feb"));
	if (nbmon == 2)
		return (ft_strdup("Mar"));
	if (nbmon == 3)
		return (ft_strdup("Apr"));
	if (nbmon == 4)
		return (ft_strdup("May"));
	if (nbmon == 5)
		return (ft_strdup("Jun"));
	if (nbmon == 6)
		return (ft_strdup("Jul"));
	if (nbmon == 7)
		return (ft_strdup("Aug"));
	if (nbmon == 8)
		return (ft_strdup("Sep"));
	if (nbmon == 9)
		return (ft_strdup("Oct"));
	if (nbmon == 10)
		return (ft_strdup("Nov"));
	if (nbmon == 11)
		return (ft_strdup("Dec"));
	return (NULL);
}

char	*nb_node(char *tab, struct stat *buf)
{
	char		*temp;

	temp = ft_strdup(ft_itoa(buf->st_nlink));
	return (temp);
}

char	*user_id(char *tab, struct stat *buf)
{
	struct passwd	*test;
	char			*temp;

	test = getpwuid(buf->st_uid);
	temp = ft_strdup(test->pw_name);
	return (temp);
}

char	*group_id(char *tab, struct stat *buf)
{
	struct group	*lol;
	char			*temp;

	lol = getgrgid(buf->st_gid);
	temp = ft_strdup(lol->gr_name);
	return (temp);
}

char	*block_allocated(char *tab, struct stat *buf)
{
	char	*temp;

	temp = ft_strdup(ft_itoa(buf->st_size));
	return (temp);
}

char	*creation_date(char *tab, struct stat *buf)
{
	struct tm	*p;
	time_t		fff;
	char		*temp;

	fff = buf->st_mtime;
	p = localtime(&fff);
	temp = ft_strjoin(convert_mon(p->tm_mon), " ");
	temp = ft_strjoin(temp, convert_day(p->tm_mday));
	temp = ft_strjoin(temp, " ");
	temp = ft_strjoin(temp, convert_hour(p->tm_hour, p->tm_min));
	//temp = ft_strjoin(temp, ft_itoa(1900 + p->tm_year));
	return (temp);
}
