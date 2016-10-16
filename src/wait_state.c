/*
** wait_state.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_philo
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Sun Mar  6 22:43:27 2016 
** Last update Sun Mar 13 23:37:28 2016 
*/

#include "philo.h"

void	wait_by_state(t_state state)
{
  if (state == THINK)
    think_wait();
  else if (state == EAT)
    eat_wait();
  else if (state == SLEEP)
    rest_wait();
}
