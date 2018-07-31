/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tab_doss.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 16:34:58 by alsomvil          #+#    #+#             */
/*   Updated: 2018/07/30 17:14:58 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <fcntl.h>

void	ft_fill_fich(char **av, int fich, t_temp *saveoption)
{
	int		i;
	int		j;
	int		openfich;

	i = 0;
	j = 0;
	saveoption->tabfich = malloc(sizeof(char **) * (fich + 1));
	while (av[i])
	{
		if (i > 0 && av[i] && (openfich = open(av[i], O_WRONLY)) > 0)
		{
			saveoption->tabfich[j++] = ft_strdup(av[i]);
			close(openfich);
		}
		i++;
	}
	saveoption->tabfich[j] = NULL;
	saveoption->tabfich = order_tab(saveoption->tabfich, saveoption, 0,
			saveoption->nbfich - 1);
	if (saveoption->r)
		saveoption->tabfich = inversetab(saveoption->tabfich);
}

void	ft_fill_doss(char **av, int doss, t_temp *saveoption)
{
	int				i;
	int				j;
	DIR				*opendoss;
	struct stat		buf;

	i = 0;
	j = 0;
	if (saveoption->nbfich == 0 && saveoption->nbdoss == 0 && saveoption->fail == 0)
	{
		saveoption->nbdoss++;
		saveoption->tabdoss = malloc(sizeof(char **) * 2);
		saveoption->tabdoss[j++] = ft_strdup(".");
	}
	else
	{
		saveoption->tabdoss = malloc(sizeof(char **) * (doss + 1));
		while (av[i])
		{
			if (i > 0 && av[i] && (lstat(av[i], &buf) == 0 && S_ISDIR(buf.st_mode)))
			{
				saveoption->tabdoss[j] = ft_strdup(av[i]);
				j++;
			}
			i++;
		}
	}
	saveoption->tabdoss[j] = NULL;
	saveoption->tabdoss = order_tab(saveoption->tabdoss, saveoption, 0, saveoption->nbdoss - 1);
	if (saveoption->r)
		saveoption->tabdoss = inversetab(saveoption->tabdoss);
}

void	ft_fill_fail(char **av, int fail, t_temp *saveoption)
{
	int			i;
	int			j;
	int			openfail;
	struct stat	buf;

	i = 0;
	j = 0;
	saveoption->tabfail = malloc(sizeof(char **) * (fail + 1));
	while (av[i])
	{
		if (i > 0 && av[i] && (openfail = open(av[i], O_WRONLY)) < 0 && (lstat(av[i], &buf) < 0))
		{
			saveoption->tabfail[j++] = ft_strdup(av[i]);
			close(openfail);
		}
		i++;
	}
	saveoption->tabfail[j] = NULL;
	saveoption->tabfail = order_tab(saveoption->tabfail,
			saveoption, 0, saveoption->fail - 1);
	if (saveoption->r)
		saveoption->tabfail = inversetab(saveoption->tabfail);
	i = 0;
}

void	check_tab_doss(int i, int ac, char **av, t_temp *saveoption)
{
	int				openfich;
	char			*str;
	DIR				*opendoss;
	struct stat		buf;
	int				ret;

	i = saveoption->nboption + 1;
	while (av[i])
	{
		if (av[i] && ((ret = lstat(av[i], &buf)) == 0) && S_ISDIR(buf.st_mode))
			saveoption->nbdoss++;
		else if (i > 0 && av[i] && (openfich = open(av[i], O_WRONLY)) > 0)
			saveoption->nbfich++;
		else if (av[i])
		{
			str = strerror(errno);
			if (ft_strcmp(str, "Is a directory") != 0)
				saveoption->fail++;
		}
		i++;
	}
	//ft_fill_fail(av, saveoption->fail, saveoption);
	ft_fill_doss(av, saveoption->nbdoss, saveoption);
	ft_fill_fich(av, saveoption->nbfich, saveoption);
}
