/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/21 22:44:10 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/03/07 21:48:25 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "tester.h"

static void	test_function(int flag, void *function)
{
	static const t_tester	testers[] = {
		test_strlen,
		test_strcpy,
		test_strcmp,
		test_write,
		test_read,
		test_strdup
	};

	testers[flag](function);
}

void	test(t_data *data)
{
	int	i;

	i = 0;
	while (i < FUNCTION_COUNT)
	{
		if (data->flags[i] == true) {
			test_function(i, get_function(i, data->output));
		}
		i++;
	}
}
