/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gviola-l <gviola-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:38:44 by gviola-l          #+#    #+#             */
/*   Updated: 2026/03/17 17:38:45 by gviola-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	init_queue(t_queue *q, int (*cmp)(t_request, t_request))
{
	q->head = NULL;
	q->size = 0;
	q->cmp = cmp;
}

t_request	queue_peek(t_queue *q)
{
	return (q->head->req);
}

void	queue_push(t_queue *q, t_request req)
{
	t_node	*n;
	t_node	*prev;
	t_node	*curr;

	n = malloc(sizeof(t_node));
	if (!n)
		return ;
	n->req = req;
	n->next = NULL;
	prev = NULL;
	curr = q->head;
	while (curr && q->cmp(curr->req, req) < 0)
	{
		prev = curr;
		curr = curr->next;
	}
	n->next = curr;
	if (prev)
		prev->next = n;
	else
		q->head = n;
	q->size++;
}

t_request	queue_pop(t_queue *q)
{
	t_node		*old;
	t_request	req;

	old = q->head;
	req = old->req;
	q->head = old->next;
	free(old);
	q->size--;
	return (req);
}

void	destroy_queue(t_queue *q)
{
	t_node	*curr;
	t_node	*next;

	curr = q->head;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	q->head = NULL;
	q->size = 0;
}
