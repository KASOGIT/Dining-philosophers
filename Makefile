##
## Makefile for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_philo
## 
## Made by adam soto
## Login   <soto_a@epitech.net>
## 
## Started on  Wed Mar  2 12:54:44 2016 
## Last update Sun Oct 16 23:49:12 2016 
##

NAME	= philo

CFLAGS	= -I./include -O2 -pipe
LDFLAGS	= -L./lib/ -lriceferee -lpthread

CC	= gcc

SRC	= main.c \
	  philo_list.c \
	  parser.c \
	  random_gen.c \
	  wait_state.c \
	  algo.c \
	  threads_mngt.c \
	  state_act.c \
	  routines_act.c \

OBJ	= $(addprefix src/, $(SRC:.c=.o))

$(NAME):	$(OBJ)
		$(CC) $(OBJ) $(LDFLAGS) -o $(NAME) -O3

all:	$(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

