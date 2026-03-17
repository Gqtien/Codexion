/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gviola-l <gviola-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 18:04:34 by gviola-l          #+#    #+#             */
/*   Updated: 2026/03/17 18:04:35 by gviola-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

// TODO: free scheduler queue
void	cleanup(t_data *data)
{
	unsigned int	i;

	if (!data)
		return ;
	if (data->dongles)
	{
		i = 0;
		while (i < data->number_of_coders)
			pthread_mutex_destroy(&data->dongles[i++].mutex);
		free(data->dongles);
		data->dongles = NULL;
	}
	pthread_mutex_destroy(&data->log_mutex);
	if (data->coders)
	{
		free(data->coders);
		data->coders = NULL;
	}
}
