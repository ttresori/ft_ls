/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <ttresori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 04:19:50 by ttresori          #+#    #+#             */
/*   Updated: 2017/10/06 21:37:51 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ls.h"

void	ft_major(struct stat *sts, t_ls *ls)
{
	ft_padding_size(ls, sts);
	ft_putnbr(major(sts->st_rdev));
	ft_putchar(',');
	ft_print_space(1);
	ft_putnbr(minor(sts->st_rdev));
}

int		ft_date_before_year(struct stat *sts, time_t actualtime)
{
	char	*str1;
	char	*str2;

	str1 = ctime(&sts->st_mtime);
	if ((actualtime - 15778463) > sts->st_mtime || actualtime < sts->st_mtime)
	{
		str2 = ft_strnew(6);
		str2 = ft_strsub(str1, 20, 4);
		str1 = ft_strsub(str1, 4, 6);
		str1 = ft_strjoin(str1, "  ");
		str1 = ft_strjoin(str1, str2);
		free(str2);
	}
	ft_putstr(str1);
	return (0);
}

int		ft_date(char *name, t_ls *ls)
{
	struct stat		sts;
	struct group	*grp;
	struct passwd	*user;
	time_t			actualtime;

	actualtime = time(0);

	errno = 0;
	grp = NULL;
	user = NULL;
	if ((lstat(name, &sts)) != 0)
		return (0);
	ft_right(&sts, name);
	ft_putnbrspace(sts.st_nlink);
	if ((user = getpwuid(sts.st_uid)) != NULL)
		ft_putstrspace(ft_padding_pwn_name(ls, user));
	else
	{
		ft_putchar(' ');
		ft_putnbrspace(sts.st_uid);
	}
		if ((grp = getgrgid(sts.st_gid)) != NULL)
			ft_putstrspace(ft_padding_grp_name(ls, grp));
	if (S_ISCHR(sts.st_mode))
		ft_major(&sts, ls);
	else
		ft_putnbr(ft_padding_size(ls, &sts));
	ft_print_space(1);
	if ((actualtime - 15778463) > sts.st_mtime || actualtime < sts.st_mtime)
		ft_date_before_year(&sts, actualtime);
	else
		ft_startstop(ctime(&sts.st_mtime), 4, ft_strlen(ctime(&sts.st_mtime)) - 9);
	ft_putchar(' ');
	return (1);
}

