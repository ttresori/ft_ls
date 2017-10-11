/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 17:45:43 by ttresori          #+#    #+#             */
/*   Updated: 2017/09/29 17:45:46 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ls.h"

void	ft_print_blocks(t_ls *ls)
{
	ft_putstr("total ");
	ft_putnbr(ls->dir->content_size);
	ft_putchar('\n');
}

size_t	ft_size_blocks(t_ls *ls, char *name)
{
	struct stat		sts;

	if ((name[0] == '.') && (ls->option['a'] == 0))
		return (0);
	lstat(ft_strjoin(ls->dir->content, ft_strjoin("/", name)), &sts);
	ls->dir->content_size += sts.st_blocks;
	return (ls->dir->content_size);
}
