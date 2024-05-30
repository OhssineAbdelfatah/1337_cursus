/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:42:25 by aohssine          #+#    #+#             */
/*   Updated: 2024/05/30 12:58:59 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// is sorted // locate in sort.c
// free stack // locate in main.c
void	push_swap(char **args)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		range;

	range = 15;
	stack_b = NULL;
	stack_a = fill_args(args);
	if (stack_a == NULL)
		put_message("Error\n", 2);
	if (lstsize(stack_a) <= 5)
		mini_sorted(&stack_a, &stack_b);
	else
	{
		if (lstsize(stack_a) > 100)
			range = 35;
		sort_to_b(&stack_a, &stack_b, range);
		sort_to_a(&stack_a, &stack_b);
	}
	return ;
}

void mian_2()
{
	system("leaks push_swap");
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
	{
		if (check_args(argc, argv) == -1)
		{
			put_message("Error\n", 2);
			return (0);
		}
		push_swap(argv);
	}
	mian_2();
}
