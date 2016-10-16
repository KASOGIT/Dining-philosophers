/*
** algo.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_philo
** 
** Made by soto_a
** Login   <@epitech.net>
** 
** Started on  Sun Mar  6 22:47:06 2016 
** Last update Sun Mar 13 23:35:06 2016 
*/

#include "philo.h"

int	out = 0;

void		*algo(void *arg)
{
  t_philo	*philo;

  philo = (t_philo *)arg;
  while (1)
    {
      if (philo->rice <= 0)
	out = 1;
      if (out)
	pthread_exit(0);
      if (philo->state == NONE)
	none_act(philo);
      else if (philo->state == THINK)
	think_act(philo);
      else if (philo->state == EAT)
	eat_act(philo);
      else if (philo->state == SLEEP)
	sleep_act(philo);
    }
  return (0);
}
