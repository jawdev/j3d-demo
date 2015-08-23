TARGET	= runme
CC		= g++-5
SHELL	:= /bin/bash
CFLAGS	= -I. -Wall -std=c++14 -g -rdynamic -pthread -m64
LFLAGS	= -L. -lm -lGLEW -lGL -lGLU -lglut
DEPS	:= $(shell find -name "*.h")
SRCS	:= $(shell find -name "*.cpp")
OBJDIR	= .obj

$(shell if [ ! -d "$(OBJDIR)" ]; then mkdir "$(OBJDIR)"; fi)
$(shell ls -d */ 2>/dev/null | while read d; do find "$$d" | while read d2; do if test -d "$$d2"; then mkdir -p "$(OBJDIR)/$$d2"; fi; done; done)
OBJS = $(patsubst %,$(OBJDIR)/%.o,$(SRCS))

$(OBJDIR)/%.o: % $(DEPS)
	$(CC) -c -o $@ $(CFLAGS) $<

$(TARGET): $(OBJS)
	$(CC) -o $@ $(CFLAGS) $^ $(LFLAGS)

clean:
	rm -f $(TARGET) *~
	rm -rf $(OBJDIR)/*
