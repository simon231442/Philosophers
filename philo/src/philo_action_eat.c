/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action_eat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:48:31 by srenaud           #+#    #+#             */
/*   Updated: 2025/05/18 18:48:31 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int philo_action_eat(t_philo *philo)
{
    time_t  time_end;
    
    philo->time_last_eat = philo_utils_get_time();
    philo->meal_to_eat--;
    time_end = philo->time_last_eat + philo->data->time_to_eat;
    philo_action_print(philo, E_EATING);
    while (philo_utils_get_time() < time_end)
    {
        if (!philo_action_is_simulation_running(philo))
            return (1);
        usleep(DELAY_LOOP);
    }
    return (0);
}