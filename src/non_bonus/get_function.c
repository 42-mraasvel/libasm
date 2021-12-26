/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_function.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/21 21:36:01 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/03/10 12:12:11 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "libasm.h"
#include "tester.h"

static void	*ft_function(int flag)
{
	// replace with ft_version after adding definitions
	static void	*functions[] = {
		ft_strlen,
		ft_strcpy,
		ft_strcmp,
		ft_write,
		ft_read,
		ft_strdup
	};

	if (flag > FUNCTION_COUNT)
		return (NULL);
	return (functions[flag]);
}

static void	*std_function(int flag)
{
	static void	*functions[] = {
		strlen,
		strcpy,
		strcmp,
		write,
		read,
		strdup
	};

	if (flag > FUNCTION_COUNT)
		return (NULL);
	return (functions[flag]);
}

/*
** Return pointer to appropriate
** test function
*/

void	*get_function(int flag, t_output type)
{
	if (type == ft_version)
		return (ft_function(flag));
	else if (type == std_version)
		return (std_function(flag));
	return (NULL);
}
