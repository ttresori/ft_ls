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

void	check_new_dir(t_ls *ls)
{
	struct stat sts;
	t_list		*new;
	t_list		*tmpd;

	if (stat(ls_join(ls->dir->content, ls->file->name), &sts) != 0)
		if (lstat(ls_join(ls->dir->content, ls->file->name), &sts) != 0)
			return ;
	if (S_ISDIR(sts.st_mode) && (!(S_ISLNK(sts.st_mode))))
	{
		tmpd = ls->tmp->next;
		if (!(new = (t_list*)malloc(sizeof(t_list))))
			return ;
		if (!(new->content = ft_strdup(ls_join(ls->dir->content, \
ls->file->name))))
			return ;
		ls->tmp->next = new;
		new->next = tmpd;
		ls->tmp = new;
	}
	return ;
}
