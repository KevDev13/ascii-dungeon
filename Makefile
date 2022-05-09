EXEC_NAME=dungeon
CC=g++
CXXFLAGS=-c -Wall -g -std=c++17
LDLIBS=-lBearLibTerminal
LDFLAGS=#none

INC_DIRS=ThirdParty
INCLUDES=$(foreach i, $(INC_DIRS), -I$i)
BIN_DIR=bin
OBJ_DIR=$(BIN_DIR)/obj
SRC_DIR=src

SOURCE_FILES=main.cpp \
		$(wildcard $(SRC_DIR)/*.cpp)
EXEC_FILES=$(EXEC_NAME:%=$(BIN_DIR)/%)
OBJ_FILES=$(SOURCE_FILES:%.cpp=$(OBJ_DIR)/%.o)

.PHONY: build clean run all


all: build

build: $(EXEC_FILES)

clean:
	rm -rf $(BIN_DIR)

$(EXEC_FILES): $(OBJ_FILES)
	@$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)
	@echo "Build complete!"

$(OBJ_FILES): $(OBJ_DIR)/%.o: $(SOURCE_FILES)
	@echo Compiling $<
	@mkdir -p $(@D)
	@$(CC) $(CXXFLAGS) $(INCLUDES) -o $@ $<
	@echo "Compilation complete!"

run:
	@./$(BIN_DIR)/$(EXEC_NAME)

