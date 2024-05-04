SERVER				=	server
CLIENT				=	client
SERVER_BNS			=	server_bonus
CLIENT_BNS			=	client_bonus
LIBFT				=	libft/libft.a
CFLAGS				=	-Wall -Wextra -Werror

all:		client server

$(NAME):	$(OBJS)
	@make -C libft
	@ar -r $(NAME).a $?
	@cc -o $(NAME) $(CFLAGS) utils.c $(NAME).a $(LIBFT)

client:		$(CLIENT).o
	@make -C libft
	@ar -r $(CLIENT).a $?
	@cc -o $(CLIENT) $(CFLAGS) utils.c $(CLIENT).a $(LIBFT)

client_bonus:		$(CLIENT_BNS).o
	@make -C libft
	@ar -r $(CLIENT_BNS).a $?
	@cc -o $(CLIENT_BNS) $(CFLAGS) utils.c $(CLIENT_BNS).a $(LIBFT)

server:		$(SERVER).o
	@make -C libft
	@ar -r $(SERVER).a $?
	@cc -o $(SERVER) $(CFLAGS) utils.c $(SERVER).a $(LIBFT)

server_bonus:		$(SERVER_BNS).o
	@make -C libft
	@ar -r $(SERVER_BNS).a $?
	@cc -o $(SERVER_BNS) $(CFLAGS) utils.c $(SERVER_BNS).a $(LIBFT)

bonus:	client_bonus server_bonus

clean:
	@make -C libft fclean
	@rm -f $(CLIENT).o $(SERVER).o $(CLIENT_BNS).o $(SERVER_BNS).o $(CLIENT).a $(SERVER).a $(CLIENT_BNS).a $(SERVER_BNS).a

fclean:		clean
	@make -C libft fclean
	@rm -f $(CLIENT) $(SERVER) $(CLIENT_BNS) $(SERVER_BNS)

re:			fclean all

.PHONY:	all clean fclean re bonus
