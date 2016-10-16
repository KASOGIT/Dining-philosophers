/*
** philo_list.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_philo
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Sun Mar  6 12:21:50 2016 
** Last update Sun Mar 13 23:36:09 2016 
*/

#include "philo.h"

t_philo		*create_philo(int id, int size_rice)
{
  t_philo	*new;

  if ((new = malloc(sizeof(t_philo))) == NULL)
    abort();
  new->state = NONE;
  pthread_mutex_init(&new->mutex, NULL);
  new->rice = size_rice;
  new->id = id;
  new->eat = 0;
  new->think = 0;
  new->rest = 0;
  new->next = NULL;
  new->prev = NULL;
  return (new);
}

t_philo	*append_philo(t_philo *head, t_philo *to_append)
{
  if (head == NULL)
    {
      to_append->next = to_append;
      to_append->prev = to_append;
      return (to_append);
    }
  to_append->next = head;
  to_append->prev = head->prev;
  head->prev->next = to_append;
  head->prev = to_append;
  return (head);
}

t_philo		*create_list(int nb_philo, int size_rice)
{
  t_philo	*head;
  t_philo	*new;
  int		id;

  head = NULL;
  id = 0;
  while (nb_philo--)
    {
      new = create_philo(id, size_rice);
      head = append_philo(head, new);
      id++;
    }
  return (head);
}

void		free_list(t_philo *head)
{
  t_philo	*to_del;
  t_philo	*tmp;
  int		check;

  check = 1;
  tmp = head;
  while (check || tmp != head)
    {
      check = 0;
      to_del = tmp;
      tmp = tmp->next;
      free(to_del);
    }
}

void		print_list(t_philo *head)
{
  t_philo	*tmp;
  int		check;

  tmp = head;
  check = 1;
  while (check || tmp != head)
    {
      check = 0;
      printf("Id philo -> %d\n", tmp->id);
      tmp = tmp->prev;
    }
}
