/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gviola-l <gviola-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:38:29 by gviola-l          #+#    #+#             */
/*   Updated: 2026/03/17 17:38:30 by gviola-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	init_data(t_data *data)
{
	init_dongles(data);
	init_coders(data);
	pthread_mutex_init(&data->log_mutex, NULL);
	pthread_mutex_init(&data->simulation_mutex, NULL);
	pthread_mutex_init(&data->counter_mutex, NULL);
	data->request_counter = 0;
	data->running = false;
}
