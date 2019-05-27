/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tab_doss.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 16:34:58 by alsomvil          #+#    #+#             */
/*   Updated: 2018/08/15 01:25:46 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_fill_fich(char **av, int fich, t_temp *saveoption)
{
	int				i;
	int				j;
	int				openfich;
	struct stat		buf;

	i = 0;
	j = 0;
	saveoption->tabfich = malloc(sizeof(char **) * (fich + 1));
	while (av[i])
	{
		if (lstat(av[i], &buf) == 0)
		{
			if (i > 0 && av[i] && (S_ISSOCK(buf.st_mode) ||
						S_ISFIFO(buf.st_mode) || S_ISREG(buf.st_mode) ||
						S_ISLNK(buf.st_mode)))
				saveoption->tabfich[j++] = ft_strdup(av[i]);
		}
		i++;
	}
	saveoption->tabfich[j] = NULL;
	order_tab(saveoption->tabfich, saveoption, 0, saveoption->nbfich - 1);
	if (saveoption->t && saveoption->nbfich > 1)
		test_before_order(saveoption->tabfich, saveoption, saveoption->nbfich);
	if (saveoption->r)
		inversetab(saveoption->tabfich);
}

int		ft_fill_doss_two(int i, char **av, t_temp *saveoption, int doss)
{
	int			j;
	struct stat	buf;

	j = 0;
	saveoption->tabdoss = malloc(sizeof(char **) * (doss + 1));
	while (av[i])
	{
		if (i > 0 && av[i] && (!lstat(av[i], &buf) && S_ISDIR(buf.st_mode)))
		{
			saveoption->tabdoss[j] = ft_strdup(av[i]);
			j++;
		}
		i++;
	}
	return (j);
}

void	ft_fill_doss(char **av, int doss, t_temp *saveoption)
{
	int	j;

	j = 0;
	if (!saveoption->nbfich && !saveoption->nbdoss && !saveoption->fail)
	{
		saveoption->nbdoss++;
		saveoption->tabdoss = malloc(sizeof(char **) * 2);
		saveoption->tabdoss[j++] = ft_strdup(".");
	}
	else
		j = ft_fill_doss_two(0, av, saveoption, doss);
	saveoption->tabdoss[j] = NULL;
	order_tab(saveoption->tabdoss, saveoption, 0, saveoption->nbdoss - 1);
	if (saveoption->t && saveoption->nbdoss > 1)
		saveoption->tabdoss = order_temp_tab(saveoption->tabdoss, saveoption,
				0, saveoption->nbdoss - 1);
	if (saveoption->r)
		saveoption->tabdoss = inversetab(saveoption->tabdoss);
}

void	ft_fill_fail(char **av, int fail, t_temp *saveoption)
{
	int			i;
	int			j;
	int			openfail;
	struct stat	buf;
	char		*str;

	i = saveoption->nboption + 1;
	j = 0;
	saveoption->tabfail = malloc(sizeof(char **) * (fail + 1));
	while (av[i])
	{
		if (i > 0 && av[i] && (lstat(av[i], &buf) < 0))
			saveoption->tabfail[j++] = ft_strdup(av[i]);
		i++;
	}
	saveoption->tabfail[j] = NULL;
	saveoption->tabfail = order_tab(saveoption->tabfail,
			saveoption, 0, saveoption->fail - 1);
	ft_affich_fail(saveoption->tabfail);
}

void	check_tab_doss(int i, int ac, char **av, t_temp *saveoption)
{
	int				openfich;
	char			*str;
	struct stat		buf;
	int				ret;

	while (av[i])
	{
		ret = lstat(av[i], &buf);
		if (av[i] && ret == 0 && S_ISDIR(buf.st_mode))
		{
			saveoption->nbdoss++;
		}
		else if (ret == 0 && i > 0 && av[i] && (S_ISSOCK(buf.st_mode) ||
					S_ISFIFO(buf.st_mode) || S_ISREG(buf.st_mode) ||
					S_ISLNK(buf.st_mode)))
			saveoption->nbfich++;
		else if (av[i] && ret == -1)
			fonction_affich_error(saveoption, str, av[i]);
		i++;
	}
	if (saveoption->fail > 0)
		ft_fill_fail(av, saveoption->fail, saveoption);
	ft_fill_doss(av, saveoption->nbdoss, saveoption);
	if (saveoption->nbfich > 0)
		ft_fill_fich(av, saveoption->nbfich, saveoption);
}
