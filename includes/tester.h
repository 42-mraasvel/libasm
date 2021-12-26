/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tester.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/26 11:39:49 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/03/10 12:18:02 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_H
# define TESTER_H

# define FUNCTION_COUNT 6
# define READ_SIZE 1000

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef enum e_types
{
	id_strlen,
	id_strcpy,
	id_strcmp,
	id_write,
	id_read,
	id_strdup
}	t_types;

typedef enum e_output
{
	ft_version,
	std_version,
	both
}	t_output;

typedef struct s_data
{
	t_bool		flags[FUNCTION_COUNT];
	t_output	output;
}	t_data;

/* Function typedef */

typedef void	(*t_tester)(void*);

#endif
