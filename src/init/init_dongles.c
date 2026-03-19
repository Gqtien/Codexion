/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dongles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gviola-l <gviola-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:38:26 by gviola-l          #+#    #+#             */
/*   Updated: 2026/03/17 17:38:27 by gviola-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	init_dongles(t_data *data)
{
	unsigned int	i;
	int				(*cmp)(t_request, t_request);

	data->dongles = malloc(sizeof(t_dongle) * data->number_of_coders);
	if (!data->dongles)
		error("Dongles allocation failed.");
	if (data->scheduler == FIFO)
		cmp = cmp_fifo;
	else
		cmp = cmp_edf;
	i = 0;
	while (i < data->number_of_coders)
	{
		pthread_mutex_init(&data->dongles[i].mutex, NULL);
		pthread_cond_init(&data->dongles[i].cond, NULL);
		data->dongles[i].available = 1;
		data->dongles[i].last_release_ms = 0;
		init_queue(&data->dongles[i].wait_queue, cmp);
		i++;
	}
}
