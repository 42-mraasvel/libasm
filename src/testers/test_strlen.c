/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_strlen.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/21 22:45:35 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/03/01 13:28:53 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include "prototypes.h"

static void	run_test_strlen(int i, size_t (*function)(const char *), const char *param)
{
	printf("\t%d: strlen(\"%s\"); :", i, param);
	printf("|%lu|\n", function(param));
}

/*
** size_t strlen(const char *s);
** size_t ft_strlen(const char *s);
** How do you even test the function properly
** maybe allocate a massive string?
*/

void	test_strlen(void *function)
{
	int	i;
	static const char *tests[] = {
		"",
		"432980987123",
		"asdfiahdfasdf",
		"129384719823749817234",
		NULL
	};

	i = 0;
	printf("Strlen Tests:\n");
	while (tests[i] != NULL)
	{
		// run_test_strlen(i, (size_t (*)(const char *))function, tests[i]);
		run_test_strlen(i, function, tests[i]);
		i++;
	}
}
