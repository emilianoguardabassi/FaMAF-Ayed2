CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99 -g
OBJECTS= main.o queue_helpers.o queue.o
SOURCE=main.c queue_helpers.c queue.c
TARGET=readqueue

all:$(TARGET)

$(TARGET): main.o queue.o queue_helpers.o
	gcc $(CFLAGS) $(OBJECTS) -o $(TARGET)

obects: main.c queue.c queue_helpers.c 
	gcc $(CFLAGS) $(SOURCE) -c

clean:
		rm $(OBJECTS) $(TARGET)
