CC = gcc 

CFLAGS = -Wall -Wextra -02 

TARGET = app 

SRC = main.c 

all: $(TARGET)

$(TARGET): $(SRC)

$(CC) $(CFLAGS) $(SRC) -o $(TARGET) 

run: $(TARGET) 
	./$(TARGET)

clean:
	rm -f $(TARGET)
 

