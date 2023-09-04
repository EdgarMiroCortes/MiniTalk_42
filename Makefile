NAME = minitalk
CLIENT = client
SERVER = server
PRINTF_PATH = printf/
PRINTF_LIB = $(PRINTF_PATH)ft_printf.a
CFLAGS = -Wall -Wextra -Werror

SRC_CLIENT = client.c
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

SRC_SERVER = server.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)

RM = rm -f

%.o: %.c Makefile
	@$(CC) $(CFLAGS) -MMD -I./ -c $< -o $@

all: subsystems
	@$(MAKE) $(CLIENT)
	@$(MAKE) $(SERVER)

$(CLIENT): $(OBJ_CLIENT)
	@$(CC)  $(CFLAGS) $(OBJ_CLIENT) -o $@
	@echo "client compiled $<..."
	@ rm -rf client.d

subsystems:
	@make -C $(PRINTF_PATH) all

$(SERVER): $(OBJ_SERVER)
	@$(CC) $(CFLAGS) $(PRINTF_LIB) $(OBJ_SERVER) -o $@
	@echo "server compiled $<..."
	@ rm -rf server.d

clean:
	@$(RM) $(OBJ_SERVER) $(OBJ_CLIENT)
	@$(MAKE) clean -C printf

fclean: clean
	@$(RM) $(CLIENT) $(SERVER) $(PRINTF_LIB)

re: fclean all

.PHONY: all clean fclean re bonus