/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 19:49:53 by carmand           #+#    #+#             */
/*   Updated: 2017/10/13 00:45:26 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ls.h"

t_list	*add_one(t_list *last, char *str)
{
	t_list	*new;

	new = NULL;
	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new->content = str;
	new->content_size = ft_strlen(str);
	new->next = NULL;
	last->next = new;
	return (new);
}

t_list	*remake_list(char **moche)
{
	t_list	*new;
	t_list	*tmp;
	int		i;

	new = NULL;
	tmp = NULL;
	i = 0;
	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new->content = moche[i];
	new->content_size = ft_strlen(moche[i]);
	new->next = NULL;
	i++;
	tmp = new;
	while (moche[i] != NULL)
	{
		tmp = add_one(tmp, moche[i]);
		i++;
	}
	return (new);
}

t_list	*sort_dir_r(t_ls *ls)
{
	t_list	*tmp;
	int		i;
	char	**moche;
	int		j;

	i = 1;
	tmp = ls->dir;
	while (tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	if (!(moche = (char**)malloc(sizeof(char*) * i + 1)))
		return (NULL);
	tmp = ls->dir;
	j = i - 1;
	moche[i] = NULL;
	while (tmp)
	{
		if (!(moche[j] = ft_strdup(tmp->content)))
			return (NULL);
		j--;
		tmp = tmp->next;
	}
	return (remake_list(moche));
}

t_list	*sort_opdir(t_ls *ls)
{
	if (ls->option['t'] == 1)
		ls->dir = sort_dir_t(ls);
	if (ls->option['r'] == 1)
		ls->dir = sort_dir_r(ls);
	return (ls->dir);
}
