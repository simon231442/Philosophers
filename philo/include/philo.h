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
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>

# define INT_MAX 2147483647
// time is in microseconds
# define DELAY_LOOP 1000
# define DELAY_MULTIPLY 200

# define TAKING "has taken a fork"
# define TAKING_SIZE 16
# define EATING "is eating"
# define EATING_SIZE 9
# define SLEEPING "is sleeping"
# define SLEEPING_SIZE 11
# define THINKING "is thinking"
# define THINKING_SIZE 11
# define DYING "died"
# define DYING_SIZE 4
# define BUFF_SIZE 80
# define PRECISION_TIME 9
# define PRECISION_ID 6

typedef enum e_mutex_name
{
	E_PRINT,
	E_SIMULATION_OVER,
}					t_mutex_name;

typedef enum e_buffer_name
{
	E_TAKING,
	E_EATING,
	E_SLEEPING,
	E_THINKING,
	E_DYING,
}					t_buffer_name;

typedef struct s_philo	t_philo;

typedef struct s_print
{
	char			time_stamp[BUFF_SIZE];
	char			*id;
	char			*action;
}					t_print;

typedef struct s_data
{
	int				philo_nb;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				meal_nb;
	time_t			time_start;
	int				simulation_over;
	pthread_mutex_t	mutex[2];
	t_print			action_print[5];
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
	time_t			time_action;
	int				meal_to_eat;
	pthread_t		thread;
	t_data			*data;
	t_philo			*next;
}					t_philo;

//initing
int					philo_inputs_are_valid(int ac, char **av);
int					philo_core_init_data(t_data *data, int ac, char **av);
int					philo_core_init_philo(t_data *data);
void				philo_core_init_print(t_data *data);
void				philo_core_thread_create_and_join(t_data *data);

//action
void				philo_action_print(t_philo *philo, int buffer_name);
int					philo_action_is_simulation_running(t_philo *philo);
void				*philo_action_routine(void *arg);
int					philo_action_take_a_fork(t_philo *philo, int *fork,
						pthread_mutex_t *mutex_fork);
void				philo_action_leave_forks(t_philo *philo);
int					philo_action_eat(t_philo *philo);
void				philo_action_think(t_philo *philo);
int					philo_action_sleep(t_philo *philo);

//utils
long				philo_utils_atol(char *str);
void				*philo_utils_calloc(size_t nmemb, size_t size);
int					philo_utils_is_digit(char c);
time_t				philo_utils_get_time(void);
void				philo_utils_memcpy(void *dest, void *src, int size);
void				philo_utils_memset(void *dest, char c, int size);
char				*philo_utils_ritoa(time_t n, char *dest);

//exit
int					philo_core_exit(t_data *data);

#endif
