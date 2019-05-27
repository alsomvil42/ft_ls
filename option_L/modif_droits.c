/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_droits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 00:36:23 by alsomvil          #+#    #+#             */
/*   Updated: 2018/08/11 14:45:11 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	ft_for_other(char **str, struct stat *buf)
{
	if (S_IROTH & buf->st_mode)
		(*str)[7] = 'r';
	if (S_IWOTH & buf->st_mode)
		(*str)[8] = 'w';
	if (S_IXOTH & buf->st_mode)
		(*str)[9] = 'x';
}

void	ft_for_group(char **str, struct stat *buf)
{
	if (S_IRGRP & buf->st_mode)
		(*str)[4] = 'r';
	if (S_IWGRP & buf->st_mode)
		(*str)[5] = 'w';
	if (S_IXGRP & buf->st_mode)
		(*str)[6] = 'x';
}

void	ft_for_user(char **str, struct stat *buf)
{
	if (S_IRUSR & buf->st_mode)
		(*str)[1] = 'r';
	if (S_IWUSR & buf->st_mode)
		(*str)[2] = 'w';
	if (S_IXUSR & buf->st_mode)
		(*str)[3] = 'x';
}

char	ft_recup_type(struct stat *buf)
{
	if (S_ISREG(buf->st_mode))
		return ('-');
	else if (S_ISDIR(buf->st_mode))
		return ('d');
	else if (S_ISLNK(buf->st_mode))
		return ('l');
	else if (S_ISCHR(buf->st_mode))
		return ('c');
	else if (S_ISBLK(buf->st_mode))
		return ('b');
	else if (S_ISFIFO(buf->st_mode))
		return ('p');
	else if (S_ISSOCK(buf->st_mode))
		return ('s');
	return ('\0');
}

char	*checkdroits(struct stat *buf)
{
	char		*temp;
	char		*str;

	str = ft_strdup("---------- \0");
	str[0] = ft_recup_type(buf);
	ft_for_user(&str, buf);
	ft_for_group(&str, buf);
	ft_for_other(&str, buf);
	return (str);
}
