/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gviola-l <gviola-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:59:47 by gviola-l          #+#    #+#             */
/*   Updated: 2026/03/17 17:59:48 by gviola-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <pthread.h>
# include <stdbool.h>

typedef enum e_status
{
	SUCCESS,
	FAIL,
}	t_status;

typedef enum e_scheduler
{
	FIFO,
	EDF,
}	t_scheduler;

typedef struct s_dongle
{
	pthread_mutex_t	mutex;
	int				available;
	long			last_release_ms;
}	t_dongle;

typedef struct s_coder
{
	int				id;
	unsigned int	compiles_done;
	long			last_compile_ms;
	t_dongle		*left;
	t_dongle		*right;
	pthread_t		thread;
	pthread_mutex_t	mutex;
}	t_coder;

typedef struct s_data
{
	unsigned int	number_of_coders;
	unsigned int	time_to_burnout;
	unsigned int	time_to_compile;
	unsigned int	time_to_debug;
	unsigned int	time_to_refactor;
	unsigned int	number_of_compiles_required;
	unsigned int	dongle_cooldown;
	t_scheduler		scheduler;
	t_coder			*coders;
	t_dongle		*dongles;
	pthread_mutex_t	log_mutex;
	pthread_mutex_t	simulation_mutex;
	bool			running;
}	t_data;

#endif // STRUCT_H
