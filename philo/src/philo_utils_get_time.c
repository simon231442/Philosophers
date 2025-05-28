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
 * @brief Retourne l'heure actuelle en millisecondes.
 *
 * Utilise gettimeofday() pour récupérer le temps système,
 * puis convertit les secondes et microsecondes en millisecondes.
 *
 * @return time_t Horodatage en millisecondes depuis l'époque UNIX.
 */

time_t	philo_utils_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
