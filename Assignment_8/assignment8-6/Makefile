
CC = gcc
CFLAGS = -Wall -Wextra -O2 -fPIC

LIB = libmath.so
OBJ = math.o
TARGET = app

all: so app

# Build shared library
so: $(LIB)

$(LIB): $(OBJ)
	$(CC) -shared -o $(LIB) $(OBJ)

math.o: math.c math.h
	$(CC) $(CFLAGS) -c math.c

# Build app using shared library
app: main.c $(LIB)
	$(CC) -Wall -Wextra -O2 main.c -L. -lmath -o $(TARGET)

run: app
	LD_LIBRARY_PATH=. ./$(TARGET)

clean:
	rm -f *.o *.so $(TARGET)