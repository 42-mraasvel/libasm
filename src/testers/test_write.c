/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_write.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 10:20:56 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/03/07 22:09:03 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	run_test_write(int p1, void *p2, size_t p3, int *i, ssize_t (*fnc)(int, void*, size_t))
{
	ssize_t	ret;

	printf("\tTest %d: write(%d, \"%.10s\", %lu)", *i, p1, (char*)p2, p3);
	*i += 1;
	ret = fnc(p1, p2, p3);
	printf("\t|%ld| : RET\n", ret);
	if (ret < 0)
	{
		int tmp_err = dup(STDERR_FILENO);
		dup2(STDOUT_FILENO, STDERR_FILENO);
		perror("\t\tWrite");
		dup2(tmp_err, STDERR_FILENO);
		close(tmp_err);
		printf("\n");
	}
}

void	test_write(void *function)
{
	int i;
	int fds[2];

	printf("Write Tests:\n");
	if (pipe(fds) == -1)
		return ;
	i = 0;
	run_test_write(-1, "1324", 0, &i, function);
	run_test_write(fds[1], "1324", 0, &i, function);
	run_test_write(fds[1], "1324", 3, &i, function);
	run_test_write(fds[1], "1324", 4, &i, function);
	run_test_write(fds[1], "", 0, &i, function);
	run_test_write(fds[1], "abcdef", 6, &i, function);
	close(fds[0]);
	close(fds[1]);
}
