CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRCDIR = src
OBJDIR = build
SOURCES = $(SRCDIR)/main.c $(SRCDIR)/models/application.c
OBJECTS = $(OBJDIR)/main.o $(OBJDIR)/application.o
TARGET = $(OBJDIR)/jar

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

$(OBJDIR)/main.o: $(SRCDIR)/main.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $(SRCDIR)/main.c -o $(OBJDIR)/main.o

$(OBJDIR)/application.o: $(SRCDIR)/models/application.c $(SRCDIR)/models/application.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c $(SRCDIR)/models/application.c -o $(OBJDIR)/application.o

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR) $(TARGET)
