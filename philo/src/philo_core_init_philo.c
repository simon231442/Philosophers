/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_core_init_philo.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:00:26 by srenaud           #+#    #+#             */
/*   Updated: 2025/05/03 15:00:26 by srenaud          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Initialise les structures t_philo pour chaque philosophe
 *
 * Cette fonction, appelée par main, initialise la liste chainee de structures
 * t_philo dont la mémoire a été allouée précédemment dans philo_core_init_data
 * 
 * le premier philo est initie, puis le suivant est une copie du premier avec
 * certaines valeurs changees, le sur-suivant est une copie du precedent,
 * ainsi de suite jusqu'au dernier
 * 
 * la liste chainee boucle (le dernier philo pointe sur le premier)
 *
 * - Les identifiants des philosophes vont de 1 à n.
 * - les fourchettes representes par un int sont set a 1 (disponible)
 *   chaque philosophe a une fourchette
 * - meal_to_eat prend la valeur de meal_nb dans data
 * - Chaque philosophe pointe sur la structure data (t_data)
 * - Cette fonction initie les mutex_fork
 * 
 * @param data Pointeur vers la structure principale contenant les philosophes
 * @return 0 en cas de succès, 1 en cas d'échec d'initiation d'un mutex
 */

static void	init_philo_first(t_data *data);
static void	init_philo_others(t_data *data);
static int	init_mutex_philo(t_data *data);

int	philo_core_init_philo(t_data *data)
{
	init_philo_first(data);
	init_philo_others(data);
	if (init_mutex_philo(data))
		return (1);
	return (0);
}

static void	init_philo_first(t_data *data)
{
	data->philo_first->id = 1;
	data->philo_first->fork = 1;
	data->philo_first->time_last_eat = data->time_start;
	data->philo_first->meal_to_eat = data->meal_nb;
	data->philo_first->data = data;
	data->philo_first->next = data->philo_first + 1;
}

static void	init_philo_others(t_data *data)
{
	data->philo_cursor = data->philo_first;
	philo_utils_memcpy(data->philo_cursor, data->philo_first, sizeof(t_philo));
	while (data->philo_cursor->id < data->philo_nb)
	{
		philo_utils_memcpy(data->philo_cursor->next, data->philo_cursor,
			sizeof(t_philo));
		data->philo_cursor = data->philo_cursor->next;
		data->philo_cursor->id++;
		data->philo_cursor->next++;
	}
	data->philo_cursor->next = data->philo_first;
}

static int	init_mutex_philo(t_data *data)
{
	data->philo_cursor = data->philo_first;
	while (1)
	{
		if (pthread_mutex_init(&data->philo_cursor->mutex_fork, NULL))
			return (1);
		data->init_counter++;
		data->philo_cursor = data->philo_cursor->next;
		if (data->philo_cursor == data->philo_first)
			break ;
	}
	return (0);
}
