/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_core_thread_create_and_join.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 17:10:29 by srenaud           #+#    #+#             */
/*   Updated: 2025/05/18 17:10:29 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Crée et joint les threads des philosophes.
 *
 * le main appel cette fonction pour créer les threads, puis les joindre
 * un thread par philosophe est cree en appelant, la fct philo_action_routine
 * 
 * A chaque fois qu'un thread est cree, init_counter est incremente ainsi en cas
 * d'erreur de creation de thread, le nombre exact de threads est joint.
 * 
 * le thread est joint lorsque philo_routine est termine, c'est a dire lorsque
 * cette derniere fonction retourne NULL.
 *
 * @param data Pointeur vers la structure de données principale.
 */

void	philo_core_thread_create_and_join(t_data *data)
{
	data->philo_cursor = data->philo_first;
	while (1)
	{
		if (pthread_create(&data->philo_cursor->thread, NULL,
				philo_action_routine, data->philo_cursor))
			break ;
		data->init_counter++;
		data->philo_cursor = data->philo_cursor->next;
		if (data->philo_cursor == data->philo_first)
			break ;
	}
	data->philo_cursor = data->philo_first;
	while (data->init_counter > 3 + data->philo_nb)
	{
		pthread_join(data->philo_cursor->thread, NULL);
		data->init_counter--;
		data->philo_cursor = data->philo_cursor->next;
	}
}
