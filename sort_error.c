/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 19:44:26 by carmand           #+#    #+#             */
/*   Updated: 2017/10/17 01:50:32 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ls.h"

t_list	*add_error(t_list *error, t_list *nxt, t_list *prv)
{
	t_list	*new;

	new = NULL;
	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!(new->content = ft_strdup(error->content)))
		return (NULL);
	new->content_size = error->content_size;
	new->next = nxt;
	if (prv != NULL)
		prv->next = new;
	return (new);
}

t_list	*fill_error(t_list *bgn, t_list *error)
{
	t_list *tmp;

	tmp = bgn;
	if ((ft_strcmp(tmp->content, error->content) > 0))
	{
		if (!(tmp = add_error(error, tmp, NULL)))
			return (NULL);
		return (tmp);
	}
	while (tmp->next)
	{
		ft_putstr("COUCOU");
		if ((ft_strcmp(tmp->content, error->content) > 0)
			&& (ft_strcmp(tmp->next->content, error->content) < 0))
			break ;
		else
			tmp = tmp->next;
	}
	if (!(tmp = add_error(error, tmp->next, tmp)))
		return (NULL);
	return (bgn);
}

t_list	*sort_error(t_list *bgn)
{
	t_list *new;

	new = NULL;
	if (!bgn)
		return (NULL);
	if (bgn == NULL)
		ft_putendl(bgn->content);
	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!(new->content = ft_strdup(bgn->content)))
		return (NULL);
	new->content_size = bgn->content_size;
	new->next = NULL;
	bgn = bgn->next;
	while (bgn)
	{
		if (!(new = fill_error(new, bgn)))
			return (NULL);
		bgn = bgn->next;
	}
	ls_print_error(new);
	return (new);
}
