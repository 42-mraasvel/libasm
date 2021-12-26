/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_bonus.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/26 11:39:49 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/03/10 12:18:07 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_BONUS_H
# define TEST_BONUS_H

# define FUNCTION_COUNT 11
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
