/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 00:50:49 by alsomvil          #+#    #+#             */
/*   Updated: 2018/08/13 03:59:50 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

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
	char	*test;

	if (S_ISCHR(buf->st_mode) || S_ISBLK(buf->st_mode))
	{
		maj = major(buf->st_rdev);
		min = minor(buf->st_rdev);
		test = ft_itoa(maj);
		temp = block_two(test, min);
		free(test);
		test = ft_itoa(min);
		forfree = ft_strjoin(temp, test);
		free(temp);
		free(test);
		temp = forfree;
	}
	else
		temp = ft_itoa(buf->st_size);
	test = ft_strjoin(temp, " ");
	free(temp);
	return (test);
}

char	*creation_date(struct stat *buf)
{
	struct tm	*p;
	time_t		fff;
	char		*test;
	char		*forfree;

	fff = buf->st_mtime;
	test = ctime(&fff);
	forfree = convert_mon(fff, test);
	return (forfree);
}
