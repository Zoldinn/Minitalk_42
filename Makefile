SERVER = server
CLIENT = client
CFLAGS = -Wall -Wextra -Werror -g -I ft_printf

OBJ_DIR = obj
PRINTF_DIR = ft_printf

SRC_SERVER = server.c utils.c
OBJ_SERVER = $(addprefix $(OBJ_DIR)/, $(SRC_SERVER:.c=.o))
SRC_CLIENT = client.c utils.c
OBJ_CLIENT = $(addprefix $(OBJ_DIR)/, $(SRC_CLIENT:.c=.o))

PRINTF = $(PRINTF_DIR)/libftprintf.a

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJ_SERVER) $(PRINTF)
	@echo "🔨 Compilation de $(SERVER)..."
	@cc $(CFLAGS) $(OBJ_SERVER) $(PRINTF) -o $(SERVER)
	@echo "✅ Compilation réussie !"

$(CLIENT): $(OBJ_CLIENT) $(PRINTF)
	@echo "🔨 Compilation de $(CLIENT)..."
	@cc $(CFLAGS) $(OBJ_CLIENT) $(PRINTF) -o $(CLIENT)
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
	@rm -f $(SERVER) $(CLIENT)
	@make -s -C $(PRINTF_DIR) fclean
	@echo "✅ Tout a été supprimé !"

re: fclean all

.PHONY: all clean fclean re
