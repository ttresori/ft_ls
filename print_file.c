void print_no_dir(char *name, t_ls *ls)
{
	if (ls->option['l'] == 1)
	{
		ft_date(name, ls);
		ft_putchar('\n');
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

int ls_option(t_ls *ls, int a, char **v)
{
	int i;
	int error;

	error = 0;
	ls->option_enable = ft_strdup("larRt");
	ls->dir = NULL;
	ls->nb_dir = 0;
	ls->dir_write = -1;
	if (a > 0)
	{
		i = 1;
		while (i < a)
		{
			if (v[i][0] == '-')
				detect_option(v[i], ls, error);
			else if ((add_dir(v[i], ls)) == 0)
				return (0);
			else if (check_arg(v[i], ls))
				error = 0;
			else
				error = 1;
			i++;
		}
	}
	if (error == 0)
		ls->dir = dir_default();
	return (1);
}
