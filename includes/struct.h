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

typedef enum e_scheduler
{
	FIFO,
	EDF,
}	t_scheduler;

typedef struct s_request
{
	unsigned int	coder_id;
	long			deadline;
	unsigned long	arrival_order;
}	t_request;

typedef struct s_node
{
	t_request		req;
	struct s_node	*next;
}	t_node;

typedef struct s_queue
{
	t_node	*head;
	int		size;
	int		(*cmp)(t_request, t_request);
}	t_queue;

typedef struct s_dongle
{
	pthread_mutex_t	mutex;
	int				available;
	long			last_release_ms;
	t_queue			wait_queue;
	pthread_cond_t	cond;
}	t_dongle;

typedef struct s_coder
{
	unsigned int	id;
	unsigned int	compiles_done;
	long			last_compile_ms;
	t_dongle		*left;
	t_dongle		*right;
	int				left_idx;
	int				right_idx;
	pthread_t		thread;
	pthread_mutex_t	mutex;
	struct s_data	*data;
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
	unsigned long	start_time;
	unsigned long	request_counter;
	pthread_mutex_t	counter_mutex;
	pthread_t		monitor_thread;
}	t_data;

#endif // STRUCT_H
