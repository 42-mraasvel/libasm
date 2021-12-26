/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_strcpy.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 09:34:09 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/03/07 21:39:55 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void	run_strcpytest(int i, const char *src, char *(*cpy)(char *, const char *))
{
	char	*dst;
	char	*ptr;

	dst = NULL;
	if (src != NULL)
	{
		dst = (char*)malloc((strlen(src) + 1) * sizeof(char));
		if (dst == NULL)
			return ;
	}
	printf("\tTest %d: ", i);
	printf("ft_strcpy(dst, \"%s\")", src);
	ptr = cpy(dst, src);
	if (src == NULL)
		printf("|%p|, |%p| : dst/src", dst, src);
	else
		printf("|%.15s|, |%.15s| : dst/src", dst, src);
	if (ptr != dst)
		printf("\tPointer returned does not point to dst");
	printf("\n");
	free(dst);
	if (i == 6)
		exit(1);
}

void	test_strcpy(void *function)
{
	int	i;
	static const char *tests[] = {
		"",
		"432980987123",
		"asdfiahdfasdf",
		"129384719823749817234",
		"1293 847198 2  37498 17234",
		"1293]t \t847198 2  37498 17234",
		NULL
	};

	i = 0;
	printf("Strcpy Tests:\n");
	while (tests[i] != NULL)
	{
		run_strcpytest(i, tests[i], function);
		i++;
	}
}
