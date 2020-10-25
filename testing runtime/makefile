CC = g++
CFLAGS = -Wall
LDFLAGS =
OBJFILES = HashTable.o main.o
TARGET = hash

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)
clean:
	rm -f $(OBJFILES) $(TARGET) *~