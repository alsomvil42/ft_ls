/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:22:50 by alsomvil          #+#    #+#             */
/*   Updated: 2018/07/02 04:10:50 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <sys/stat.h>
# include <dirent.h>
# include <stdio.h>

typedef struct			s_info
{
	char	*name;
	int		date;
	int		heure;
	char	*droits;
	char	*lieu;
	char	*session;
	int		nboctet;
	int		nbfichier;
	struct s_info	*next;
}						t_info;

typedef struct			s_temp
{
	int		l;
	int		r;
	int		a;
	int		t;
	int		R;
	char	***bigtab;
	char	***tab_l;
	int		lentab;
	struct s_info	*begin_info;
}						t_temp;

void	apply_option(char **tabdoss, t_temp *saveoption);
void	apply_small_option(char **tabdoss, t_temp *saveoption);
void	apply_long_option(char **tabdoss, t_temp *saveoption);
char	**check_tab_doss(int ac, char **av, t_temp *saveoption);
char	**order_tab(char **tab, t_temp *saveoption);
int		ft_morelongchar(char **tab);
char	***createbigtab(int nb, char *tab);
char	***create_tab_l(int nb, char *tab, t_temp *saveoption);
void	order_bigtab(t_temp *saveoption);
void	ft_affich_tab(t_temp *saveoption);
char	*creation_date(char *tab, struct stat *buf);
char	*block_allocated(char *tab, struct stat *buf);
char	*group_id(char *tab, struct stat *buf);
char	*user_id(char *tab, struct stat *buf);
char	*nb_node(char *tab, struct stat *buf);
char	*checkdroits(char *tab, struct stat *buf);

char	***fill_bigtab(int nb, char *tab, char ***bigtab, t_temp *saveoption);

# endif
