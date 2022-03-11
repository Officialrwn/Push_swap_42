#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define A 	1
# define B 	2
# define AB 3
# define OP_INDEX "00011222333"

# include <unistd.h>
# include <stdlib.h>

typedef struct s_struct
{
	int		flag;
	//stack a_head;
	//stack a_tail;
	//stack b_head;
	//stack b_tail;
}	t_struct;

void	swap_ab(t_struct *st);
void	push_ab(t_struct *st);
void	rotate_ab(t_struct *st);
void	reverse_rotate_ab(t_struct *st);

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
