/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 07:09:43 by carmand           #+#    #+#             */
/*   Updated: 2017/09/29 16:59:31 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ls.h"

int	check_dir(char *arg)
{
	DIR	*rep;

	if (!(rep = opendir(arg)))
	{
		if (errno == 2)
		  perror(ft_strjoin("ls: ", arg));
		return (0);
	}
	else
		closedir(rep);
	return (1);
}

int	ls_print_dir(t_ls *ls)
{
	DIR		*rep;
	char	*tmp;

	ls->dir_write = 1;
	if (((ls->option['R']) == 1) || (ls->nb_dir > 1))
	{
		ft_putstr(ls->dir->content);
		ft_putendl(":");
	}
	if (!(rep = opendir(ls->dir->content)))
	{
		if (!(tmp = ft_strrchr(ls->dir->content, '/')))
			perror(ft_strjoin("ls: ", ls->dir->content));
			else
			perror(ft_strjoin("ls: ", tmp + 1));
		return (0);
	}
	if (ls->option['l'] == 1)
		ft_print_blocks(ls);
	closedir(rep);
	return (1);
}
