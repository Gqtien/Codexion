/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gviola-l <gviola-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:38:17 by gviola-l          #+#    #+#             */
/*   Updated: 2026/03/17 17:38:18 by gviola-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	is_running(t_data *data)
{
	int	running;

	pthread_mutex_lock(&data->simulation_mutex);
	running = data->running;
	pthread_mutex_unlock(&data->simulation_mutex);
	return (running);
}

static void	wake_all(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->number_of_coders)
		pthread_cond_broadcast(&data->dongles[i++].cond);
}

static void	start_simulation(t_data *data)
{
	unsigned int	i;

	data->start_time = get_time_ms();
	i = 0;
	while (i < data->number_of_coders)
	{
		data->coders[i].last_compile_ms = data->start_time;
		i++;
	}
	data->running = true;
	pthread_create(&data->monitor_thread, NULL, monitor_routine, data);
	i = 0;
	while (i < data->number_of_coders)
	{
		pthread_create(&data->coders[i].thread, NULL,
			coder_routine, &data->coders[i]);
		i++;
	}
	pthread_join(data->monitor_thread, NULL);
	wake_all(data);
	i = 0;
	while (i < data->number_of_coders)
		pthread_join(data->coders[i++].thread, NULL);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (parse_args(argc, argv, &data) == FAIL)
		error("Parsing failed.");
	init_data(&data);
	start_simulation(&data);
	cleanup(&data);
	return (0);
}
