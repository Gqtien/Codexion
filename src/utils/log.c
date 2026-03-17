/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gviola-l <gviola-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:38:22 by gviola-l          #+#    #+#             */
/*   Updated: 2026/03/17 17:38:23 by gviola-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	log_action(t_data *data, unsigned int id, char *action)
{
	pthread_mutex_lock(&data->log_mutex);
	if (data->running)
		printf("%lu %u %s\n", get_time_ms() - data->start_time, id, action);
	pthread_mutex_unlock(&data->log_mutex);
}
