/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle_acquire.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gviola-l <gviola-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:38:40 by gviola-l          #+#    #+#             */
/*   Updated: 2026/03/17 17:38:41 by gviola-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static int	can_take(t_dongle *dongle, unsigned int coder_id)
{
	t_request	top;

	if (dongle->wait_queue.size == 0)
		return (0);
	top = queue_peek(&dongle->wait_queue);
	if (top.coder_id != coder_id)
		return (0);
	if (!dongle->available)
		return (0);
	return (1);
}

static int	cooldown_ok(t_dongle *dongle, t_data *data)
{
	if (dongle->last_release_ms == 0)
		return (1);
	if (get_time_ms() - dongle->last_release_ms >= data->dongle_cooldown)
		return (1);
	return (0);
}

static void	acquire_dongle(t_coder *coder, t_data *data, t_dongle *dongle)
{
	t_request	req;

	req.coder_id = coder->id;
	req.deadline = coder->last_compile_ms + data->time_to_burnout;
	pthread_mutex_lock(&data->counter_mutex);
	req.arrival_order = data->request_counter++;
	pthread_mutex_unlock(&data->counter_mutex);
	pthread_mutex_lock(&dongle->mutex);
	queue_push(&dongle->wait_queue, req);
	while (is_running(data) && !can_take(dongle, coder->id))
		pthread_cond_wait(&dongle->cond, &dongle->mutex);
	while (is_running(data) && !cooldown_ok(dongle, data))
		usleep(200);
	if (is_running(data))
	{
		queue_pop(&dongle->wait_queue);
		dongle->available = false;
	}
	pthread_mutex_unlock(&dongle->mutex);
}

void	get_dongle_order(t_coder *coder, t_dongle **first, t_dongle **second)
{
	if (coder->left_idx <= coder->right_idx)
	{
		*first = coder->left;
		*second = coder->right;
	}
	else
	{
		*first = coder->right;
		*second = coder->left;
	}
}

void	acquire_dongles(t_coder *coder, t_data *data)
{
	t_dongle	*first;
	t_dongle	*second;

	get_dongle_order(coder, &first, &second);
	acquire_dongle(coder, data, first);
	if (!is_running(data))
		return ;
	log_action(data, coder->id, "has taken a dongle");
	acquire_dongle(coder, data, second);
	if (!is_running(data))
		return ;
	log_action(data, coder->id, "has taken a dongle");
}
