#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				val;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*head;
	int				size;

}					t_stack;

typedef struct s_data
{
	t_stack			a;
	t_stack			b;
	int				moves_count;
	int				bench;

}					t_data;

#endif