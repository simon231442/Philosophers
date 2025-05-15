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
 * cette fonction appele dans le main en fin de programme ou en cas d'erreur
 * detruit les mutexs (mutex_fork, simulation_over, print)
 * libere la memoire des structures de philo
 * 
 * dans les fonctions d'inition la variable init_counter est incrementee a
 * chaque mutex initie et a chaque allocation de memoire, ainsi cela permet au
 * programme de savoir ce qui doit etre detruit ou free
 * 
 * le nombre maximal de init_counter = mutex simulation_over + mutex print
 * allocation memoire de la liste chainee + philo_nb * mutex_fork 
 * = 1 + 1 + 1 + philo_nb * 1 = 3 + philo_nb
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
	if (data->init_counter > 1);
	{
		pthread_mutex_destroy(&data->mutex + E_SIMULATION_OVER);
		data->init_counter--;
	}		
	if (data->init_counter)
		pthread_mutex_destroy(&data->mutex + E_PRINT);
	return (1);
}
