/*
** philo.h for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_philo
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Wed Mar  2 13:22:03 2016 
** Last update Sun Mar 13 23:17:45 2016 
*/

#ifndef PHILO_H_
#define PHILO_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "extern.h"

typedef enum	e_state
  {
    SLEEP,
    EAT,
    THINK,
    NONE
  }		t_state;

typedef struct	s_philo
{
  pthread_t		thread;
  t_state	       	state;
  pthread_mutex_t	mutex;
  int			rice;
  int			id;
  int			eat;
  int			rest;
  int			think;
  struct s_philo	*next;
  struct s_philo	*prev;
}		t_philo;

extern int	out;
extern int	g_eat;
extern int	g_think;
extern int	g_rest;

#define	WAIT_TIME	550

int	main(int ac, char **av);

/*
** list for philo
*/

t_philo	*create_philo(int id, int size_rice);
t_philo *append_philo(t_philo *head, t_philo *to_append);
t_philo	*create_list(int nb_philo, int size_rice);
void	free_list(t_philo *head);
void	print_list(t_philo *head);

/*
** others algo and parse func
*/

int	parse_philo(char **av, int *nb, int *max);
void	init_rand();
float	rand_gen(float min, float max);
void	think_wait();
void	eat_wait();
void	rest_wait();
void	wait_by_state(t_state state);
void	*algo(void *arg);
void	create_threads(t_philo *head, int nb_philo);
void	wait_end_threads(t_philo *head);
void	think_state_act(t_philo *philo);
void	none_act(t_philo *philo);
void	think_act(t_philo *philo);
void	eat_act(t_philo *philo);
void	sleep_act(t_philo *philo);
void	eat_rout(t_philo *philo);
void	think_rout(t_philo *philo);
void	rest_rout(t_philo *philo);

#endif /* !PHILO_H_ */
