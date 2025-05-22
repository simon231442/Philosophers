/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action_sleep.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:49:04 by srenaud           #+#    #+#             */
/*   Updated: 2025/05/18 18:49:04 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_action_sleep(t_philo *philo)
{
	time_t	time_end;

	time_end = philo_utils_get_time() + philo->data->time_to_sleep;
	philo_action_print(philo, E_SLEEPING);
	while (philo_utils_get_time() < time_end)
	{
		if (!philo_action_is_simulation_running(philo))
			return (1);
		usleep(DELAY_LOOP);
	}
	return (0);
}
