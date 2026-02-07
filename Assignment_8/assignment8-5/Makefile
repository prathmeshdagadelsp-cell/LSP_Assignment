CC = gcc
CFLAGS = -Wall -Wextra -O2

LIB = libmath.a
OBJ = math.o
TARGET = app

all: lib app

# Build static library
lib: $(LIB)

$(LIB): $(OBJ)
	ar rcs $(LIB) $(OBJ)

math.o: math.c math.h
	$(CC) $(CFLAGS) -c math.c

# Build app using static library
app: main.c $(LIB)
	$(CC) $(CFLAGS) main.c -L. -lmath -o $(TARGET)

clean:
	rm -f *.o *.a $(TARGET)