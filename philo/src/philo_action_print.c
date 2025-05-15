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
 * lorsque cette fonction est appeler pour annoncer la mort d'un philo, le flag
 * simulation_over est mis a 1 et il n'est desormais plus possible d'afficher
 */

void	philo_action_print(t_philo *philo, time_t time, const char *action)
{
	int	id;

	if (action[0] == 'd')
	{
		id = philo->meal->order->id;
		fprintf(g_debug_file, "philo no %d est mort\n", id);
	}
	else
		id = philo->id;
	pthread_mutex_lock(&philo->mutex->mutex_print);
	if (philo->mutex->simulation_over == 0)
		printf("%ld %d %s\n", time - philo->mutex->time_start, id, action);
	if (action[0] == 'd')
		philo->mutex->simulation_over = 1;
	pthread_mutex_unlock(&philo->mutex->mutex_print);
}
