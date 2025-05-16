/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_core_init_print.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:36:53 by srenaud           #+#    #+#             */
/*   Updated: 2025/05/14 17:36:53 by srenaud          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Initialise la structure print qui contient les offsets des information a afficher
 *
 * Cette fonction, appelée par main,
 */
void	philo_core_init_print(t_data *data)
{
	int			i;
	static char	*action_type[] = {TAKING, EATING, SLEEPING, THINKING, DYING};
	static int	action_size[] = {TAKING_SIZE, EATING_SIZE, SLEEPING_SIZE,
								THINKING_SIZE, DYING_SIZE};

	i = 0;
	while (i <= E_DYING)
	{
		philo_utils_memset(data->action_print[i].time_stamp, 32, BUFF_SIZE);
		data->action_print[i].id = 
			data->action_print[i].time_stamp + PRECISION_TIME;
		data->action_print[i].action = data->action_print[i].id + PRECISION_ID;
		philo_utils_memcpy(data->action_print[i].action, action_type[i],
		action_size[i]);
		i++;
	}
}
