TARGET = build/exec

CC = gcc
CFLAGS = -Wall -Wextra -g -Isrc

SRCS = $(wildcard src/*.c)

all: $(TARGET)

$(TARGET): $(SRCS)
	@mkdir -p build
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -rf build/* res/*.vtk