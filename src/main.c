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

int	main(int argc, char **argv)
{
	t_data	data;

	if (parse_args(argc, argv, &data) == FAIL)
		error("Parsing failed.");
	init_data(&data);
	// start_simulation(&data);
	cleanup(&data);
}
