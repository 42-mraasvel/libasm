/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_sort_ref.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 11:25:59 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/03/08 11:29:31 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "bonus_ref.h"
#include "libasm.h"

/*
** Sorting by swapping pointers: Bubble sort
*/

void	ft_list_sort_ref(t_list **begin_list, int (*cmp)())
{
	t_list	**itr;
	t_list	*ptrs[2];
	int		i[2];
	int		size;

	if (begin_list == NULL || *begin_list == NULL)
		return ;
	size = ft_list_size_ref(*begin_list);
	i[0] = 0;
	while (i[0] < size - 1)
	{
		itr = begin_list;
		i[1] = 0;
		while (i[1] < size - i[0] - 1)
		{
			ptrs[0] = *itr;
			ptrs[1] = (*itr)->next;
			if (cmp(ptrs[0]->data, ptrs[1]->data) > 0)
			{
				ptrs[0]->next = ptrs[1]->next;
				ptrs[1]->next = ptrs[0];
				*itr = ptrs[1];
			}
			itr = &((*itr)->next);
			i[1]++;
		}
		i[0]++;
	}
}

/*
** Sorting by swapping data: Selection sort
*/

/*
** void	ft_swap_ptrs(void **a, void **b)
** {
** 	void	*tmp;
** 
** 	tmp = *a;
** 	*a = *b;
** 	*b = tmp;
** }
** 
** void ft_list_sort_ref(t_list **begin_list, int (*cmp)())
** {
** 	t_list *i;
** 	t_list *j;
** 	t_list *min;
** 
** 	if (begin_list == NULL || (*begin_list)->next == NULL)
** 		return ;
** 	i = *begin_list;
** 	while (i != NULL) {
** 		j = i->next;
** 		min = i;
** 		while (j != NULL) {
** 			if (cmp(min->data, j->data) > 0)
** 				min = j;
** 			j = j->next;
** 		}
** 		ft_swap_ptrs(&min->data, &i->data);
** 		i = i->next;
** 	}
** }
*/
