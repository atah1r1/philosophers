# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 11:42:25 by atahiri           #+#    #+#              #
#    Updated: 2021/11/25 22:26:45 by atahiri          ###   ########.fr        #
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
		helpers/ft_isalpha.c \
		helpers/ft_isdigit.c \

all: $(NAME)

$(NAME): $(SRCS) $(INCLUDES)
	@gcc $(FLAGS) $(SRCS) -o $(NAME) 

clean:
			@rm -rf *.o 

fclean: 	clean
			@rm -rf $(NAME)

re: 		fclean all