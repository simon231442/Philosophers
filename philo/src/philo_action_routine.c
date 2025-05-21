/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action_routine.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 15:00:58 by srenaud           #+#    #+#             */
/*   Updated: 2025/05/18 15:00:58 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_action_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 != 0) // si le philo est impair
		usleep(philo->id * DELAY_MULTIPLY);
	else
	{
		usleep(philo->data->time_to_eat / 2 * 1000);
		usleep((philo->data->philo_nb - philo->id) * DELAY_MULTIPLY);
	}
	while (philo->meal_to_eat != 0)
	{
		if (philo_action_take_a_fork(philo, &philo->fork, &philo->mutex_fork)
	|| philo_action_take_a_fork(philo, &philo->next->fork, &philo->next->mutex_fork)
	|| philo_action_eat(philo))
		return (NULL);
		philo_action_leave_forks(philo);
		philo_action_think(philo);
		if (philo_action_sleep(philo))
		return (NULL);
	}
	return (NULL);
}