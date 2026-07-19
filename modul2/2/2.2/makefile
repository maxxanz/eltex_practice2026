CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
TARGET = calculator

# Все .c файлы в папке
SOURCES = cusual_calc.c func_calc.c
OBJECTS = $(SOURCES:.c=.o)

# Сборка программы
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# Компиляция .c в .o
%.o: %.c func_calc.h
	$(CC) $(CFLAGS) -c $< -o $@

# Запуск
run: $(TARGET)
	./$(TARGET)

# Очистка
clean:
	rm -f $(OBJECTS) $(TARGET)

# По умолчанию
all: $(TARGET)