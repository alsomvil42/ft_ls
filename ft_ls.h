#ifndef FT_LS_H
# define FT_LS_H

#include <stdio.h>
#include"libft/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>

char	**ft_insertstr(char **tabname, char *name);
int	ft_strcmp_ls(const char *s1, const char *s2);

#endif
