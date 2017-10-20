/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 07:09:43 by carmand           #+#    #+#             */
/*   Updated: 2017/10/17 05:25:07 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ls.h"

int		check_dir(char *arg, t_ls *ls)
{
	DIR	*rep;

	if (!(rep = opendir(arg)))
	{
		if (errno != 2)
			stock_error(ls, arg);
		else
			stock_error_dir(ls, arg);
		return (0);
	}
	else
		closedir(rep);
	return (1);
}

void	help_ls_print(t_ls *ls)
{
	if ((((ls->option['R']) == 1) || (ls->nb_dir > 1)))
	{
		ft_putstr(ls->dir->content);
		ft_putendl(":");
	}
}

int		ls_print_dir(t_ls *ls)
{
	DIR				*rep;
	char			*tmp;
	struct stat		sts;

	ls->dir_write = 1;
	help_ls_print(ls);
	if (!(rep = opendir(ls->dir->content)))
	{
		if (lstat(ls->dir->content, &sts) == 0)
			return (0);
		else
		{
			if (!(tmp = ft_strrchr(ls->dir->content, '/')))
				perror(ft_strjoin("ls: ", ls->dir->content));
			else
				perror(ft_strjoin("ls: ", tmp + 1));
			return (0);
		}
	}
	if (ls->option['l'] == 1)
		ft_print_blocks(ls);
	closedir(rep);
	return (1);
}
