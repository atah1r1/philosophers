# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 11:42:25 by atahiri           #+#    #+#              #
#    Updated: 2021/12/11 09:13:52 by atahiri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		philo

FLAGS = -Wall -Wextra -Werror -g -fsanitize=address

INCLUDES =	philosophers.h

SRCS =	main.c \
		start.c \
		time.c \
		init_philos.c \
		routine.c \
		helpers/ft_atoi.c \
		helpers/ft_isdigit.c \
		

all: $(NAME)

$(NAME): $(SRCS) $(INCLUDES)
	@gcc $(FLAGS) $(SRCS) -o $(NAME) 

clean:
			@rm -rf *.o 

fclean: 	clean
			@rm -rf $(NAME)
			@rm -rf philo.dSYM

re: 		fclean all