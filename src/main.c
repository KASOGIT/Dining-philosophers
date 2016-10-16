/*
** main.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_philo/src
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Wed Mar  2 13:17:29 2016 
** Last update Sun Mar 13 23:36:29 2016 
*/

#include "philo.h"

void	usage()
{
  printf("./philo -p <number philo> -e <max eat for a philo>\n");
  exit(EXIT_FAILURE);
}

int		main(int ac, char **av)
{
  t_philo	*head;
  int		nb_philo;
  int		max_eat;

  RCFStartup(ac, av);
  head = NULL;
  if (ac == 5)
    {
      if (parse_philo(av, &nb_philo, &max_eat) == -1)
	usage();
      init_rand();
      head = create_list(nb_philo, max_eat);
      create_threads(head, nb_philo);
      wait_end_threads(head);
    }
  else
    usage();
  free_list(head);
  RCFCleanup();
  return (EXIT_SUCCESS);
}
