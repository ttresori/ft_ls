/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_info.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 03:37:33 by carmand           #+#    #+#             */
/*   Updated: 2017/09/29 23:49:47 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ls.h"

t_ls	*cut_stock(t_ls *ls, struct stat sts)
{
	struct group *grp;

	if ((grp = getgrgid(sts.st_gid)) != NULL)
		if (ft_strlen(grp->gr_name) > ls->l_info[2])
			ls->l_info[2] = ft_strlen(grp->gr_name);
	if ((size_t)sts.st_size > ls->l_info[3])
		ls->l_info[3] = sts.st_size;
	return (ls);
}

int		ft_stockmax(t_ls *ls, char *name)
{
	struct stat		sts;
	struct dirent	*ent;
	size_t			i;
	DIR				*rep;
	struct passwd	*user;

	if (stat(name, &sts) != 0)
		if (lstat(name, &sts) != 0)
			return (0);
	i = 0;
	user = NULL;
	if ((rep = opendir(name)))
	{
		while ((ent = readdir(rep)))
			i++;
		if (i > ls->l_info[0])
			ls->l_info[0] = i;
		closedir(rep);
	}
	if ((user = getpwuid(sts.st_uid)) != NULL)
		if (ft_strlen(user->pw_name) > ls->l_info[1])
			ls->l_info[1] = ft_strlen(user->pw_name);
	ls = cut_stock(ls, sts);
	return (1);
}
