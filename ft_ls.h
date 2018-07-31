/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:22:50 by alsomvil          #+#    #+#             */
/*   Updated: 2018/07/30 16:23:02 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <sys/stat.h>
# include <sys/types.h>
# include <dirent.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>

typedef struct			s_temp
{
	int		l;
	int		r;
	int		a;
	int		t;
	int		R;
	int		left;
	int		right;
	int		nboption;
	char	*midd;
	int		nbfich;
	int		nbdoss;
	int		fail;
	int		totalblock;
	int		lenfill;
	int		len;
	DIR		*dirp;
	char	*tmp;
	char	**tab;
	char	**tabdoss;
	char	**tabfich;
	char	**tabfail;
	char	***tab_l;
}						t_temp;

int		verifstat(char *doss, char *name, t_temp *saveoption);
void	check_tab_doss(int i, int ac, char **av, t_temp *saveoption);
void	apply_next_doss(char *tab, t_temp *saveoption);
void	apply_option_l(int ac, t_temp *saveoption);
char	*creation_date(struct stat *buf);
char	*block_allocated(struct stat *buf);
char	*group_id(struct stat *buf);
char	*user_id(struct stat *buf);
char	*nb_node(struct stat *buf);
char	*checkdroits(struct stat *buf);
char	***fill_bigtab(int nb, char *tab, char ***bigtab, t_temp *saveoption);
void	create_tab_l(int nb, char *tab, t_temp *saveoption);
char	*modif_droits(char *temp);
void	apply_option_l_fich(t_temp *saveoption);
void	apply_option_l_doss(int ac, t_temp *saveoption);
int		search_big_len_l(char **tab);
char	**order_tab(char **tab, t_temp *saveoption, int li_left, int li_right);
void	apply_small_option(int ac, t_temp *saveoption);
void	apply_small_option_fich(char **tabfich, t_temp *saveoption);
void	apply_small_option_doss(char *doss, t_temp *saveoption);
void	order_bigtab(t_temp *saveoption);
void	freetab(char **tab);
void	freebigtab(char ***tab);
void	affich_big_tab_doss(char ***bigtab);
void	apply_option_r(char *doss, t_temp *saveoption);
char	**inversetab(char **tab);
void	freesave(t_temp *saveoption);
void	freebigtab(char ***tab);
void	freetab(char **tab);
char	*convert_day(int nbday);
char	*convert_mon(int nbmon);
char	*convert_hour(int hour, int min);

# endif
