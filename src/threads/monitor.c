#include "codexion.h"

void monitor(t_data data)
{
    unsigned int i;
    unsigned long now;

    while (1)
    {
    	pthread_mutex_lock(&data.simulation_mutex);
    	if (data.running)
    	{
        	pthread_mutex_unlock(&data.simulation_mutex);
        	break;
    	}
    	pthread_mutex_unlock(&data.simulation_mutex);
    	i = 0;
        while (i < data.number_of_coders)
        {
            pthread_mutex_lock(&data.coders[i].mutex);
            now = get_time_ms();
            if (now - data.coders[i].last_compile_ms > data.time_to_burnout)
            {
                pthread_mutex_lock(&data.log_mutex);
                log_action(now, data.coders[i].id, "burned out");
                pthread_mutex_unlock(&data.log_mutex);
                pthread_mutex_lock(&data.simulation_mutex);
                data.running = false;
                pthread_mutex_unlock(&data.simulation_mutex);
                pthread_mutex_unlock(&data.coders[i].mutex);
                return ;
            }
            pthread_mutex_unlock(&data.coders[i].mutex);
        }
        usleep(1000);
    }
}