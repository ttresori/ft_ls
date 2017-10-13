/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_new_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori<carmand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 01:42:35 by carmand           #+#    #+#             */
/*   Updated: 2017/09/29 23:15:27 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ls.h"

void print_no_dir(char *name, t_ls *ls, struct stat *sts)
{
	int i;

	i = 0;
	if (ls->option['l'] == 1)
	{
		if (S_ISLNK(sts->st_mode))
		{
			ft_print_link(name);
			i = 1;
		}
		ft_date(name, ls);
		ft_putchar(' ');
		ft_putendl(name);
	}
	else
		ft_putendl(name);
}

int check_arg(char *name, t_ls *ls)
{
	struct stat sts;

	if (lstat(name, &sts) != 0)
		return (0);
	if (!(S_ISDIR(sts.st_mode)))
		print_no_dir(name, ls, &sts);
	return(0);
}
