/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action_take_a_fork.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:48:17 by srenaud           #+#    #+#             */
/*   Updated: 2025/05/18 18:48:17 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_action_take_a_fork(t_philo *philo, int *fork,
							pthread_mutex_t *mutex_fork)
{
	while (philo_action_is_simulation_running(philo))
	{
		pthread_mutex_lock(mutex_fork);
		if (*fork == 1)
		{
			*fork = 0;
			pthread_mutex_unlock(mutex_fork);
			philo_action_print(philo, E_TAKING);
			return (0);
		}
		pthread_mutex_unlock(mutex_fork);
		usleep(DELAY_LOOP);
	}
	return (1);
}
