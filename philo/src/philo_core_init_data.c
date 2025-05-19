/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_core_init_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:43:00 by srenaud           #+#    #+#             */
/*   Updated: 2025/05/14 10:43:00 by srenaud          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Initialise la structure data avec les arguments et alloue la mémoire
 *
 * Cette fonction, appelée par main, récupère les arguments av
 * (préalablement validés) et les place dans la structure data.
 * 
 * Un memset initialise la structure à zéro
 * si ac == 6, meal_nb prendra la valeur de av[5]
 * si ac < 6, meal_nb sera à -1 (aucune contrainte sur le nombre de repas).
 * 
 * C'est ici que la mémoire de la liste chaînée de philosophes (t_philo) est
 * allouée et mise à 0 avec calloc.
 * 
 * init_counter est incrémenté à chaque allocation mémoire et initialisation
 * de mutex (utile pour l'opération de nettoyage dans philo_core_exit).
 *
 * Détail des arguments :
 *   av[1] = number_of_philosophers
 *   av[2] = time_to_die (en millisecondes) : délai maximal sans manger
 *   av[3] = time_to_eat (en ms) : durée d'un repas
 *   av[4] = time_to_sleep (en ms) : durée du sommeil
 *   av[5] = number_of_times_each_philosopher_must_eat (argument optionnel)
 *
* @param data Pointeur vers la structure à initialiser
 * @param ac Nombre total d'arguments
 * @param av Tableau des arguments
  * @return 0 en cas de succès, 1 en cas d'échec d'allocation mémoire
 */

int	philo_core_init_data(t_data *data, int ac, char **av)
{
	philo_utils_memset(data, 0, sizeof(t_data));
	data->philo_nb = philo_utils_atol(av[1]);
	data->time_to_die = philo_utils_atol(av[2]);
	data->time_to_eat = philo_utils_atol(av[3]);
	data->time_to_sleep = philo_utils_atol(av[4]);
	data->time_start = philo_utils_get_time() + DELAY_START;
	if (ac == 6)
		data->meal_nb = philo_utils_atol(av[5]);
	else
		data->meal_nb = -1;
	if (pthread_mutex_init(&data->mutex[E_PRINT], NULL))
		return (1);
	data->init_counter++;
	if (pthread_mutex_init(&data->mutex[E_SIMULATION_OVER], NULL))
		return (1);
	data->init_counter++;
	data->philo_first = philo_utils_calloc(sizeof(t_philo), data->philo_nb);
	if (!data->philo_first)
		return (1);
	data->init_counter++;
	return (0);
}
