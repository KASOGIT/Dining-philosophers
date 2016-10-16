/*
** threads_mngt.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_philo/src
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Mon Mar  7 00:11:04 2016 
** Last update Sun Mar 13 23:37:15 2016 
*/

#include "philo.h"

void		create_threads(t_philo *head, int nb_philo)
{
  t_philo	*tmp;

  tmp = head;
  while (nb_philo--)
    {
      pthread_create(&tmp->thread, NULL, &algo, tmp);
      tmp = tmp->next;
    }
}

void		wait_end_threads(t_philo *head)
{
  t_philo	*tmp;
  int		check;

  check = 1;
  tmp = head;
  while (check || tmp != head)
    {
      check = 0;
      pthread_join(tmp->thread, NULL);
      tmp = tmp->next;
    }
}
