/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_core_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:40:10 by srenaud           #+#    #+#             */
/*   Updated: 2025/05/14 10:40:10 by srenaud          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (!philo_inputs_are_valid(ac, av))
		return (1);
	if (philo_core_init_data(&data, ac, av)
		|| philo_core_init_philo(&data))
		return (philo_core_exit(&data));
	philo_core_init_print(&data);
	philo_core_thread_create_and_join(&data);
	philo_core_exit(&data);
	return (0);
}
