# Compiler
CC = g++
CCFLAGS = -Wall -Werror -std=c++11 -g -Os -Ivendor/stb
# Source and Object directories
SRC_DIR = src
OBJ_DIR = obj

# Find all .cpp and .c files in src directory
SRCS++ = $(wildcard $(SRC_DIR)/*.cpp) 
SRCS = $(wildcard $(SRC_DIR)/*.c)
# Generate corresponding .o file names
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS++))
OBJS += $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
# external libraries
SSTRIP = vendor/sstrip/sstrip
UPX = vendor/upx/build/release/upx

# Target executable
TARGET = Game

# Build target
all: $(OBJ_DIR) $(TARGET) dist

run: $(TARGET)
	./$(TARGET)

dist: $(TARGET).dist

$(TARGET): $(OBJS)
	$(CC) $(CCFLAGS) -o $@ $^

$(TARGET).dist: $(SSTRIP) $(UPX) $(TARGET)
	cp $(TARGET) $@
	$(SSTRIP) $@
	$(UPX) $@
	

# Rule to compile .cpp/.c files to .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CCFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CCFLAGS) -c $< -o $@

# Create object directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(SSTRIP):
	$(MAKE) -C vendor/sstrip

$(UPX):
	$(MAKE) -C vendor/upx


# Clean rule
clean:
	rm -rf $(OBJ_DIR)/*.o $(TARGET) $(TARGET).dist

.PHONY: all clean
