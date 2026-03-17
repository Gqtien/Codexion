/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atosch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gviola-l <gviola-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:38:03 by gviola-l          #+#    #+#             */
/*   Updated: 2026/03/17 17:38:04 by gviola-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

t_scheduler	ft_atosch(const char *nptr)
{
	if (ft_strcmp(nptr, "fifo") == 0)
		return (FIFO);
	else if (ft_strcmp(nptr, "edf") == 0)
		return (EDF);
	error("Scheduler value must be one of: \"FIFO\", \"EDF\"");
}
