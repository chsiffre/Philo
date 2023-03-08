NAME = philo

CFLAGS = -Wall -Wextra -g3 -pthread

PHILO =	${DIR_PHILO}ft_atoi.c \
			${DIR_PHILO}main.c \
			${DIR_PHILO}init_create.c \
			${DIR_PHILO}fork.c \
			${DIR_PHILO}thread_process.c \
			${DIR_PHILO}philo_utils.c \
			${DIR_PHILO}parsing.c

	
LIST_OBJS = ${PHILO:.c=.o}

DIR_OBJS = .objs/
DIR_PHILO = srcs/
DIR_HEADERS = includes/

all : $(NAME)

%.o: %.c $(CC) $(CFLAGS) -I philo.h -I $(DIR_PHILO) -c $< -o ${<:.c=.o} 

$(NAME) : $(LIST_OBJS)
	$(CC) $(LIST_OBJS) -g3 -pthread -o $(NAME)
clean:
	rm -rf $(LIST_OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)

.PHONY : clean fclean re bonus
