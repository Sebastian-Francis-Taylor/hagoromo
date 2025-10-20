CC = gcc
CFLAGS = -Wall -O3 -I./src
DEBUG_CFLAGS = -Wall -g -O0 -DDEBUG -I./src

EXAMPLES_DIR = examples
BUILD_DIR = build
BIN_DIR = bin

EXAMPLE_SRCS = $(wildcard $(EXAMPLES_DIR)/*.c)
EXAMPLE_BINS = $(patsubst $(EXAMPLES_DIR)/%.c,$(BIN_DIR)/%,$(EXAMPLE_SRCS))

all: $(EXAMPLE_BINS)

$(BIN_DIR)/%: $(EXAMPLES_DIR)/%.c
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $<

debug: CFLAGS = $(DEBUG_CFLAGS)
debug: all

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

.PHONY: all debug clean
