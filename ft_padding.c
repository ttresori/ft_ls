/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <ttresori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 22:29:16 by carmand           #+#    #+#             */
/*   Updated: 2017/09/29 23:24:32 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ls.h"

void	cut_padding_nb(t_ls *ls, int *i, int *space, int nb_dir)
{
	while ((ls->l_info[0] / *i) > 0)
		*i = *i * 10;
	while ((nb_dir < (*i / 10)) > 0)
	{
		*space = *space + 1;
		*i = *i / 10;
	}
	return ;
}

char	*ft_padding_pwn_name(t_ls *ls, struct passwd *user)
{
	size_t size;

	size = ls->l_info[1];
	while (size > 0)
	{
		ft_putchar(' ');
		size = size / 10;
	}
	return (user->pw_name);
}

int		ft_padding_size(t_ls *ls, struct stat *sts)
{
	int		i;
	size_t	space;

	i = 10;
	space = 0;
	while (((ls->l_info[3] / i) > 0))
		i = i * 10;
	while (((sts->st_size < i) > 0))
	{
		i = i / 10;
		ft_print_space(1);
	}
	return (sts->st_size);
}

char	*ft_padding_grp_name(t_ls *ls, struct group *grp)
{
	size_t size;

	size = (ls->l_info[2]);
	while (size > ft_strlen(grp->gr_name))
	{
		ft_putchar(' ');
		size = size - 1;
	}
	return (grp->gr_name);
}
