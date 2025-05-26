/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_core_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:49:12 by srenaud           #+#    #+#             */
/*   Updated: 2025/05/14 16:49:12 by srenaud          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Libère les ressources allouées en fin de programme ou en cas d'erreur
 *
 * Cette fonction est appelée par le main en fin de programme ou en cas d'erreur
 * Elle détruit tous les mutex (mutex_fork, simulation_over, print) et
 * libère la mémoire allouée pour les structures de philosophes
 * 
 * Dans les fonctions d'initialisation, la variable init_counter est incrémentée
 * à chaque création de mutex et à chaque allocation de mémoire. Cela permet au
 * programme de savoir ce qui doit être détruit ou libéré
 *
 * La valeur maximale de init_counter = mutex simulation_over + mutex print +
 * allocation mémoire de la liste chaînée + (philo_nb * mutex_fork)
 * = 1 + 1 + 1 + philo_nb = 3 + philo_nb
 *
 * @param data Pointeur vers la structure principale du programme
 * @return 1 pour indiquer la fin de l'opération
 */

int	philo_core_exit(t_data *data)
{
	if (data->init_counter > 3)
	{
		while (data->init_counter > 3)
		{
			pthread_mutex_destroy(&data->philo_first->mutex_fork);
			data->init_counter--;
			data->philo_first = data->philo_first->next;
		}
	}
	if (data->init_counter > 2)
	{
		free(data->philo_first);
		data->init_counter--;
	}
	if (data->init_counter > 1)
	{
		pthread_mutex_destroy(&data->mutex[E_SIMULATION_OVER]);
		data->init_counter--;
	}
	if (data->init_counter)
		pthread_mutex_destroy(&data->mutex[E_PRINT]);
	return (1);
}
