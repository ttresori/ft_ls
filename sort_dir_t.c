/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dir_t.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 15:45:54 by carmand           #+#    #+#             */
/*   Updated: 2017/10/13 00:45:19 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ls.h"

t_list	*add_name_t(t_list *dir, t_list *nxt, t_list *prv)
{
	t_list	*new;

	new = NULL;
	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new->next = nxt;
	if (prv != NULL)
		prv->next = new;
	new->content = ft_strdup(dir->content);
	new->content_size = dir->content_size;
	return (new);
}

long    r_time_t(char *d_name)
{
	long            t;
	struct stat     sts;

	t = 0;
	lstat(d_name, &sts);
	t = sts.st_mtime;
	return (t);
}

t_list *fill_new_t(t_list *bgn, t_list *dir)
{
	t_list	*tmp;

	tmp = bgn;
	if ((r_time_t(dir->content)) > (r_time_t(bgn->content)))
	{
		if (!(bgn = add_name_t(dir, bgn, NULL)))
			return (NULL);
		return (bgn);
	}
	while (bgn->next)
	{
		//ft_putstr(bgn->content);
		if ((((r_time_t(dir->content)) <= (r_time_t(bgn->content)))
			&& (((r_time_t(dir->content)) > (r_time_t(bgn->next->content))))))
			break ;
		else
			bgn = bgn->next;
	}
		if (!(bgn = add_name_t(dir, bgn->next, bgn)))
			return (NULL);
	return (tmp);
}

t_list	*sort_dir_t(t_ls *ls)
{
	t_list	*bgn;

	bgn = ls->dir;
	ls->dir = ls->dir->next;
	bgn->next = NULL;
	while (ls->dir)
	{
		if (!(bgn = fill_new_t(bgn, ls->dir)))
			return (NULL);
		ls->dir = ls->dir->next;
	}
	return (bgn);
}
