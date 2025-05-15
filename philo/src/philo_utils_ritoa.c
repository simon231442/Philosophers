/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_ritoa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 22:06:42 by srenaud           #+#    #+#             */
/*   Updated: 2025/05/14 22:06:42 by srenaud          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_utils_ritoa(time_t n, char *dest)
{
	if (n >= 10)
		philo_utils_ritoa(n / 10, dest);
	*dest = time + '0';
	return (dest + 1);
}
