/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_ls_option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 03:14:23 by ttresori          #+#    #+#             */
/*   Updated: 2017/10/20 03:14:25 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ls.h"

t_list	*dir_default(void)
{
	t_list *new;

	new = NULL;
	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!(new->content = ft_strdup(".")))
		return (NULL);
	new->next = NULL;
	new->content_size = 1;
	return (new);
}

int		stock_error(t_ls *ls, char *arg)
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
	if (ls->error == NULL)
		ls->error = new;
	else
	{
		tmp = ls->error;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (1);
}
