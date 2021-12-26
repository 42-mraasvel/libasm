/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_strdup.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 11:16:53 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/03/07 22:00:51 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static void	run_test_strdup(int *i, char *(*fct)(const char*), const char *s1)
{
	char	*result;

	printf("\tTest %d: ", *i);
	*i += 1;

	printf("strdup(\"%s\")", s1);
	result = fct(s1);
	if (result == NULL)
	{
		printf("|%p| - RET\n", result);
		perror("Strdup");
		return ;
	}
	printf(" RESULT: |%s|\n", result);
	free(result);
}

void	test_strdup(void *function)
{
	int i;

	printf("Strdup Tests:\n");
	i = 0;
	run_test_strdup(&i, function, "12348971293847");
	run_test_strdup(&i, function, "");
	run_test_strdup(&i, function, "a");
	run_test_strdup(&i, function, "12");
}
