/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 00:50:49 by alsomvil          #+#    #+#             */
/*   Updated: 2018/07/02 07:18:52 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <time.h>
#include <pwd.h>
#include <grp.h>
#define NANO 1000000000L

char	*modif_droits(char *temp)
{
	int		len;
	int		i;
	int		j;
	char	*str;
	char	*bin;

	str = ft_strdup("-rwxrwxrwx-");
	len = ft_strlen(temp) - 1;
	i = len;
	printf("%d\n", (temp[len] - 48));
	printf("%d\n", 5 * 0b101);
	exit (0);
	bin = ft_itoabase((temp[len] - 48), 2);
	i--;
	while (i > len - 3)
	{
		bin = ft_strjoin(ft_itoabase((temp[i] - 48), 2), bin);
		i--;
	}
	//printf("I = %d  ", i);
	//printf("%c\n", temp[i - 2]);
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

char	*checkdroits(char *tab, struct stat *buf)
{
	char		*temp;

	temp = ft_strdup(ft_itoabase(buf->st_mode, 8));
	temp = modif_droits(temp);
	return (temp);
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
	temp = ft_strjoin(ft_itoa(p->tm_mday), " ");
	temp = ft_strjoin(temp, ft_itoa(p->tm_mon));
	temp = ft_strjoin(temp, " ");
	temp = ft_strjoin(temp, ft_itoa(1900 + p->tm_year));
	temp = ft_strjoin(temp, " ");
	temp = ft_strjoin(temp, ft_itoa(p->tm_hour));
	temp = ft_strjoin(temp, ":");
	temp = ft_strjoin(temp, ft_itoa(p->tm_min));
	return (temp);
}
