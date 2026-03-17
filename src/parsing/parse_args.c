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
	static int	i = 0;

	if (ac != 9)
		return (FAIL);
	while (i < 8)
		if (!ft_isnumber(av[i++]))
			return (FAIL);
	data->number_of_coders = (unsigned int)ft_atoui(av[1]);
	data->time_to_burnout = (unsigned int)ft_atoui(av[2]);
	data->time_to_compile = (unsigned int)ft_atoui(av[3]);
	data->time_to_debug = (unsigned int)ft_atoui(av[4]);
	data->time_to_refactor = (unsigned int)ft_atoui(av[5]);
	data->number_of_compiles_required = (unsigned int)ft_atoui(av[6]);
	data->dongle_cooldown = (unsigned int)ft_atoui(av[7]);
	data->scheduler = (t_scheduler)ft_atosch(av[8]);
	if (data->number_of_coders == 0
		|| data->time_to_burnout == 0
		|| data->time_to_compile == 0
		|| data->time_to_debug == 0
		|| data->time_to_refactor == 0)
		return (FAIL);
	return (SUCCESS);
}
