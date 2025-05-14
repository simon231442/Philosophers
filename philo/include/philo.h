/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:38:54 by srenaud           #+#    #+#             */
/*   Updated: 2025/05/13 16:38:54 by srenaud          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>

# define TAKING "has taken a fork"
# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define DYING "died"

typedef enum e_mutex_name
{
	E_PRINT,
	E_SIMULATION_OVER,
}					t_mutex_name;

typedef enum e_buffer_name
{
	E_TAKING,
	E_EATING,
	E_THINKING,
	E_DYING,
}					t_buffer_name;

struct				s_philo;
struct 				s_print;

typedef struct s_data
{
	int				philo_nb;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				meal_nb;
	pthread_mutex_t	mutex[2];
	t_print			action_print[4];
	t_philo			*philo_first;
	t_philo			*philo_cursor;
	int				init_counter;
}					t_data;

typedef struct s_philo
{
	int				id;
	int				fork;
	pthread_mutex_t	mutex_fork;
	time_t			time_last_eat;
	time_t			time_end_action;
	int				meal_to_eat;
	pthread_t		thread;
	t_philo			*next;
}					t_philo;

typedef struct s_print
{
	char			buffer[80];
	char			*time_stamp;
	char			*id;
	char			*action;
}					t_print;

//initing
int					philo_inputs_are_valid(int ac, char **av);

#endif
