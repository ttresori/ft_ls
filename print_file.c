/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 03:08:31 by ttresori          #+#    #+#             */
/*   Updated: 2017/10/20 03:08:36 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ls.h"

void	print_no_dir(char *name, t_ls *ls, struct stat *sts)
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

int		check_arg(char *name, t_ls *ls)
{
	struct stat sts;

	if (lstat(name, &sts) != 0)
		return (0);
	if (!(S_ISDIR(sts.st_mode)))
		print_no_dir(name, ls, &sts);
	return (0);
}
