# Компилятор
CC := gcc

# Удаление
RM := rm

# Путь к си файлам
C := ./src/
# Путь к хэдерам
H := ./inc/
# Путь к объектным файлам
O := ./out/

# Файлы
SOURCES = $(wildcard $(C)*.c)
OBJECTS = $(patsubst $(C)%.c, $(O)%.o, $(SOURCES))
HEADERS = $(wildcard $(H)*.h)

# Опции компиляции
CFLAGS := -Werror -Wall -Wextra -Wpedantic -Wcast-align -Wcast-qual -Wconversion -Wenum-compare -Wfloat-equal -Wredundant-decls -Wsign-conversion -g

app.exe : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

$(OBJECTS) : $(O)%.o : $(C)%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : clean

clean :
	$(RM) -f $(O)*.o *.exe
