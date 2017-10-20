/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_right.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 03:08:08 by ttresori          #+#    #+#             */
/*   Updated: 2017/10/20 03:08:10 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ls.h"

void	help_right(struct stat *sts)
{
	ft_putchar((S_ISFIFO(sts->st_mode)) ? 'p' : '\0');
	ft_putchar((S_ISCHR(sts->st_mode)) ? 'c' : '\0');
	ft_putchar((S_ISLNK(sts->st_mode)) ? 'l' : '\0');
	ft_putchar((S_ISDIR(sts->st_mode)) ? 'd' : '\0');
	ft_putchar((S_ISBLK(sts->st_mode)) ? 'b' : '\0');
	ft_putchar((S_ISREG(sts->st_mode)) ? '-' : '\0');
	ft_putchar((S_ISSOCK(sts->st_mode)) ? 's' : '\0');
	ft_putchar((sts->st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((sts->st_mode & S_IWUSR) ? 'w' : '-');
	if (((S_ISUID & sts->st_mode) && (S_IXUSR & sts->st_mode)))
		ft_putchar('s');
	else if (S_ISUID & sts->st_mode)
		ft_putchar('S');
	else if (S_IXUSR & sts->st_mode)
		ft_putchar('x');
	else
		ft_putchar('-');
}

void	help_2right(struct stat *sts)
{
	ft_putchar((sts->st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((sts->st_mode & S_IWGRP) ? 'w' : '-');
	if (((S_ISGID & sts->st_mode) && (S_IXGRP & sts->st_mode)))
		ft_putchar('s');
	else if (S_ISGID & sts->st_mode)
		ft_putchar('S');
	else if (S_IXGRP & sts->st_mode)
		ft_putchar('x');
	else
		ft_putchar('-');
	ft_putchar((sts->st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((sts->st_mode & S_IWOTH) ? 'w' : '-');
	if (((S_ISVTX & sts->st_mode) && (S_IXOTH & sts->st_mode)))
		ft_putchar('t');
	else if (S_ISVTX & sts->st_mode)
		ft_putchar('T');
	else if (S_IXOTH & sts->st_mode)
		ft_putchar('x');
	else
		ft_putchar('-');
}

void	ft_right(struct stat *sts, char *name)
{
	int		xattr;
	acl_t	acl;

	acl = NULL;
	help_right(sts);
	help_2right(sts);
	if ((xattr = listxattr(name, NULL, 1, XATTR_NOFOLLOW) > 0))
		ft_putchar('@');
	else if (((acl = acl_get_file(name, ACL_TYPE_EXTENDED)) != NULL &&
	(!(S_ISLNK(sts->st_mode)))))
		ft_putchar('+');
	else
		ft_putchar(' ');
	ft_putstr("  ");
	if (acl)
		acl_free(acl);
}
