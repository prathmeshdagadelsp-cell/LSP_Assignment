CC = gcc 

CFLAGS = -Wall -Wextra -02 

TARGET = app 

SRC = main.c add.c 

all: $(TARGET)

$(TARGET): $(SRC)

$(CC) $(CFLAGS) $(SRC) -o $(TARGET) 

run: $(TARGET) 
	./$(TARGET)

clean:
	rm -f $(TARGET)
 

help:
	@echo "usage:"
	@echo "make   -> build the application "
	@echo "make run  -> run the application "
	@echo "make clean -> remove the binary "
	@echo "make help -> show this help messsage"