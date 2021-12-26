/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_push_front_ref.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 22:29:40 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/03/07 23:06:12 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libasm.h"

static t_list	*ft_create_elem(void *data)
{
	t_list	*new;

	new = (t_list*)malloc(1 * sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

void	ft_list_push_front_ref(t_list **begin_list, void *data)
{
	t_list	*tmp;

	if (begin_list == NULL)
		return ;
	tmp = *begin_list;
	*begin_list = ft_create_elem(data);
	if (*begin_list == NULL)
		return ;
	(*begin_list)->next = tmp;
}
