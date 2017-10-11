/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_right.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <ttresori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 04:19:50 by ttresori          #+#    #+#             */
/*   Updated: 2017/10/06 23:53:15 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ls.h"

void	ft_right(struct stat *sts, char *name)
{
	int xattr;
	acl_t acl;

	ft_putchar((S_ISFIFO(sts->st_mode)) ? 'p' : '\0');
	ft_putchar((S_ISCHR(sts->st_mode)) ? 'c' : '\0');
	ft_putchar((S_ISLNK(sts->st_mode)) ? 'l' : '\0');
	ft_putchar((S_ISDIR(sts->st_mode)) ? 'd' : '\0');
	ft_putchar((S_ISBLK(sts->st_mode)) ? 'b' : '\0');
	ft_putchar((S_ISREG(sts->st_mode)) ? '-' : '\0');
	ft_putchar((S_ISSOCK(sts->st_mode)) ? 's' : '\0');
	ft_putchar((sts->st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((sts->st_mode & S_IWUSR) ? 'w' : '-');
	ft_putchar(((S_ISUID & sts->st_mode) && (S_IXUSR & sts->st_mode))  ? 's' :
		(S_ISUID & sts->st_mode) ? 'S' : (S_IXUSR & sts->st_mode) ? 'x' : '-');
	ft_putchar((sts->st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((sts->st_mode & S_IWGRP) ? 'w' : '-');
	ft_putchar(((S_ISGID & sts->st_mode) && (S_IXGRP & sts->st_mode)) ? 's' :
		(S_ISGID & sts->st_mode) ? 'S' : (S_IXGRP & sts->st_mode) ? 'x' : '-');
	ft_putchar((sts->st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((sts->st_mode & S_IWOTH) ? 'w' : '-');
	ft_putchar(((S_ISVTX & sts->st_mode) && (S_IXOTH & sts->st_mode)) ? 't' :
		(S_ISVTX & sts->st_mode) ? 'T' : (S_IXOTH & sts->st_mode) ? 'x' : '-');
	ft_putchar((xattr = listxattr(name, NULL, 1, XATTR_NOFOLLOW) > 0) ? '@' :
		((acl = acl_get_file(name, ACL_TYPE_EXTENDED)) != NULL &&
		 (!(S_ISLNK(sts->st_mode)))) ? '+' : ' ');
	ft_putstr("  ");
}
