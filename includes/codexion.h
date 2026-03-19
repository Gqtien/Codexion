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
void			init_coders(t_data *data);
void			init_dongles(t_data *data);

// Parsing
void			parse_args(int ac, char **av, t_data *data);

// Threads
void			*coder_routine(void *arg);
void			*monitor_routine(void *arg);
void			wake_all(t_data *data);
int				is_running(t_data *data);

// Dongles
void			acquire_dongles(t_coder *coder, t_data *data);
void			release_dongles(t_coder *coder);

// Scheduler
int				cmp_fifo(t_request a, t_request b);
int				cmp_edf(t_request a, t_request b);

// Queue
void			init_queue(t_queue *q, int (*cmp)(t_request, t_request));
void			queue_push(t_queue *q, t_request req);
t_request		queue_pop(t_queue *q);
t_request		queue_peek(t_queue *q);
void			destroy_queue(t_queue *q);

// Utils
unsigned int	ft_atoui(const char *nptr);
t_scheduler		ft_atosch(const char *nptr);
int				ft_strcmp(const char *s1, const char *s2);
size_t			ft_strlen(const char *s);
void			log_action(t_data *data, unsigned int id, char *action);
int				error(const char *msg);
int				ft_isnumber(const char *str);
void			cleanup(t_data *data);
unsigned long	get_time_ms(void);
void			ft_usleep(unsigned long ms, t_data *data);

#endif // CODEXION_H
