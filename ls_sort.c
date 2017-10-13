/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <ttresori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 03:37:33 by carmand           #+#    #+#             */
/*   Updated: 2017/10/04 21:28:48 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ls.h"

t_lstd		*add_name(char *d_name, t_lstd *nxt, t_lstd *prv)
{
	t_lstd	*new;

	new = NULL;
	if (!(new = (t_lstd*)malloc(sizeof(t_lstd))))
		return (NULL);
	if (!(new->name = ft_strdup(d_name)))
		return (NULL);
	new->prev = prv;
	new->next = nxt;
	if (nxt != NULL)
		nxt->prev = new;
	if (prv != NULL)
		prv->next = new;
	return (new);
}

t_lstd		*fill_new(t_lstd *bgn, char *d_name, t_ls *ls)
{
	ft_stockmax(ls, ft_strjoin(ls->dir->content, ft_strjoin("/", d_name)));
	if (ls->option['t'] == 1)
		sort_t(bgn, d_name, ls);
	else
	{
		if ((ft_strcmp(bgn->name, d_name) > 0))
		{
			if (!(bgn = add_name(d_name, bgn, NULL)))
				return (NULL);
			return (bgn);
		}
		while (bgn->next)
		{
			if ((ft_strcmp(bgn->name, d_name) < 0)
			&& (ft_strcmp(bgn->next->name, d_name) > 0))
				break ;
			else
				bgn = bgn->next;
		}
		if (!(bgn = add_name(d_name, bgn->next, bgn)))
			return (NULL);
	}
	while (bgn->prev)
		bgn = bgn->prev;
	return (bgn);
}

t_lstd		*sort_dir(DIR *rep, t_ls *ls)
{
	struct dirent	*ent;
	t_lstd			*bgn;

	ls->dir->content_size = 0;
	ent = readdir(rep);
	if (!(bgn = (t_lstd*)malloc(sizeof(t_lstd))))
		return (NULL);
	if (!(bgn->name = ft_strdup(ent->d_name)))
		return (NULL);
	bgn->prev = NULL;
	bgn->next = NULL;
	while ((ent = readdir(rep)))
	{
		if (ent->d_name[0] != '.' || ls->option['a'] == 1)
			ls->dir->content_size = ft_size_blocks(ls, ent->d_name);
		if (!(bgn = fill_new(bgn, ent->d_name, ls)))
			return (NULL);
	}
	return (bgn);
}

int			check_link_dossier(char *file_link)
{
	struct stat sts;
	char		*tmp;
	int 		len;


	len = ft_strlen(file_link);
	tmp = ft_strndup(file_link, len);
	if(lstat(tmp, &sts) != 0)
		return (-1);
	if(!(S_ISLNK(sts.st_mode)))
	   return (-1);
	else
	{
		ft_print_link(tmp);
		return(1);
	}
	return(0);
}

int			ls_sort(t_ls *ls, char *dir)
{
	DIR				*rep;

	ls->l_info[0] = 0;
	ls->l_info[1] = 0;
	ls->l_info[2] = 0;
	ls->l_info[3] = 0;
	if (!(rep = opendir(dir)))
	{
		if(check_arg(dir, ls) == -1)
			return (1);
		else
			return (0);
	}
	else if (!(ls->file = sort_dir((rep), ls)))
		return (0);
	/*else if (!(check_link_dossier(ls->dir->content)))
	  ft_putstr("OK");*/
	closedir(rep);
	return (1);
}
