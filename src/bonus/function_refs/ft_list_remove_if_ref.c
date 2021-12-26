/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_remove_if_ref.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 14:25:55 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/03/08 14:32:34 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bonus_ref.h"
#include "libasm.h"

void	ft_list_remove_if_ref(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*tmp;
	t_list	*prev;

	if (begin_list == NULL || *begin_list == NULL)
		return ;
	prev = NULL;
	tmp = *begin_list;
	while (tmp != NULL)
	{
		if (cmp(tmp->data, data_ref) == 0)
		{
			if (free_fct != NULL)
				free_fct(tmp->data);
			if (prev == NULL)
			{
				*begin_list = tmp->next;
				free(tmp);
				tmp = *begin_list;
			}
			else
			{
				prev->next = tmp->next;
				free(tmp);
				tmp = prev->next;
			}
			continue ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}
