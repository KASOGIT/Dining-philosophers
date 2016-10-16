/*
** parser.c for philo in /home/julien_k/PSU_2015_philo/src
** 
** Made by Kévin Julien
** Login   <julien_k@epitech.net>
** 
** Started on  Sun Mar  6 17:23:50 2016 Kévin Julien
** Last update Mon Mar  7 18:22:53 2016 Kévin Julien
*/

#include "philo.h"

int	check_if_number(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] < '0' || str[i] > '9')
        return (-1);
      i++;
    }
  return (0);
}

int	stack_var(int *a, int *b, char *str1, char *str2)
{
  if (check_if_number(str1) == -1)
    return (-1);
  (*a) = atoi(str1);
  if (check_if_number(str2) == -1)
    return (-1);
  (*b) = atoi(str2);
  return (0);
}

int	parse_philo(char **av, int *nb, int *max)
{
  if (((strcmp(av[1], "-p") == 0)
       && (strcmp(av[3], "-e") == 0))
      || (strcmp(av[1], "-e") == 0 && strcmp(av[3], "-p") == 0))
    {
      if (strcmp(av[1], "-p") == 0)
	{
	  if (stack_var(nb, max, av[2], av[4]) == -1)
	    return (-1);
	}
      else if (strcmp(av[1], "-e") == 0)
        {
          if (stack_var(max, nb, av[2], av[4]) == -1)
            return (-1);
	}
      if ((*nb) < 2)
        return (-1);
      return (0);
    }
  return (-1);
}
