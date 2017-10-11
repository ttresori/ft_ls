/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <ttresori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 07:09:43 by carmand           #+#    #+#             */
/*   Updated: 2017/10/06 22:02:24 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ls.h"

void	ls_help_print(t_ls *ls)
{
	if ((ls->option['R'] == 1)
	&& (ft_strcmp(ls->file->name, ".") != 0)
	&& (ft_strcmp(ls->file->name, "..") != 0))
					check_new_dir(ls);
	if (ls->option['l'] == 1)
			ft_date((ft_strjoin(ls->dir->content, \
				ft_strjoin("/" ,ls->file->name))), ls);
	if (((ls->option['l']) == 0) || (!(ft_check_link(ls->file->name, \
		ls->dir->content))))
	ft_putendl(ls->file->name);	
}

void	ls_print(t_ls *ls)
{
	ls->tmp = ls->dir;
	if (ls->option['r'] == 1)
		while(ls->file->next)
			ls->file = ls->file->next;
	while (ls->file)
	{
		if (ls->file->name[0] != '.' || ls->option['a'] == 1)
			ls_help_print(ls);
		if (ls->option['r'] == 1)
			ls->file = ls->file->prev;
		else
			ls->file = ls->file->next;
	}
	if (ls->dir->next)
		ft_putchar('\n');
}
