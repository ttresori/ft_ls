#include "lib_ls.h"

void print_no_dir(char *name, t_ls *ls)
{
	if (ls->option['l'] == 1)
	{
		ft_date(name, ls);
		ft_putchar(' ');
		ft_putendl(name);
	}
	else
		ft_putendl(name);
}

int check_arg(char *name, t_ls *ls)
{
	struct stat sts;

	if (lstat(name, &sts) != 0)
		return (0);
	if (!(S_ISDIR(sts.st_mode)))
		print_no_dir(name, ls);
	return(0);
}
