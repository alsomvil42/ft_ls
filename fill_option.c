/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 00:50:49 by alsomvil          #+#    #+#             */
/*   Updated: 2018/07/30 16:19:14 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*nb_node(struct stat *buf)
{
	char		*temp;
	char		*forfree;

	forfree = ft_itoa(buf->st_nlink);
	temp = ft_strdup(forfree);
	free(forfree);
	return (temp);
}

char	*user_id(struct stat *buf)
{
	struct passwd	*test;
	char			*temp;
	int				uid;

	uid = buf->st_uid;
	if (uid == 4389)
		temp = ft_itoa(uid);
	else
	{
		test = getpwuid(uid);
		temp = ft_strdup(test->pw_name);
	}
	return (temp);
}

char	*group_id(struct stat *buf)
{
	struct group	*lol;
	char			*temp;

	lol = getgrgid(buf->st_gid);
	temp = ft_strdup(lol->gr_name);
	return (temp);
}

char	*block_allocated(struct stat *buf)
{
	char	*temp;
	char	*forfree;
	int		maj;
	int		min;

	if (S_ISCHR(buf->st_mode) || S_ISBLK(buf->st_mode))
	{
		maj = major(buf->st_rdev);
		min = minor(buf->st_rdev);
		if (ft_strlen(ft_itoa(min)) == 3)
			temp = ft_strjoin(ft_itoa(maj), ", ");
		else if (ft_strlen(ft_itoa(min)) == 2)
			temp = ft_strjoin(ft_itoa(maj), ",  ");
		else if (ft_strlen(ft_itoa(min)) == 1)
			temp = ft_strjoin(ft_itoa(maj), ",   ");
		forfree = ft_strjoin(temp, ft_itoa(min));
		free(temp);
		temp = forfree;
	}
	else
	{
		forfree = ft_itoa(buf->st_size);
		temp = ft_strdup(forfree);
		free(forfree);
	}
	return (temp);
}

char	*creation_date(struct stat *buf)
{
	struct tm	*p;
	time_t		fff;
	char		*temp;
	char		*temp2;
	char		*forfree;

	fff = buf->st_mtime;
	p = localtime(&fff);
	forfree = convert_mon(p->tm_mon);
	temp = ft_strjoin(forfree, " ");
	free(forfree);
	forfree = convert_day(p->tm_mday);
	temp2 = ft_strjoin(temp, forfree);
	free(temp);
	free(forfree);
	temp = ft_strjoin(temp2, " ");
	forfree = convert_hour(p->tm_hour, p->tm_min);
	free(temp2);
	temp2 = ft_strjoin(temp, forfree);
	free(temp);
	free(forfree);
	return (temp2);
}
