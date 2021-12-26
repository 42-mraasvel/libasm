/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_read.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 11:01:38 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/03/10 12:13:17 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include "tester.h"

ssize_t	ft_read(int fd, void *buf, size_t count);

static void	run_test_read(int *i, ssize_t (*fct)(int, void*, size_t), int p1, char *buffer, int out, char *input)
{
	ssize_t	ret;
	size_t	len;

	printf("\tTest %d: ", *i);
	*i += 1;

	len = strlen(input);
	if (write(out, input, len) == -1)
		return ;
	ret = fct(p1, buffer, READ_SIZE);
	if (ret < 0)
	{
		printf("RET - |%ld|\n", ret);
		int tmp_err = dup(STDERR_FILENO);
		dup2(STDOUT_FILENO, STDERR_FILENO);
		perror("\t\tRead");
		dup2(tmp_err, STDERR_FILENO);
		close(tmp_err);
		return ;
	}
	buffer[ret - 1] = '\0';
	printf("|%.20s| : RET - |%ld|\n", buffer, ret);
}

void	test_read(void *function)
{
	int i;
	int fds[2];
	char buffer[READ_SIZE];

	printf("Read Tests:\n");
	if (pipe(fds) == -1)
		return ;
	i = 0;
	run_test_read(&i, function, fds[0], buffer, fds[1], "Duplicating FD testing");
	run_test_read(&i, function, fds[0], buffer, fds[1], "1");
	run_test_read(&i, function, fds[0], buffer, fds[1], "1234");
	run_test_read(&i, function, fds[0], buffer, fds[1], "HOW DO I TEST THESE");
	run_test_read(&i, function, -1, buffer, fds[1], "Error");
	close(fds[0]);
	close(fds[1]);
}