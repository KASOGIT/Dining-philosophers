/*
** random_gen.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_philo
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Sun Mar  6 22:25:44 2016 
** Last update Sun Mar 13 23:36:40 2016 
*/

#include "philo.h"

void	init_rand()
{
  srand((unsigned int)time(NULL));
}

float	rand_gen(float min, float max)
{
  float	random;
  float	range;

  random = ((float)rand()) / (float)RAND_MAX;
  range = max - min;
  return ((random * range) + min);
}

void	think_wait()
{
}

void	eat_wait()
{
}

void	rest_wait()
{
}
