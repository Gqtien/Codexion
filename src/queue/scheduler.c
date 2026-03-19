/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scheduler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gviola-l <gviola-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:38:48 by gviola-l          #+#    #+#             */
/*   Updated: 2026/03/17 17:38:49 by gviola-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	cmp_fifo(t_request a, t_request b)
{
	if (a.arrival_order < b.arrival_order)
		return (-1);
	if (a.arrival_order > b.arrival_order)
		return (1);
	return (0);
}

int	cmp_edf(t_request a, t_request b)
{
	if (a.deadline < b.deadline)
		return (-1);
	if (a.deadline > b.deadline)
		return (1);
	return (0);
}
