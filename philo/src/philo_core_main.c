/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_core_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:40:10 by srenaud           #+#    #+#             */
/*   Updated: 2025/05/14 10:40:10 by srenaud          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Point d'entrée de la simulation
 *
 * Cette fonction gère les initialisations et lance la simulation :
 *   - Vérifie la validité des arguments
 *   - Initialise les données globales et les philosophes
 *   - Prépare les buffers d'affichage
 *   - Lance les threads des philosophes et attend leur fin
 *   - Détruit les mutex et libère les ressources
 *
 * @param ac  Nombre d'arguments (doit être 5 ou 6)
 * @param av  Tableau des arguments :
 *            [1] philo_nb,
 *            [2] time_to_die,
 *            [3] time_to_eat,
 *            [4] time_to_sleep,
 *            [5] [optionnel] number_of_meals
 * @return    0 si succès, 1 en cas d'erreur d'arguments ou d'initialisation
 */

int	main(int ac, char **av)
{
	t_data	data;

	if (!philo_inputs_are_valid(ac, av))
		return (1);
	if (philo_core_init_data(&data, ac, av)
		|| philo_core_init_philo(&data))
		return (philo_core_exit(&data));
	philo_core_init_print(data.action_print);
	philo_core_thread_create_and_join(&data);
	philo_core_exit(&data);
	return (0);
}
