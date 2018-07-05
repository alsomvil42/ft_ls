/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:22:50 by alsomvil          #+#    #+#             */
/*   Updated: 2018/07/05 06:21:16 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <sys/stat.h>
# include <dirent.h>
# include <stdio.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>

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
	int		totalblock;
	char	***bigtab;
	char	***tab_l;
	int		lentab;
	struct s_info	*begin_info;
}						t_temp;

void	apply_option(char **tabdoss, t_temp *saveoption);
void	apply_small_option(char *tabdoss, t_temp *saveoption);
void	apply_long_option(char *tabdoss, t_temp *saveoption);
void	apply_small_option_r(char *tabdoss, t_temp *saveoption);
void	apply_long_option_r(char *tabdoss, t_temp *saveoption);
char	**check_tab_doss(int ac, char **av, t_temp *saveoption);
char	**order_tab(char **tab, t_temp *saveoption);
int		ft_morelongchar(char **tab);
char	***createbigtab(int nb, char *tab, t_temp *saveoption);
char	***create_tab_l(int nb, char *tab, t_temp *saveoption);
void	order_bigtab(t_temp *saveoption, char *temptab);
void	ft_affich_tab(t_temp *saveoption, int i, int j, char *tab);
void	ft_affich_tab_l(t_temp *saveoption, int i, int j, char *tab);
char	*creation_date(char *tab, struct stat *buf);
char	*block_allocated(char *tab, struct stat *buf);
char	*group_id(char *tab, struct stat *buf);
char	*user_id(char *tab, struct stat *buf);
char	*nb_node(char *tab, struct stat *buf);
char	*checkdroits(char *tab, struct stat *buf);
char	***fill_bigtab(int nb, char *tab, char ***bigtab, t_temp *saveoption);
char	*modif_droits(char *temp);

# endif
