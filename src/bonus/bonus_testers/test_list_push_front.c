/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_list_push_front.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 23:07:54 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/03/08 15:02:02 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libasm.h"
#include "bonus_ref.h"

t_list	*new_list_function(void (*fct)(t_list **, void*), size_t size, t_listtype type, size_t param)
{
	t_list	*begin_list;

	begin_list = NULL;
	if (type == number)
	{
		while (size > 0)
		{
			fct(&begin_list, random_int(param));
			size--;
		}
	}
	else if (type == string)
	{
		while (size > 0)
		{
			fct(&begin_list, random_str(param));
			size--;
		}
	}
	return (begin_list);
}

void	run_pushfront_test(void (*fct)(t_list **, void*), size_t size, t_listtype type, int param)
{
	t_list	*begin_list;

	begin_list = new_list_function(fct, size, type, param);
	if (begin_list == NULL)
	{
		printf("Malloc failed on linked list test\n");
		return ;
	}
	print_list_wrap(begin_list, type);
	free_list(begin_list, free);
}

void	test_list_push_front(void *function)
{
	printf("List_push_front Tests:\n");
	run_pushfront_test(function, 10, string, 10);
	run_pushfront_test(function, 10, number, 10);
	run_pushfront_test(function, 1, number, 10);
	run_pushfront_test(function, 50, number, 1000);
}
