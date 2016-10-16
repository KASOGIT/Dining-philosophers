/*
** routines_act.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_philo
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Sun Mar 13 15:07:20 2016 
** Last update Sun Mar 13 23:36:49 2016 
*/

#include "philo.h"

void	eat_rout(t_philo *philo)
{
  philo->rice--;
  philo->eat++;
  if (philo->eat > g_eat)
    g_eat = philo->eat;
  if (philo->rice <= 0)
    out = 1;
  lphilo_eat();
  wait_by_state((philo->state = EAT));
}

void	think_rout(t_philo *philo)
{
  philo->think++;
  if (philo->think > g_think)
    g_think = philo->think;
  lphilo_think();
  wait_by_state((philo->state = THINK));
}

void	rest_rout(t_philo *philo)
{
  philo->rest++;
  if (philo->rest > g_rest)
    g_rest = philo->rest;
  lphilo_sleep();
  philo->state = SLEEP;
}
