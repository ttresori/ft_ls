/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_ls.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <ttresori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 02:30:06 by carmand           #+#    #+#             */
/*   Updated: 2017/10/06 21:58:16 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_LS_H
# define LIB_LS_H

# include "libft/libft.h"
# include "sys/stat.h"
# include <sys/types.h>
# include <errno.h>
# include <stdio.h>
# include <pwd.h>
# include <grp.h>
# include "time.h"
# include <sys/xattr.h>
# include <sys/acl.h>

typedef struct		s_lstd
{
	char			*name;
	struct s_lstd	*next;
	struct s_lstd	*prev;
}					t_lstd;

typedef struct		s_ls
{
	int				option[255 + 1];
	char			*option_enable;
	t_list			*dir;
	t_lstd			*file;
	t_list			*tmp;
	int				dir_write;
	int				nb_dir;
	size_t			l_info[4];
	t_list			*error;
}					t_ls;

void				ls_print_error(t_ls *ls);
void				free_ls(t_ls *ls);
int					ls_option(t_ls *ls, int a, char **v);
t_list				*dir_default();
int					add_dir(char *arg, t_ls *ls);
int					detect_option(char *arg, t_ls *ls, int error);
int					ft_date(char *name, t_ls *ls);
int					ft_check_link(char *link, char *dir);
void				ls_print(t_ls *ls);
void				ft_print_link(char *link);
int					ls_sort(t_ls *ls, char *dir);
void				ft_print_blocks(t_ls *ls);
size_t				ft_size_blocks(t_ls *ls, char *name);
t_lstd				*sort_dir(DIR *rep, t_ls *ls);
t_lstd				*fill_new(t_lstd *bgn, char *d_name, t_ls *ls);
t_lstd				*add_name(char *d_name, t_lstd *nxt, t_lstd *prv);
long				r_time(t_ls *ls, char *d_name);
t_lstd				*sort_t(t_lstd *bgn, char *d_name, t_ls *ls);
int					ls_print_dir(t_ls *ls);
int					ls_file_dir(char *name);
void				check_new_dir(t_ls *ls);
void				ft_right(struct stat *sts, char *name);
int					ft_stockmax(t_ls *ls, char *name);
int					check_dir(char *arg);
char				*ft_padding_pwn_name(t_ls *ls, struct passwd *user);
int					ft_padding_size(t_ls *ls, struct stat *sts);
char				*ft_padding_grp_name(t_ls *ls, struct group *grp);
int					check_arg(char *name, t_ls *ls);
t_list 				*sort_opdir(t_ls *ls);
t_list				 *sort_dir_t(t_ls *ls);
int					check_link_dossier(char *file_link);
#endif
