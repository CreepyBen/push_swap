/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 16:09:13 by ben               #+#    #+#             */
/*   Updated: 2026/11/05 16:12:46 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// void		init_stack(t_stack *stack);

void	init_stack(t_stack *stack)
{
	stack->head = NULL;
	stack->size = 0;
}
// t_node	*last_node(t_stack *stack);

t_node	*last_node(t_stack *stack)
{
	t_node *curr;
	if(!stack || !stack->head)
		return (NULL);
	curr = stack->head;
	while(curr->next != NULL)
	{
		curr = curr->next;
	}
	return (curr);
}
// t_node	*remove_back(t_stack *stack);

t_node	*remove_back(t_stack *stack)
{
	
}
// int		is_sorted(t_stack *stack);