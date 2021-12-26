/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_list_size_ref.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 11:13:26 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/03/08 11:14:27 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libasm.h"

int	ft_list_size_ref(t_list *begin_list)
{
	int	i;

	i = 0;
	while (begin_list != NULL)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}
