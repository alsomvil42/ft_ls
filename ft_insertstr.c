#include <stdlib.h>
#include "libft/libft.h"
#include "ft_ls.h"

/*char	**ft_strmallcpy(char **str, char *name)
{
	int	i;
	
	printf("%s\n", "TEST");
	while (str[i] && str[i] != NULL)
		i++;
	
}*/

char	**ft_insertstr(char **tabname, char *name)
{
	char	**tabname2;
	int	i;
	int	j;
	int	length;

	i = 0;
	j = 0;
	if (!tabname)
	{
		length = ft_strlen(name);
		if (!(tabname2 = malloc(sizeof(char **) * 2)))
			printf("%s\n", "Malloc1");
		if (!(tabname2[0] = malloc(sizeof(char *) * (length + 1))))
			printf("%s\n", "Malloc2");
		while (name[i])
		{
			tabname2[0][i] = name[i];
			i++;
		}
		tabname2[0][i] = name[i];
		tabname2[1] = NULL;
		return (tabname2);
	}
	while (tabname[i] != NULL)
		i++;
	tabname2 = malloc(sizeof(char **) * (i + 2));
	i = 0;
	while (tabname[i] != NULL)
	{
		length = ft_strlen(tabname[i]);
		tabname2[i] = malloc(sizeof(char *) * (length + 1));
		while (tabname[i][j])
		{
			tabname2[i][j] = tabname[i][j];
			j++;
		}
		tabname2[i][j] = tabname[i][j];
		i++;
		j = 0;
	}
	length = ft_strlen(name);
	tabname2[i] = malloc(sizeof(char) * (length + 1));
	while (name[j])
	{
		tabname2[i][j] = name[j];
		j++;
	}
	tabname2[i][j] = name[j];
	return (tabname2);
}
