/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action_leave_forks.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:42:34 by srenaud           #+#    #+#             */
/*   Updated: 2025/05/19 13:42:34 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_action_leave_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex_fork);
	philo->fork = 1;
	pthread_mutex_unlock(&philo->mutex_fork);
	pthread_mutex_lock(&philo->next->mutex_fork);
	philo->next->fork = 1;
	pthread_mutex_unlock(&philo->next->mutex_fork);
}
