/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gviola-l <gviola-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:38:36 by gviola-l          #+#    #+#             */
/*   Updated: 2026/03/17 17:38:37 by gviola-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	parse_args(int ac, char **av, t_data *data)
{
	int	i;

	if (ac != 9)
		error("Invalid argument count. Expected 8 arguments.");
	i = 1;
	while (i < 8)
		if (!ft_isnumber(av[i++]))
			error("All first 7 arguments must be positive integers.");
	*data = (t_data){
		.number_of_coders = ft_atoui(av[1]),
		.time_to_burnout = ft_atoui(av[2]),
		.time_to_compile = ft_atoui(av[3]),
		.time_to_debug = ft_atoui(av[4]),
		.time_to_refactor = ft_atoui(av[5]),
		.number_of_compiles_required = ft_atoui(av[6]),
		.dongle_cooldown = ft_atoui(av[7]),
		.scheduler = ft_atosch(av[8]),
	};
	if (!data->number_of_coders
		|| !data->time_to_burnout
		|| !data->time_to_compile
		|| !data->time_to_debug
		|| !data->time_to_refactor)
		error("number_of_coders, time_to_burnout, time_to_compile, "
			"time_to_debug and time_to_refactor must be greater than 0.");
}
