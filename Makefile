COMPILER=		g++
CFLAGS=			-I. -Wall -Wno-write-strings -m64 -pthread -std=c++14 -g -rdynamic -fopenmp
LIBRARIES=		-lm -lGLEW -lGL -lGLU -lglut
OBJDIR=			.obj
BINARY=			demo

#DEPENDENCIES=	j3d/j3d.h \
				j3d/debug.h

#SOURCES=		j3d/debug.cc \
				main.cc

DEPENDENCIES:=$(shell find -name '*.h')
SOURCES:=$(shell find -name '*.cc')

###############################################################################

OBJ=$(patsubst %,$(OBJDIR)/%.o,$(SOURCES))

$(OBJDIR)/%.o: % $(DEPENDENCIES)
	$(COMPILER) -c -o $@ $< $(CFLAGS)

$(BINARY): $(OBJ)
	$(COMPILER) -o $@ $^ $(CFLAGS) $(LIBRARIES)

.PHONY: clean

clean:
	rm -f $(BINARY) $(OBJDIR)/*.o $(OBJDIR)/j3d/*.o *~ core
