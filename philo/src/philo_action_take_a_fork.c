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

/**
 * @brief Prend une fourchette de façon thread-safe.
 *
 * fonction appeler par philo_action_routine
 * Les fourchettes sont représentées par un indicateur int
 * (1 = libre, 0 = occupée), protégé par un mutex pour assurer
 * l'exclusion mutuelle (empêche l'accès concurrent à la même fourchette).
 *
 * La fonction :
 *   - Verrouille le mutex associé à la fourchette.
 *   - Si la fourchette est libre, la marque comme prise (0),
 *     affiche l'action et retourne 0.
 *   - Sinon, relâche le mutex puis attend brièvement avant de réessayer.
 *
 * La boucle s'exécute tant que la simulation est active
 *   ou jusqu'à ce que la fourchette soit prise.
 *
 * @param philo        Pointeur vers le philo courant (état et affichage).
 * @param fork         Pointeur vers l'indicateur de dispo. de la fourchette.
 * @param mutex_fork   Mutex protégeant l'accès à la fourchette.
 * @return             - 0 si la fourchette est prise, 
 * 					   - 1 si la simulation est terminée.
 */

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
