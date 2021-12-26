/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_list_size.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 23:07:54 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/03/08 14:33:51 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libasm.h"
#include "bonus_ref.h"

static void	run_listsize_test(int (*fct)(t_list *), size_t size, t_listtype type, int param)
{
	t_list	*begin_list;

	begin_list = new_list(size, type, param);
	if (begin_list == NULL)
	{
		printf("Malloc failed on linked list test\n");
		return ;
	}
	printf("\t|%d| - Size\n", fct(begin_list));
	free_list(begin_list, free);
}

void	test_list_size(void *function)
{
	printf("List_size Tests:\n");
	run_listsize_test(function, 10, string, 10);
	run_listsize_test(function, 10, number, 10);
	run_listsize_test(function, 1, number, 10);
	run_listsize_test(function, 50, number, 1000);
	run_listsize_test(function, 10000, number, 1000);
}
