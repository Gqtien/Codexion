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
	unsigned int	i;

	data->coders = malloc(sizeof(t_coder) * data->number_of_coders);
	data->dongles = malloc(sizeof(t_dongle) * data->number_of_coders);
	if (!data->coders || !data->dongles)
		error("Allocation failed.");
	i = 0;
	while (i < data->number_of_coders)
	{
		pthread_mutex_init(&data->dongles[i].mutex, NULL);
		data->dongles[i].available = 1;
		data->dongles[i++].last_release_ms = 0;
	}
	i = 0;
	while (i++ < data->number_of_coders)
	{
		data->coders[i - 1] = (t_coder){
			.id = i,
			.compiles_done = 0,
			.last_compile_ms = 0,
			.left = &data->dongles[i - 1],
			.right = &data->dongles[i % data->number_of_coders],
		};
	}
	pthread_mutex_init(&data->log_mutex, NULL);
}
