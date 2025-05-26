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

/**
 * @brief Routine principale de chaque philosophe.
 * 
 * fonction qui est executee a la creation de chaque thread. 
 * 
 * Un temps d'attente dependant de l'ID du philosophe est defini pour fluidifier
 * l'echange des fourchettes :
 * - les philosophes impairs seront les premiers a prendre les fourchettes
 *   (il y a aussi un temps d'attente entre chaque philosophe)
 * - les philosophes pairs attendront la moitie du temps de repas avant
 *   d'entreprendre de prendre une fourchette.
 * les philosophes pairs sont sequencer par ordre croissant de leur ID tandis
 * que les philosophes impairs sont sequencer par ordre decroissant de leur ID
 * 
 */

void	*philo_action_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 != 0)
		usleep(philo->id * DELAY_MULTIPLY);
	else
	{
		usleep(philo->data->time_to_eat / 2 * 1000);
		usleep((philo->data->philo_nb - philo->id) * DELAY_MULTIPLY);
	}
	while (philo->meal_to_eat != 0)
	{
		if (philo_action_take_a_fork(philo, &philo->fork, &philo->mutex_fork)
			|| philo_action_take_a_fork(philo, &philo->next->fork,
				&philo->next->mutex_fork)
			|| philo_action_eat(philo))
			return (NULL);
		philo_action_leave_forks(philo);
		philo_action_think(philo);
		if (philo_action_sleep(philo))
			return (NULL);
	}
	return (NULL);
}
