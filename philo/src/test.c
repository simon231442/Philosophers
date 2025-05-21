#include "philo.h"

int	main(void)
{
	time_t time;
	time_t time_end;

	time = philo_utils_get_time();
	time_end = time + DELAY_START;
	while (time < time_end)
	{
		printf("time = %ld\n", time);
		usleep(DELAY_LOOP);
		time = philo_utils_get_time();
	}
	printf("finished\n");
	return (0);
}