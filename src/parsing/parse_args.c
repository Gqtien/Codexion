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

t_status	parse_args(int ac, char **av, t_data *data)
{
	int	i;

	if (ac != 9)
		return (FAIL);
	i = 1;
	while (i < 8)
		if (!ft_isnumber(av[i++]))
			return (FAIL);
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
	if (data->number_of_coders == 0
		|| data->time_to_burnout == 0
		|| data->time_to_compile == 0
		|| data->time_to_debug == 0
		|| data->time_to_refactor == 0)
		return (FAIL);
	return (SUCCESS);
}
