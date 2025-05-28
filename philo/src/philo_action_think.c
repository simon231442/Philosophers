/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action_think.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:48:53 by srenaud           #+#    #+#             */
/*   Updated: 2025/05/18 18:48:53 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Signale un philosophe en phase de réflexion.
 *
 * Fonction appelée par philo_action_routine pour afficher
 * l'état de réflexion du philosophe via philo_action_print(E_THINKING).
 *
 * @param philo  Pointeur vers la structure t_philo du philosophe courant.
 */

void	philo_action_think(t_philo *philo)
{
	philo_action_print(philo, E_THINKING);
}
