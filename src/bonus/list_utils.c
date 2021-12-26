/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 23:10:28 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/03/08 11:18:18 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libasm.h"
#include "bonus_ref.h"

void	free_list(t_list *begin_list, void (*del)(void*))
{
	t_list	*tmp;

	if (begin_list == NULL)
		return ;
	tmp = begin_list;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		if (del != NULL)
			del(begin_list->data);
		free(begin_list);
		begin_list = tmp;
	}
}

void	print_list_int(t_list *begin_list)
{
	while (begin_list != NULL)
	{
		
		printf("%d ", *(int*)begin_list->data);
		begin_list = begin_list->next;
	}
	printf("\n");
}

void	print_list_str(t_list *begin_list)
{
	while (begin_list != NULL)
	{
		printf("%s\n", (char*)begin_list->data);
		begin_list = begin_list->next;
	}
}

void	print_list_wrap(t_list *begin_list, t_listtype type)
{
	if (type == number)
		print_list_int(begin_list);
	else if (type == string)
		print_list_str(begin_list);
}

char	random_print(void)
{
	return ((char)(rand() % 95 + 32));
}

char	random_digit_ascii(void)
{
	return ((char)(rand() % 10 + '0'));
}

char	*random_str(size_t size)
{
	char	*new;

	new = (char*)malloc((size + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	new[size] = '\0';
	while (size > 0)
	{
		size--;
		new[size] = random_digit_ascii();
	}
	return (new);
}

int		*random_int(size_t max)
{
	int	*new;

	new = malloc(1 * sizeof(int));
	if (new == NULL)
		return (NULL);
	*new = rand() % max;
	if (rand() % 2 == 0)
		*new = -(*new);
	return (new);
}

t_list	*new_list(size_t size, t_listtype type, size_t param)
{
	t_list	*begin_list;

	begin_list = NULL;
	if (type == number)
	{
		while (size > 0)
		{
			ft_list_push_front_ref(&begin_list, random_int(param));
			size--;
		}
	}
	else if (type == string)
	{
		while (size > 0)
		{
			ft_list_push_front_ref(&begin_list, random_str(param));
			size--;
		}
	}
	return (begin_list);
}
