CC = g++
CFLAGS = -Wall
LDFLAGS =
OBJFILES = main.o
TARGET = MyAppStore

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)
clean:
	rm -f $(OBJFILES) $(TARGET) *~