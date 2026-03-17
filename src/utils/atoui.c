/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gviola-l <gviola-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:46:49 by gviola-l          #+#    #+#             */
/*   Updated: 2026/03/17 17:38:00 by gviola-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_atoui(const char *nptr)
{
	unsigned int	res;

	res = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '-')
		return (0);
	if (*nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
		res = res * 10 + (*nptr++ - '0');
	return (res);
}
