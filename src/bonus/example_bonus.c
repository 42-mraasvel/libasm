/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   example.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/10 12:05:14 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/03/10 12:09:48 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_ref.h"
#include "prototype_bonus.h"
#include "libasm.h"

int	example_test(void)
{
	test_strlen(ft_strlen);
	test_strcpy(ft_strcpy);
	test_strcmp(ft_strcmp);
	test_write(ft_write);
	test_read(ft_read);
	test_strdup(ft_strdup);
	test_atoi_base(ft_atoi_base);
	test_list_push_front(ft_list_push_front);
	test_list_size(ft_list_size);
	test_list_sort(ft_list_sort);
	test_list_remove_if(ft_list_remove_if);
	return (0);
}
