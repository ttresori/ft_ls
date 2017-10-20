/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 22:06:45 by carmand           #+#    #+#             */
/*   Updated: 2017/10/17 05:29:09 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ls.h"

int		stock_error_dir(t_ls *ls, char *arg)
{
	t_list	*new;
	t_list	*tmp;
	int		errno;

	errno = 0;
	new = NULL;
	tmp = NULL;
	opendir(arg);
	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (0);
	new->content = ft_strdup(arg);
	new->content_size = errno;
	new->next = NULL;
	if (ls->nodir == NULL)
		ls->nodir = new;
	else
	{
		tmp = ls->nodir;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (1);
}

void	ls_print_error_dir(t_list *error)
{
	while (error)
	{
		errno = error->content_size;
		perror(ft_strjoin("ls: ", error->content));
		error = error->next;
	}
}

void	ls_print_error(t_list *error)
{
	while (error)
	{
		ft_putstr_fd(error->content, 2);
		ft_putendl_fd(":", 2);
		errno = error->content_size;
		perror(ft_strjoin("ls: ", error->content));
		error = error->next;
	}
}

void	ls_print_error_grandr(t_list *error)
{
	while (error)
	{
		ft_putstr_fd(error->content, 2);
		ft_putendl_fd(":", 2);
		errno = error->content_size;
		perror(ft_strjoin("ls: ", error->content));
		error = error->next;
		ft_putchar_fd('\n', 2);
	}
}
