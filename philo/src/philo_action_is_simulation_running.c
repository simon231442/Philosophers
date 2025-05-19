/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action_is_simulation_running.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:09:35 by srenaud           #+#    #+#             */
/*   Updated: 2025/05/19 12:09:35 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_action_is_simulation_running(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex[E_SIMULATION_OVER]);
	if (philo->data->simulation_over)
	{
		pthread_mutex_unlock(&philo->data->mutex[E_SIMULATION_OVER]);
		return (0);
	}
	if (philo_utils_get_time() - philo->time_last_eat
		> philo->data->time_to_die )
	{
		philo->data->simulation_over = 1;
		philo_action_print(philo, E_DYING);
		pthread_mutex_unlock(&philo->data->mutex[E_SIMULATION_OVER]);
		return (0);
	}
	pthread_mutex_unlock(&philo->data->mutex[E_SIMULATION_OVER]);
	return (1);
}