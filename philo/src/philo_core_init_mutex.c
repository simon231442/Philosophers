/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_core_init_mutex.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:19:43 by srenaud           #+#    #+#             */
/*   Updated: 2025/04/27 15:36:22 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Initialise tous les mutex nécessaires.
 *
 * Cette fonction, appelée par main, initialise :
 * - Un tableau de mutex pour les fourchettes (mutex_fork)
 * - Un mutex pour la protection des affichages (mutex_print)
 * - Un mutex pour la protection du tableau de logs des repas (mutex_meal)
 *
 * Un memset est utilisé pour initialiser la structure à zéro.
 *
 * @param mutex Structure contenant tous les mutex à initialiser
 * @param data Structure permettant d'accéder au nombre de philosophes
 * @return 0 en cas de succès, 1 en cas d'échec (erreur malloc ou init_mutex)
 */

int	philo_core_init_mutex(t_mutex *mutex, int philo_nb)
{
	int	i;

	memset(mutex, 0, sizeof(t_mutex));
	i = 0;
	mutex->mutex_fork = philo_utils_calloc(sizeof(pthread_mutex_t), philo_nb);
	if (!mutex->mutex_fork)
		return (1);
	mutex->mutex_fork_inited = philo_utils_calloc(sizeof(int), philo_nb);
	if (!mutex->mutex_fork_inited)
		return (1);
	while (i < philo_nb)
	{
		if (pthread_mutex_init(&mutex->mutex_fork[i], NULL))
			return (1);
		mutex->mutex_fork_inited[i] = 1;
		i++;
	}
	if (pthread_mutex_init(&mutex->mutex_meal, NULL))
		return (1);
	mutex->mutex_meal_inited = 1;
	if (pthread_mutex_init(&mutex->mutex_print, NULL))
		return (1);
	mutex->mutex_print_inited = 1;
	return (0);
}
