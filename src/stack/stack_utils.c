/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 15:18:22 by ben               #+#    #+#             */
/*   Updated: 2026/11/06 12:34:05 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// new_node		makes a node (you did this)
// add_front	puts a node at the top
// add_back		puts a node at the bottom
// remove_front	takes the top node out and gives it back
// free_stack	frees every node

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->val = value;
	node->next = NULL;
	return (node);
}

void	add_front(t_stack *stack, t_node *new)
{
	if (!stack || !new)
		return ;
	new->next = stack->head;
	stack->head = new;
	stack->size += 1;
}

void	add_back(t_stack *stack, t_node *new)
{
	t_node	*curr;

	if (!stack || !new)
		return ;
	if (!stack->head)
	{
		add_front(stack, new);
		return ;
	}
	curr = stack->head;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new;
	new->next = NULL;
	stack->size += 1;
}

t_node	*remove_front(t_stack *stack)
{
	t_node	*head_node;

	if (!stack || !stack->head)
		return (NULL);
	head_node = stack->head;
	stack->head = head_node->next;
	stack->size -= 1;
	head_node->next = NULL;
	return (head_node);
}

void	free_stack(t_stack *stack)
{
	t_node	*curr;
	t_node	*next_node;

	if (!stack || !stack->head)
		return ;
	curr = stack->head;
	while (curr)
	{
		next_node = curr->next;
		free(curr);
		curr = next_node;
	}
	stack->head = NULL;
	stack->size = 0;
}
