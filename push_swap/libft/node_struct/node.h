/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:50:34 by leotran           #+#    #+#             */
/*   Updated: 2022/03/18 15:22:07 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
# define NODE_H

# include <stdlib.h>

typedef struct	s_node
{
	int		num;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

t_node	*ft_nodenew(int n);
t_node	*ft_nodepop(t_node **node);
void	ft_nodedel_front(t_node **node);
void	ft_nodeadd_front(t_node **head, t_node *node);
void	ft_nodeadd_end(t_node **tail, t_node *node);
void	ft_nodedel(t_node **head);
void	ft_nodeswap(t_node **head);

#endif
