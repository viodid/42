/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:11:25 by dyunta            #+#    #+#             */
/*   Updated: 2022/11/20 22:52:57 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"

t_node	*create_node(int num, char *w, t_node *header)
{
	t_node	*n;

	n = malloc(sizeof(t_node));
	if (n == NULL)
		return (0);
	n->number = num;
	n->word = w;
	n->next = header;
	return (n);
}

t_node	*create_linked_list(int num, char *str, t_node *header)
{
	header = create_node(num, str, header);
	return (header);
}
