/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 02:29:55 by carmand           #+#    #+#             */
/*   Updated: 2017/10/20 00:10:29 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ls.h"

t_ls	*init_ls(t_ls *ls)
{
	ls->dir = sort_opdir(ls);
	ls->nodir = sort_error(ls->nodir);
	ls_print_error_dir(ls->nodir);
	return (ls);
}

int		main(int a, char **v)
{
	t_ls			*ls;
	t_list			*tmp;

	ls = NULL;
	if (!(ls = (t_ls*)malloc(sizeof(t_ls))))
		return (-1);
	if (!(ls_option(ls, a, v)))
		return (-1);
	ls = init_ls(ls);
	while (ls->dir)
	{
		ls->R_error = NULL;
		if (check_link_dossier(ls->dir->content, ls) == 2)
			if (ls_sort(ls, ls->dir->content))
				if (ls_print_dir(ls))
					ls_print(ls);
		tmp = ls->dir;
		free(tmp->content);
		free(tmp);
		ls->dir = ls->dir->next;
	}
	ls->error = sort_error(ls->error);
	ls_print_error(ls->error);
	free_ls(ls);
	return (0);
}
