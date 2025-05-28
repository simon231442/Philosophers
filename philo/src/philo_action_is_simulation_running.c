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

/**
 * @brief Vérifie si la simulation est active.
 *
 * Cette fonction :
 *   - Verrouille le mutex E_SIMULATION_OVER pour synchroniser l'accès
 *   - Si la simulation est déjà terminée (simulation_over == 1),
 *     déverrouille et retourne 0
 *   - Sinon, calcule le temps écoulé depuis le dernier repas (du philosophe) :
 *     Si ce délai dépasse time_to_die, déclenche la fin de simulation
 *     (simulation_over passe de 0 à 1) et affiche E_DYING
 *   - Déverrouille le mutex avant de retourner
 *
 * @param philo  Pointeur vers le philosophe courant.
 * @return       1 si la simulation continue, 0 si elle est terminée
 */

int	philo_action_is_simulation_running(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex[E_SIMULATION_OVER]);
	if (philo->data->simulation_over)
	{
		pthread_mutex_unlock(&philo->data->mutex[E_SIMULATION_OVER]);
		return (0);
	}
	if (philo_utils_get_time() - philo->time_last_eat
		> philo->data->time_to_die)
	{
		philo->data->simulation_over = 1;
		philo_action_print(philo, E_DYING);
		pthread_mutex_unlock(&philo->data->mutex[E_SIMULATION_OVER]);
		return (0);
	}
	pthread_mutex_unlock(&philo->data->mutex[E_SIMULATION_OVER]);
	return (1);
}
