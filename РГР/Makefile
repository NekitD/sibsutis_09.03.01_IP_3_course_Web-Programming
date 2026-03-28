CC = g++

SRC = src
OBJ = obj
INCLUDE = include

GAME_DIR = game
WEB_DIR = web

GAME_LIB = $(INCLUDE)/game.a
GAME_SRC = $(SRC)/$(GAME_DIR)/game.cpp
GAME_OBJ = $(OBJ)/$(GAME_DIR)/game.o
GAME_DEPS = $(OBJ)/$(GAME_DIR)/game.d

CLIENT_SOURCE = $(SRC)/$(WEB_DIR)/client.cpp
SERVER_SOURCE = $(SRC)/$(WEB_DIR)/server.cpp

CLIENT_TARGET = WEB_OBJ/client.o
SERVER_TARGET = WEB_OBJ/server.o


WEB_SRC = $(CLIENT_SOURCE) $(SERVER_SOURCE)
WEB_OBJ = $(OBJ)/$(WEB_DIR)


.PHONY: all clean game player

all: $(GAME_OBJ) $(GAME_LIB) $(SERVER_TARGET) $(CLIENT_TARGET)

$(GAME_OBJ): $(GAME_SRC)
	@$(CC) -o $@ $^

$(GAME_LIB): $(GAME_OBJ) $(WEB_SRC)
	@mkdir $(OBJ)/$(GAME_DIR)
	@ar rcs $@ $^


$(SERVER_TARGET): $(SERVER_SOURCE)
	@mkdir $(OBJ)/$(WEB_DIR)
	@$(CC) -o $@ $^

$(CLIENT_TARGET): $(CLIENT_SOURCE)
	@mkdir $(OBJ)/$(WEB_DIR)
	@$(CC) -o $@ $^

-include $(GAME_DEPS)

game:
	@./$(SERVER_TARGET)

player:
	@./$(CLIENT_TARGET)

clean:
	@rm $(GAME_OBJ)/*.o && rm $(GAME_OBJ)/*.a && rm $(GAME_OBJ)/*.d
	@rm $(WEB_OBJ)/*.o
	@rm $(OBJ)/*.o