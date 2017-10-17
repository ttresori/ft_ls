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

void	ls_print_error(t_list *error)
{
	while (error)
	{
		ft_putstr(error->content);
		ft_putendl(":");
		errno = error->content_size;
		perror(ft_strjoin("ls: ", error->content));
		error = error->next;
		return ;
	}
}
