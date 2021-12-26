/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   example.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/10 12:05:14 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/03/10 12:10:43 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "libasm.h"

int	example_test(void)
{
	test_strlen(ft_strlen);
	test_strcpy(ft_strcpy);
	test_strcmp(ft_strcmp);
	test_write(ft_write);
	test_read(ft_read);
	test_strdup(ft_strdup);
	return (0);
}
