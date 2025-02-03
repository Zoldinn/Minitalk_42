SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus
CFLAGS_BONUS = -Wall -Wextra -Werror -g -I ft_printf

OBJ_DIR = obj
PRINTF_DIR = ft_printf

SRC_SERVER = server.c utils.c
OBJ_SERVER = $(addprefix $(OBJ_DIR)/, $(SRC_SERVER:.c=.o))
SRC_CLIENT = client.c utils.c
OBJ_CLIENT = $(addprefix $(OBJ_DIR)/, $(SRC_CLIENT:.c=.o))
SRC_SERVER_BONUS = server_bonus.c utils.c
OBJ_SERVER_BONUS = $(addprefix $(OBJ_DIR)/, $(SRC_SERVER_BONUS:.c=.o))
SRC_CLIENT_BONUS = client_bonus.c utils.c
OBJ_CLIENT_BONUS = $(addprefix $(OBJ_DIR)/, $(SRC_CLIENT_BONUS:.c=.o))

PRINTF = $(PRINTF_DIR)/libftprintf.a

all: $(SERVER) $(CLIENT)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER): $(OBJ_SERVER) $(PRINTF)
	@echo "🔨 Compilation de $(SERVER)..."
	@cc $(CFLAGS) $(OBJ_SERVER) $(PRINTF) -o $(SERVER)
	@echo "✅ Compilation réussie !"

$(CLIENT): $(OBJ_CLIENT) $(PRINTF)
	@echo "🔨 Compilation de $(CLIENT)..."
	@cc $(CFLAGS) $(OBJ_CLIENT) $(PRINTF) -o $(CLIENT)
	@echo "✅ Compilation réussie !"

$(SERVER_BONUS): $(OBJ_SERVER_BONUS) $(PRINTF)
	@echo "🔨 Compilation de $(SERVER_BONUS)..."
	@cc $(CFLAGS) $(OBJ_SERVER_BONUS) $(PRINTF) -o $(SERVER_BONUS)
	@echo "✅ Compilation réussie !"

$(CLIENT_BONUS): $(OBJ_CLIENT_BONUS) $(PRINTF)
	@echo "🔨 Compilation de $(CLIENT_BONUS)..."
	@cc $(CFLAGS) $(OBJ_CLIENT_BONUS) $(PRINTF) -o $(CLIENT_BONUS)
	@echo "✅ Compilation réussie !"

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@echo "🔧 Compilation de $<..."
	@cc $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(PRINTF):
	@echo "📦 Compilation de ft_printf..."
	@make -s -C $(PRINTF_DIR)

clean:
	@echo "🧹 Nettoyage des fichiers .o ..."
	@rm -rf $(OBJ_DIR)
	@make -s -C $(PRINTF_DIR) clean
	@echo "✅ Nettoyage terminé !"


fclean: clean
	@echo "🗑️ Suppression de $(SERVER), $(CLIENT)..."
	@echo "🗑️ Suppression de $(SERVER_BONUS), $(CLIENT_BONUS)..."
	@rm -f $(SERVER) $(CLIENT)
	@rm -f $(SERVER_BONUS) $(CLIENT_BONUS)
	@make -s -C $(PRINTF_DIR) fclean
	@echo "✅ Tout a été supprimé !"

re: fclean all

.PHONY: all clean fclean re
