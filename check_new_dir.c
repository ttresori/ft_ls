/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_new_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <carmand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 01:42:35 by carmand           #+#    #+#             */
/*   Updated: 2017/09/29 23:15:27 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ls.h"

char	*ls_join(const char *s1, const char *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	new = NULL;
	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!new)
		return (0);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	new[i++] = '/';
	while (s2[j] != '\0')
		new[i++] = s2[j++];
	new[i] = '\0';
	return (new);
}

int		stock_error_grandr(t_ls *ls, char *arg)
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
	if (ls->R_error == NULL)
		ls->R_error = new;
	else
	{
		tmp = ls->R_error;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (1);
}

void	help_check_new_dir(t_ls *ls)
{
	t_list		*new;
	t_list		*tmpd;
	DIR			*rep;

	if (!(rep = opendir(ls_join(ls->dir->content, ls->file->name))))
	{
		stock_error_grandr(ls, ls_join(ls->dir->content, ls->file->name));
		return ;
	}
	closedir(rep);
	tmpd = ls->tmp->next;
	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return ;
	if (ft_strcmp(ls->dir->content, "/") == 0)
	{
		if (!(new->content = ft_strjoin("/", ls->file->name)))
			return ;
	}
	else if (!(new->content = ls_join(ls->dir->content, ls->file->name)))
		return ;
	ls->tmp->next = new;
	new->next = tmpd;
	ls->tmp = new;
}

void	check_new_dir(t_ls *ls)
{
	struct stat	sts;

	if (lstat(ls_join(ls->dir->content, ls->file->name), &sts) != 0)
		return ;
	if (S_ISDIR(sts.st_mode) && (!(S_ISLNK(sts.st_mode))))
		help_check_new_dir(ls);
	return ;
}
