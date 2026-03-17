/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gviola-l <gviola-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:59:44 by gviola-l          #+#    #+#             */
/*   Updated: 2026/03/17 17:59:45 by gviola-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H

# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "struct.h"

// Init
void			init_data(t_data *data);

// Parsing
t_status		parse_args(int ac, char **av, t_data *data);

// Utils
unsigned int	ft_atoui(const char *nptr);
t_scheduler		ft_atosch(const char *nptr);
int				ft_strcmp(const char *s1, const char *s2);
size_t			ft_strlen(const char *s);
int				error(const char *msg);
int				ft_isnumber(const char *str);
void			cleanup(t_data *data);

#endif // CODEXION_H
