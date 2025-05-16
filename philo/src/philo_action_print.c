/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:34:36 by srenaud           #+#    #+#             */
/*   Updated: 2025/05/08 13:12:34 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * fct qui permet a un philo d'afficher sans conflit avec d'autres
 * 
 *
 */

void	philo_action_print(t_philo *philo, int buffer_name)
{
	pthread_mutex_lock(&philo->data->mutex[E_PRINT]);
	philo_utils_ritoa(philo->time_action,
						philo->data->action_print[buffer_name].time_stamp);
	philo_utils_ritoa(philo->id, philo->data->action_print[buffer_name].id);
	write(1, &philo->data->action_print[buffer_name].time_stamp, BUFF_SIZE);
	write(1, "\n", 1);
	philo_utils_memset(&philo->data->action_print[buffer_name].time_stamp,
						32, PRECISION_TIME + PRECISION_ID);
	pthread_mutex_unlock(&philo->data->mutex[E_PRINT]);
}
