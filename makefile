SRC = ./src/*.cpp \
	  ./src/game/*.cpp
INC = ./include
BIN = ./bin
CC = g++
TARGET = game
SFML = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
FLAGS = -g -Wall -Wextra -o $(BIN)/$(TARGET) $(SRC) $(SFML)

all: clean build run

build:
	$(CC) $(FLAGS)

clean:
	rm -f $(BIN)/*

run: $(BIN)/$(TARGET)
	$(BIN)/$(TARGET)