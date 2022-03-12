#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define STDIN 	0
# define A 		1
# define B 		2
# define AB 	3

# define OP_INDEX "00011222333"
# define OP_SIZE sizeof(g_op) / sizeof(g_op[0])

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

/* Forbidden header */
# include <stdio.h>

typedef struct s_struct
{
	t_list	*head;
	int		flag;
	int		*stack_a;
	int 	*stack_b;
}	t_struct;

void	swap_ab(t_struct *st);
void	push_ab(t_struct *st);
void	rotate_ab(t_struct *st);
void	reverse_rotate_ab(t_struct *st);
void	initialize_struct(t_struct *st, int size);

typedef void		(*func_ptr)(t_struct *st);

static const func_ptr	g_execute_op[4] = {
	swap_ab,
	push_ab,
	rotate_ab,
	reverse_rotate_ab,
};

static const char		*g_op[] = {
	"sa",
	"sb",
	"ss",
	"pa",
	"pb",
	"ra",
	"rb",
	"rr",
	"rra",
	"rrb",
	"rrr",
};

#endif
