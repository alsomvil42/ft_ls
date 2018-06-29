/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tempfonction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 15:24:15 by alsomvil          #+#    #+#             */
/*   Updated: 2018/06/26 15:25:04 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	ft_parce_doss(int ac, char **av, t_info *info)
{
	int		i;
	struct stat		buf;
	t_info			*temp;
	char		*test;

	i = 0;
	av[0] = "./";
	temp = info;
	while (av[i])
	{
		stat(av[i], &buf);
		//printf("%s\n", temp->name);
		temp->name = ft_strdup(av[i]);
		temp->nbfichier = buf.st_nlink;
		//printf("%s\n", temp->name);
		//printf("%d\n", temp->nbfichier);
		if (av[i + 1])
			temp->next = malloc(sizeof(t_info) * 1);
		else
		{
			temp->next = NULL;
			return ;
		}
		temp = temp->next;
		i++;
	}
}

void	ft_parce_arg(int ac, char **av, t_info *info)
{
	//if (no_option(ac, av) == 1)
	//{
		ft_parce_doss(ac, av, info);
	//	ft_order_doss();
	//}
	//else
	//{
	//}
}

void	simple_ls(char *av)
{
	DIR				*dirp;
	int				ret;
	const char		*test;
	struct stat		buf;
	struct dirent	*ent;


	printf("%s\n", av);
	if ((dirp = opendir(av)) == NULL)
	{
		ft_putstr("erreur1\n");
		exit (0);
	}
	ret = stat(av, &buf);
	printf("%d\n", buf.st_dev);
	if (ret < 0)
	{
		ft_putstr("erreur\n");
		exit (0);
	}
	while ((ent = readdir(dirp)) != NULL)
	{
		printf("%s\n", ent->d_name);
	}
	//printf("%d\n", ret);
}
