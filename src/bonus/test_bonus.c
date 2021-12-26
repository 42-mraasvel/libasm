/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_bonus.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 10:35:23 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/03/08 15:01:07 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "prototype_bonus.h"
#include "test_bonus.h"
#include "bonus_ref.h"

static void	test_function(int flag, void *function)
{
	static const t_tester	testers[] = {
		test_strlen,
		test_strcpy,
		test_strcmp,
		test_write,
		test_read,
		test_strdup,
		test_list_push_front,
		test_list_size,
		test_list_sort,
		test_list_remove_if,
		test_atoi_base
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
