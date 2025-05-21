/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_core_thread_create_and_join.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 17:10:29 by srenaud           #+#    #+#             */
/*   Updated: 2025/05/18 17:10:29 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_core_thread_create_and_join(t_data *data)
{
	data->philo_cursor = data->philo_first;
	while (1)
	{
		if (pthread_create(&data->philo_cursor->thread, NULL,
			philo_action_routine, data->philo_cursor))
			break;
		data->init_counter++;
		data->philo_cursor = data->philo_cursor->next;
		if (data->philo_cursor == data->philo_first)
			break;
	}
//	printf("init_counter = %d\n", data->init_counter);
/*	pthread_mutex_lock(&data->mutex[E_SIMULATION_OVER]);
	data->simulation_over = 1;
	pthread_mutex_unlock(&data->mutex[E_SIMULATION_OVER]);
	data->philo_cursor = data->philo_first;*/
	while (data->init_counter > 3 + data->philo_nb)
	{
		pthread_join(data->philo_cursor->thread, NULL);
		data->init_counter--;
		data->philo_cursor = data->philo_cursor->next;
	}
}