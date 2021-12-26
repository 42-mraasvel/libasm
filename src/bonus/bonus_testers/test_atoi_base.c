/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_atoi_base.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 15:01:19 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/03/08 15:20:58 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "test_bonus.h"

void	run_atoi_base(int *i, int (*fct)(char *, char *), char *str, char *base)
{
	int	result;

	printf("Test %d:\t", *i);
	*i += 1;
	printf("atoi_base(\"%s\", \"%s\")", str, base);
	result = fct(str, base);
	printf("\n\t\tRET - |%d|\n", result);
}

void	test_atoi_base(void *function)
{
	int	i;

	printf("Atoi_base Tests:\n");
	i = 0;
	/* Invalid base checks */
	run_atoi_base(&i, function, "1234", " 0123456789");
	run_atoi_base(&i, function, "1234", "012+3456789");
	run_atoi_base(&i, function, "1234", "0123456 789");
	run_atoi_base(&i, function, "1234", "0");
	run_atoi_base(&i, function, "1234", "01235465");
	run_atoi_base(&i, function, "1234", "0123546-");
	/* Invalid strings checks */
	run_atoi_base(&i, function, "- 1234", "01");
	run_atoi_base(&i, function, "b1234", "01a");
	run_atoi_base(&i, function, "c1234", "0123456789");
	run_atoi_base(&i, function, "z          1234abcf", "0123456789abcdef");
	/* Negative Tests / Other */
	run_atoi_base(&i, function, " \t-1234", "01");
	run_atoi_base(&i, function, " \t-ppff", "poneyvif");
	run_atoi_base(&i, function, " \t-1234", "0123456789");
	run_atoi_base(&i, function, " \t-1234abcf", "0123456789abcdef");
	run_atoi_base(&i, function, " \t- 1234", "01");
	run_atoi_base(&i, function, " \t- 100000123412384", "01a");
	run_atoi_base(&i, function, " \t- 1234", "0123456789");
	run_atoi_base(&i, function, " \t- 1234abcf", "0123456789abcdef");
	run_atoi_base(&i, function, " \t-0fffffff", "0123456789abcdef");
	run_atoi_base(&i, function, " \t-ffffffff", "0123456789abcdef");
	run_atoi_base(&i, function, "-80000000", "0123456789abcdef");
	run_atoi_base(&i, function, "-80000001", "0123456789abcdef");
	run_atoi_base(&i, function, " \t-2147483647", "0123456789");
	run_atoi_base(&i, function, " \t+2147483647", "0123456789");
	run_atoi_base(&i, function, " \t-2147483648", "0123456789");
	run_atoi_base(&i, function, " \t+2147483648", "0123456789");
	
}
