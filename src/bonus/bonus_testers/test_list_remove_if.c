/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_list_remove_if.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 14:18:03 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/03/08 14:37:44 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "bonus_ref.h"
#include "libasm.h"

static int	cmp_int2(int *a, int *b)
{
	if (*a > *b)
		return (0);
	return (1);
}

static int	cmp_int(int *a, int *b)
{
	if (*a < *b)
		return (0);
	return (1);
}

static int (*get_cmp(void))()
{
	if (rand() % 2 == 0)
		return (cmp_int2);
	return (cmp_int);
}

static void	run_listremoveif_test(
			int *i,
			void (*fct)(t_list **, void *, int (*cmp)(), void (*free_fct)(void*)),
			size_t size, int param)
{
	t_list	*begin_list;
	int	data_ref;

	printf("\nTest %d:\n", *i);
	*i += 1;
	begin_list = new_list(size, number, param);
	if (begin_list == NULL)
	{
		printf("Malloc failed on linked list test\n");
		return ;
	}
	data_ref = param / 2;
	printf("Before:\n");
	print_list_wrap(begin_list, number);
	fct(&begin_list, &data_ref, get_cmp(), free);
	printf("After:\n");
	print_list_wrap(begin_list, number);
	free_list(begin_list, free);
}

void	test_list_remove_if(void *function)
{
	int	i;

	i = 0;
	printf("\nList_remove_if Tests:\n");
	run_listremoveif_test(&i, function, 10, 10);
	run_listremoveif_test(&i, function, 20, 25);
	run_listremoveif_test(&i, function, 25, 100);
	run_listremoveif_test(&i, function, 10, 50);
}
