CC = g++
CFLAGS = -Wall
LDFLAGS =
OBJFILES = id.o main.o
TARGET = id

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)
clean:
	rm -f $(OBJFILES) $(TARGET) *~