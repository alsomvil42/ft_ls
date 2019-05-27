/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:22:50 by alsomvil          #+#    #+#             */
/*   Updated: 2018/08/15 01:13:10 by alsomvil         ###   ########.fr       */
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
# include <fcntl.h>
# define LETTERTWO av[i] == 'R' || av[i] == 'a' || av[i] == 't'
# define LETTER av[i] == 'l' || av[i] == 'r'
# define NOTLETTERTWO av[i] != 'l' && av[i] != 'r' && av[i] != 'R'
# define NOTLETTER av[i] != 'a' && av[i] != 't'

typedef struct			s_temp
{
	int		l;
	int		r;
	int		a;
	int		t;
	int		big_r;
	int		left;
	int		right;
	int		nboption;
	char	*midd;
	char	*direction;
	char	*direction_two;
	char	*directiontemp;
	char	temp;
	int		nb;
	int		nbfich;
	int		nbdoss;
	int		mode;
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
	char	*forfree;
}						t_temp;

int						put_message(char av);
char					**order_temp_tab(char **tab, t_temp *saveoption,
		int li_left, int li_right);
void					freesave(t_temp *saveoption);
void					affich_all(int i, int j, char ***tab_l,
		t_temp *saveoption);
void					fonction_affich_error(t_temp *saveoption, char *str,
		char *tab);
char					**finish_tab(char **tab);
void					check_tab_doss(int i, int ac, char **av,
		t_temp *saveoption);
char					**test_before_order(char **tab,
		t_temp *saveoption, int max);
char					**inversetab(char **tab);
char					**order_tab(char **tab, t_temp *saveoption,
		int li_left, int li_right);
void					ft_affich_fail(char **tabfail);
t_temp					swap(t_temp s);
void					apply_small_option(int ac, t_temp *saveoption);
void					apply_small_option_fich(char **tabfich,
		t_temp *saveoption);
void					freebigtab(char ***tab);
void					affich_big_tab_doss(char ***bigtab);
int						search_big_len_l(char **tab);
void					apply_small_option_doss(char *doss,
		t_temp *saveoption);
int						verifstat(char *doss, char *name, t_temp *saveoption);
char					**order_after_bigtab(int nb, char *doss,
		t_temp *saveoption);
char					**test_before_order_two(char *direction, char **tab,
		t_temp *saveoption, int max);
void					affich_tab_doss(char **tab);
void					freetab(char **tab);
void					apply_option_l(int ac, t_temp *saveoption);
void					apply_next_doss(char *tab, t_temp *saveoption);
void					create_tab_l(int nb, char *tab, t_temp *saveoption);
char					*creation_date(struct stat *buf);
char					*block_allocated(struct stat *buf);
char					*group_id(struct stat *buf);
char					*user_id(struct stat *buf);
char					*nb_node(struct stat *buf);
char					*checkdroits(struct stat *buf);
char					*convert_mon(time_t fff, char *date);
char					*block_two(char *test, int min);
void					apply_option_l_fich(t_temp *saveoption);
void					ft_affich_tab_fich(char ***tab_l, int i, int j,
		t_temp *saveoption);
void					apply_option_l_doss(int ac, t_temp *saveoption);
void					apply_option_r(char *doss, t_temp *saveoption);
struct stat				fill_tab_l_two(char ***tab_l, int j);

#endif
