#include "ft_ls.h"

void	ft_simple_ls(char ***av)
{
	DIR *p_opendir;
	struct dirent *lecture;
	struct stat buf;
	char *d_name;
	char **name;
	int i;
	int compt;

	i = 0;
	compt = 0;
	p_opendir = opendir("./");
	name = NULL;
	i = 0;
	*av[0] = NULL;
	if (p_opendir == NULL)
	{
		printf("%s\n", "Mauvais repertoire");
		return ;
	}
	while ((lecture = readdir(p_opendir)))
	{
		if (lecture->d_name[0] != '.')
		{
			compt++;
			name = ft_insertstr(name, lecture->d_name);
		}
	}
	while (name[i] != NULL)
	{
		if (name[i + 1] && ft_strcmp_ls(name[i], name[i + 1]) > 0)
		{
			d_name = name[i + 1];
			name[i + 1] = name[i];
			name[i] = d_name;
			i = 0;
		}
		else
			i++;	
	}
	i = 0;
	while (i < (compt - 1))
	{
		printf("%s%s", name[i], "  ");
		i++;
	}
	printf("%s", name[i]);
	i = 0;
	i = stat("./toto", &buf);
	printf("\n");
	printf("ERREUR = %d\n", i);
	closedir(p_opendir);
	return ;	
}

int	main(int ac, char **av)
{
	if (ac > 3)
	{
		ft_putstr("nombre d'arguments invalide");
		return(0);
	}
	if (ac == 1)
	{
		ft_simple_ls(&av);
		//printf("\n");
	}
	return(0);
}
