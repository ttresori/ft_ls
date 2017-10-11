/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 17:41:31 by ttresori          #+#    #+#             */
/*   Updated: 2017/09/29 17:41:34 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ls.h"

int		ft_check_link(char *link, char *dir)
{
	struct stat sts;

	if ((stat(ft_strjoin(dir, ft_strjoin("/", link)), &sts)) != 0)
		if ((lstat(ft_strjoin(dir, ft_strjoin("/", link)), &sts)) != 0)
			return (0);
	if (S_ISLNK(sts.st_mode))
	{
		ft_print_link(ft_strjoin(dir, ft_strjoin("/", link)));
		return (1);
	}
	return (0);
}

void	ft_print_link(char *link)
{
	char	tmp[255];
	char	*clink;
	char	*cut;
	char	*tmp2;
	size_t	len;

	len = 255;
	if (!(len = readlink(link, tmp, len)))
		return ;
	tmp[len] = '\0';
	if (!(cut = ft_strchr(link, '/')))
		return ;;
	tmp2 = cut;
	while (tmp2)
	{
		if ((tmp2 = ft_strchr(cut, '/')))
			cut = tmp2 + 1;
	}
	clink = ft_strdup(tmp);
	ft_putstr(cut);
	ft_putstrspace(" ->");
	ft_putendl(clink);
	free(clink);
}
