# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/07 18:33:46 by sesnowbi          #+#    #+#              #
#    Updated: 2021/07/23 18:42:18 by sesnowbi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

SRCS	= main.c init_strct.c routine.c exec_threads.c \
			utils/libft_utils.c utils/other_utils.c utils/time_utils.c

INC		= includes/philosophers.h
DEPS	= $(INC)
OBJS	= $(SRCS:.c=.o)

CC		= gcc
RM		= /bin/rm -f
FLAGS	= -g -pthread -Wall -Werror -Wextra# -fsanitize=address

%.o: %.c $(DEPS)
	$(CC) $(FLAGS) -c $< -include $(INC) -o $(<:.c=.o)

$(NAME):		$(OBJS)
					$(CC) $(FLAGS) $(OBJS) -o $(NAME)

all:			$(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
					$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
