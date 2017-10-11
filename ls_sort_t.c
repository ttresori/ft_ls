/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort_t.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 01:59:44 by carmand           #+#    #+#             */
/*   Updated: 2017/09/29 16:58:39 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ls.h"

long	r_time(t_ls *ls, char *d_name)
{
	long			t;
	struct stat		sts;

	t = 0;
	lstat(ft_strjoin(ls->dir->content, ft_strjoin("/", d_name)), &sts);
	t = sts.st_mtime;
	return (t);
}

t_lstd	*sort_t(t_lstd *bgn, char *d_name, t_ls *ls)
{
	if ((r_time(ls, d_name)) > (r_time(ls, bgn->name)))
	{
		if (!(bgn = add_name(d_name, bgn, NULL)))
			return (NULL);
		return (bgn);
	}
	while (bgn->next)
	{
		if ((((r_time(ls, d_name)) <= (r_time(ls, bgn->name)))
		&& (((r_time(ls, d_name)) > (r_time(ls, bgn->next->name))))))
			break ;
		else
			bgn = bgn->next;
	}
	if (!(bgn = add_name(d_name, bgn->next, bgn)))
		return (NULL);
	return (bgn);
}
