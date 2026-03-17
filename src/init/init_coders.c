/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_coders.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gviola-l <gviola-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:38:31 by gviola-l          #+#    #+#             */
/*   Updated: 2026/03/17 17:38:32 by gviola-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	init_coders(t_data *data)
{
	unsigned int	i;

	data->coders = malloc(sizeof(t_coder) * data->number_of_coders);
	if (!data->coders)
		error("Allocation failed.");
	i = 0;
	while (i < data->number_of_coders)
	{
		data->coders[i] = (t_coder){
			.id = i + 1,
			.compiles_done = 0,
			.last_compile_ms = 0,
			.left = &data->dongles[i],
			.right = &data->dongles[(i + 1) % data->number_of_coders],
			.left_idx = i,
			.right_idx = (i + 1) % data->number_of_coders,
			.data = data,
		};
		pthread_mutex_init(&data->coders[i].mutex, NULL);
		i++;
	}
}
