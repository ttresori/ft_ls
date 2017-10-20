/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 22:06:45 by carmand           #+#    #+#             */
/*   Updated: 2017/10/20 00:13:11 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ls.h"

static int	if_error_one(char *arg, t_ls *ls, int error)
{
	if (error == 1)
	{
		check_dir(arg, ls);
		return (0);
	}
	return (0);
}

int			detect_option(char *arg, t_ls *ls, int error)
{
	int	i;
	int	tmp;

	i = 1;
	tmp = 0;
	if_error_one(arg, ls, error);
	while (arg[i] != '\0')
	{
		if (ft_strchr((const char*)ls->option_enable, arg[i]) != NULL)
		{
			tmp = arg[i];
			ls->option[tmp] = 1;
		}
		else
		{
			ft_putstr_fd("ls :illegal option -- ", 2);
			ft_putchar_fd(arg[i], 2);
			ft_putstr_fd("\nusage: ls [-Ralrt] [file ...]\n", 2);
			exit(0);
		}
		i++;
	}
	return (1);
}

t_list		*return_new(t_list *new, t_list *prev)
{
	while (new)
	{
		prev = new;
		new = new->next;
	}
	return (new);
}

int			add_dir(char *arg, t_ls *ls)
{
	t_list			*new;
	t_list			*prev;
	struct stat		sts;

	ls->nb_dir = ls->nb_dir + 1;
	if ((check_dir(arg, ls)) == 0 && (lstat(arg, &sts) != 0))
		return (42);
	prev = NULL;
	new = NULL;
	new = ls->dir;
	new = return_new(new, prev);
	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (0);
	if (prev)
		prev->next = new;
	else
		ls->dir = new;
	if (!(new->content = ft_strdup(arg)))
		return (0);
	new->content_size = ft_strlen(arg);
	new->next = NULL;
	return (1);
}

int			ls_option(t_ls *ls, int a, char **v)
{
	int i;
	int error;

	error = 0;
	ls->option_enable = ft_strdup("larRt");
	ls->dir = NULL;
	ls->nb_dir = 0;
	ls->dir_write = -1;
	if (a > 0)
	{
		i = 1;
		while (i < a)
		{
			if (v[i][0] == '-')
				detect_option(v[i], ls, error);
			else if ((add_dir(v[i], ls)) == 0)
				return (0);
			else
				error = 1;
			i++;
		}
	}
	if (error == 0)
		ls->dir = dir_default();
	return (1);
}
