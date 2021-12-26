/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prototypes.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/26 11:39:49 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/03/10 12:17:35 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "tester.h"

void	*get_function(int flag, t_output type);
t_bool	check_args(int argc, char *argv[], t_data *data);

int		example_test(void);

/* Testers */

void	test(t_data *data);

void	test_strlen(void *function);
void	test_strcpy(void *function);
void	test_strcmp(void *function);
void	test_write(void *function);
void	test_read(void *function);
void	test_strdup(void *function);

#endif
