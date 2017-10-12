/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 02:29:55 by carmand           #+#    #+#             */
/*   Updated: 2017/09/29 16:59:02 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ls.h"

int	main(int a, char **v)
{
	t_ls			*ls;
	t_list			*tmp;

	ls = NULL;
	if (!(ls = (t_ls*)malloc(sizeof(t_ls))))
		return (-1);
	if (!(ls_option(ls, a, v)))
		return (-1);
	ls->dir = sort_opdir(ls);
	while (ls->dir)
	{
		if (ls_sort(ls, ls->dir->content))
			if (ls_print_dir(ls))
				ls_print(ls);
		tmp = ls->dir;
		ls->dir = ls->dir->next;
		free(tmp->content);
		free(tmp);
	}
	ls_print_error(ls);
	free_ls(ls);
	return (0);
}
