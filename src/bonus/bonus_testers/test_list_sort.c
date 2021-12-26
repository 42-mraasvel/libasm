/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_list_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 23:07:54 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/03/08 14:34:02 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libasm.h"
#include "bonus_ref.h"

static int	cmp_int(int *a, int *b)
{
	if (*a > *b)
		return (1);
	if (*a < *b)
		return (-1);
	return (0);
}

static int	cmp_int2(int *a, int *b)
{
	if (*a > *b)
		return (-1);
	if (*a < *b)
		return (1);
	return (0);
}

static int	(*get_cmp(t_listtype type))()
{
	if (type == string)
		return (&strcmp);
	if (rand() % 2 == 0)
		return (cmp_int);
	return (cmp_int2);
}

static void	run_listsort_test(int *i, void (*fct)(t_list **, int (*)()), size_t size, t_listtype type, int param)
{
	t_list	*begin_list;

	printf("\nTest %d:\n", *i);
	*i += 1;
	begin_list = new_list(size, type, param);
	if (begin_list == NULL)
	{
		printf("Malloc failed on linked list test\n");
		return ;
	}
	printf("Before:\n");
	print_list_wrap(begin_list, type);
	fct(&begin_list, get_cmp(type));
	printf("\nAfter:\n");
	print_list_wrap(begin_list, type);
	free_list(begin_list, free);
}

void	test_list_sort(void *function)
{
	int	i;

	i = 0;
	printf("List_sort Tests:\n");
	run_listsort_test(&i, function, 10, string, 10);
	run_listsort_test(&i, function, 10, number, 10);
	run_listsort_test(&i, function, 10, number, 10);
	run_listsort_test(&i, function, 10, number, 10);
	run_listsort_test(&i, function, 10, number, 10);
	run_listsort_test(&i, function, 1, number, 10);
	run_listsort_test(&i, function, 50, number, 1000);
}
