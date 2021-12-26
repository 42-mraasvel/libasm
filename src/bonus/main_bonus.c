/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_bonus.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/20 15:42:54 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/03/10 12:11:30 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h> // rm
#include <unistd.h> // rm
#include <stdio.h>
#include <stdlib.h>
#include "bonus_ref.h"
#include "libasm.h"
#include "test_bonus.h"
#include "prototype_bonus.h"

int	ft_error(const char *msg)
{
	printf("Error\n");
	printf("%s\n", msg);
	return (0);
}

/*
** Argument_1 will be the name of the function to be tested
** Argument_2 will determine if it displays the output of the std
** library function or the libasm version
*/

int	main(int argc, char *argv[])
{
	t_data	data;
	srand(RAND_SEED);

	// import libft bzero
	// libft strcmp
	if (argc == 2 && strcmp(argv[1], "example") == 0)
		return (example_test());
	bzero(&data, sizeof(t_data));
	if (!check_args(argc, argv, &data))
		return (ft_error("Invalid parameters"));
	if (data.output == ft_version)
		printf("Testing libasm functions\n");
	else
		printf("Testing stdlib functions\n");
	test(&data);
	return (0);
}
