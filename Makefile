# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 11:42:25 by atahiri           #+#    #+#              #
#    Updated: 2021/12/05 11:05:18 by atahiri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		philo

FLAGS = -Wall -Wextra -Werror #-g -fsanitize=address

INCLUDES =	philosophers.h

SRCS =	main.c \
		check_data.c \
		start.c \
		time.c \
		init_philos.c \
		helpers/ft_atoi.c \
		helpers/ft_isdigit.c \
		routine/take_forks.c \
		routine/start_eating.c \
		routine/start_sleeping.c \
		routine/start_thinking.c \
		

all: $(NAME)

$(NAME): $(SRCS) $(INCLUDES)
	@gcc $(FLAGS) $(SRCS) -o $(NAME) 

clean:
			@rm -rf *.o 

fclean: 	clean
			@rm -rf $(NAME)

re: 		fclean all