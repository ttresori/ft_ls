/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 22:06:45 by carmand           #+#    #+#             */
/*   Updated: 2017/08/09 22:53:50 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ls.h"

void	ls_print_error(t_ls *ls)
{
	while (ls->error)
	{
		ft_putstr(ls->error->content);
		ft_putendl(":");
		errno = ls->error->content_size;
		perror(ft_strjoin("ls: ", ls->error->content));
		ls->error = ls->error->next;
		return ;
	}
}
