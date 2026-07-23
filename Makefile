CC := clang
CFLAGS := -std=c17 -Wall -Wextra -Wpedantic -g
TARGET := game
SRC_DIR := src
BUILD_DIR := build
SOURCES := $(shell find $(SRC_DIR) -name '*.c')
OBJECTS := $(SOURCES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

RAYLIB_CFLAGS := $(shell pkg-config --cflags raylib) -I$(SRC_DIR)
RAYLIB_LIBS := $(shell pkg-config --libs raylib)

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET) $(RAYLIB_LIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(RAYLIB_CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(BUILD_DIR) $(TARGET)