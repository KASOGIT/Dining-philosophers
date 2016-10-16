/*
** state_act.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_philo
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Wed Mar  9 16:21:10 2016 
** Last update Sun Mar 13 23:37:01 2016 
*/

#include "philo.h"

int	g_think = -1;
int	g_eat = -1;
int	g_rest = -1;

void	none_act(t_philo *philo)
{
  if (pthread_mutex_trylock(&(philo->mutex)) == 0)
    {
      lphilo_take_chopstick(&(philo->mutex));
       if (pthread_mutex_trylock(&(philo->next->mutex)) == 0)
	{
	  lphilo_take_chopstick(&(philo->next->mutex));
	  eat_rout(philo);
	  lphilo_release_chopstick(&(philo->next->mutex));
	  pthread_mutex_unlock(&(philo->next->mutex));
	}
      else
	think_rout(philo);
      lphilo_release_chopstick(&(philo->mutex));
      pthread_mutex_unlock(&(philo->mutex));
    }
  else
    rest_rout(philo);
}

void	think_act(t_philo *philo)
{
  if (pthread_mutex_trylock(&(philo->next->mutex)) == 0)
    {
      lphilo_take_chopstick(&(philo->next->mutex));
      if (pthread_mutex_trylock(&(philo->mutex)) == 0)
	{
	  lphilo_take_chopstick(&(philo->mutex));
	  eat_rout(philo);
	  lphilo_release_chopstick(&(philo->mutex));
	  pthread_mutex_unlock(&(philo->mutex));
	}
      lphilo_release_chopstick(&(philo->next->mutex));
      pthread_mutex_unlock(&(philo->next->mutex));
    }
  if (philo->eat == g_eat)
    usleep(WAIT_TIME);
}

void	eat_act(t_philo *philo)
{
  if (philo->think < philo->rest)
    {
      if (pthread_mutex_trylock(&(philo->mutex)) == 0)
	{
	  lphilo_take_chopstick(&(philo->mutex));
	  think_rout(philo);
	  lphilo_release_chopstick(&(philo->mutex));
	  pthread_mutex_unlock(&(philo->mutex));
	}
      else
	rest_rout(philo);
    }
  else
    rest_rout(philo);
  if (philo->think == g_think || philo->rest == g_rest)
    usleep(WAIT_TIME);
}

void	sleep_act(t_philo *philo)
{
  pthread_mutex_lock(&(philo->mutex));
  lphilo_take_chopstick(&(philo->mutex));
  if (philo->eat < philo->think)
    {
      if (pthread_mutex_trylock(&(philo->next->mutex)) == 0)
	{
	  lphilo_take_chopstick(&(philo->next->mutex));
	  eat_rout(philo);
	  lphilo_release_chopstick(&(philo->next->mutex));
	  pthread_mutex_unlock(&(philo->next->mutex));
	}
      else
	think_rout(philo);
    }
  else
    think_rout(philo);
  lphilo_release_chopstick(&(philo->mutex));
  pthread_mutex_unlock(&(philo->mutex));
  if (philo->think == g_think || philo->eat == g_eat)
    usleep(WAIT_TIME);
}
