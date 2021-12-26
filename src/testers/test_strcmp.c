/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_strcmp.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 09:50:06 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/03/07 22:07:28 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void	run_strcmp_test(int *i, const char *s1, const char *s2, int (*cmp)(const char *, const char *))
{
	int	ret;

	printf("\tTest %d: ", *i);
	*i += 1;
	printf("ft_strcmp(\"%.20s\", \"%.20s\")\t", s1, s2);
	ret = cmp(s1, s2);

	//! Because documentation specifies less than zero and greater than zero, it's not necessary to test exact value
	if (ret > 0)
		ret = 1;
	else if (ret < 0)
		ret = -1;

	printf("|%d| : RET\n", ret);
}

void	test_strcmp(void *function)
{
	int i;
	printf("Strcmp Tests:\n");
	i = 0;
	run_strcmp_test(&i, "1234567890", "1234567890", function);
	run_strcmp_test(&i, "1234567890", "123456789a", function);
	run_strcmp_test(&i, "1234567890", "1234567890", function);
	run_strcmp_test(&i, "1234567890", "123456789a", function);
	run_strcmp_test(&i, "1234567890", "123456789a", function);
	run_strcmp_test(&i, "1234567890a", "1234567890", function);
	run_strcmp_test(&i, "123456789a", "1234567890", function);
	run_strcmp_test(&i, "1234567890", "1234567890", function);
	run_strcmp_test(&i, "1", "", function);
	run_strcmp_test(&i, "", "1", function);
	run_strcmp_test(&i, "", "", function);
	run_strcmp_test(&i, "", "", function);
	run_strcmp_test(&i, "a", "", function);
	run_strcmp_test(&i, "", "a", function);
	run_strcmp_test(&i, "123", "abc", function);
	run_strcmp_test(&i, "abcd", "abcd", function);
	run_strcmp_test(&i, "abcd", "abce", function);
	run_strcmp_test(&i, "abcd", "abd", function);
}
