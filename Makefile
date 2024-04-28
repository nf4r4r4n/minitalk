SERVER				=	server
CLIENT				=	client
LIBFT				=	libft/libft.a

all:		client server

$(NAME):	$(OBJS)
	@make -C libft
	@ar -r $(NAME).a $?
	@cc -o $(NAME) $(NAME).a $(LIBFT)

client:		$(CLIENT).o
	@make -C libft
	@ar -r $(CLIENT).a $?
	@cc -o $(CLIENT) $(CLIENT).a $(LIBFT)

server:		$(SERVER).o
	@make -C libft
	@ar -r $(SERVER).a $?
	@cc -o $(SERVER) $(SERVER).a $(LIBFT)

clean:
	@make -C libft fclean
	@rm -f $(CLIENT).o $(SERVER).o $(CLIENT).a $(SERVER).a

fclean:		clean
	@make -C libft fclean
	@rm -f $(CLIENT) $(SERVER)

re:			fclean all

.PHONY:	all clean fclean
