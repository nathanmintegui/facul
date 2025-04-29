CC=gcc
CFLAGS=-Wall
TARGET=program

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) -o $(TARGET) main.c

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)

