/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_get_time.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:41:53 by srenaud           #+#    #+#             */
/*   Updated: 2025/04/23 18:41:53 by srenaud          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @return fct qui renvoi l'horodatage en millisecondes (l'heure)
 */

time_t	philo_utils_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
