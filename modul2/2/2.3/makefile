CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
LDFLAGS = -lm          # Подключаем математическую библиотеку
TARGET = dynam_while
SOURCES = dynam_while.c

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)