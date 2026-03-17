#include "codexion.h"

t_status coder_routine(unsigned int coder_id, t_data *data)
{
	t_coder *coder = &data->coders[coder_id];

	while (coder->compiles_done < data->number_of_compiles_required)
	{
		// Lock left/right mutex depending on scheduler
		// if dongle isnt free wait

		pthread_mutex_lock(&coder->mutex);
		coder->last_compile_ms = get_time_ms();
		pthread_mutex_unlock(&coder->mutex);

		log_action(coder->last_compile_ms, coder_id, "is compiling");
		usleep(data->time_to_compile * 1000);

		// release dongles and set their cooldowns
		coder->compiles_done++;

		log_action(get_time_ms(), coder_id, "is debugging");
		usleep(data->time_to_debug * 1000);

		log_action(get_time_ms(), coder_id, "is refactoring");
		usleep(data->time_to_refactor * 1000);

		pthread_mutex_lock(&data->simulation_mutex);
		if (!data->running)
		{
			pthread_mutex_unlock(&data->simulation_mutex);
			break;
		}
		pthread_mutex_unlock(&data->simulation_mutex);
	}

	if (coder->compiles_done < data->number_of_compiles_required)
		return (FAIL);
	return (SUCCESS);
}
