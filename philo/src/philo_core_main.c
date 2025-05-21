/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_core_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:40:10 by srenaud           #+#    #+#             */
/*   Updated: 2025/05/14 10:40:10 by srenaud          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_debug g_debug; //debug

int	main(int ac, char **av)
{
	g_debug.fd = open("debug.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (g_debug.fd == -1)
	{
		perror("open");
		return (1);
	}
	g_debug.time_start = philo_utils_get_time();
	t_data	data;

	if (!philo_inputs_are_valid(ac, av)
		|| philo_core_init_data(&data, ac, av)
		|| philo_core_init_philo(&data))
		return (philo_core_exit(&data));
	philo_core_thread_create_and_join(&data);
	philo_core_exit(&data);

	close(g_debug.fd); //debug

	return (0);
}
