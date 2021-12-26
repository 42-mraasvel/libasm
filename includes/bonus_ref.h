/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bonus_ref.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 22:31:45 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/03/10 12:17:01 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_REF_H
# define BONUS_REF_H

# include "libasm.h"

void	ft_list_push_front_ref(t_list **begin_list, void *data);
int		ft_list_size_ref(t_list *begin_list);
void	ft_list_sort_ref(t_list **begin_list, int (*cmp)());
void	ft_list_remove_if_ref(t_list **begin_list,
			void *data_ref, int (*cmp)(), void (*free_fct)(void *));
int		ft_atoi_base_ref(char *str, char *base);

/* Testers */

void	test_list_push_front(void *function);
void	test_list_size(void *function);
void	test_list_sort(void *function);
void	test_list_remove_if(void *function);
void	test_atoi_base(void *function);

/* Utils for list testing */

# ifndef RAND_SEED
#  define RAND_SEED 0
# endif

typedef enum e_listtype
{
	number,
	string
}	t_listtype;

t_list	*new_list(size_t size, t_listtype type, size_t param);
void	free_list(t_list *begin_list, void (*del)(void*));
void	print_list_wrap(t_list *begin_list, t_listtype type);
char	*random_str(size_t size);
int		*random_int(size_t max);

#endif
