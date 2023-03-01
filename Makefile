NAME = philosopher

CFLAGS = -Wall -Wextra -Werror -g3 -pthread

PHILO =	${DIR_PHILO}ft_atoi.c \
			${DIR_PHILO}main.c \
			${DIR_PHILO}init_create.c \
	
LIST_OBJS = ${PHILO:.c=.o}

DIR_OBJS = .objs/
DIR_PHILO = srcs/
DIR_HEADERS = includes/

all : $(NAME)

%.o: %.c $(CC) $(CFLAGS) -I philo.h -I $(DIR_PHILO) -c $< -o ${<:.c=.o} 

$(NAME) : $(LIST_OBJS)
	$(CC) $(LIST_OBJS) -g3 -pthread -lpthread -o $(NAME)
clean:
	rm -rf $(LIST_OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)

.PHONY : clean fclean re bonus
