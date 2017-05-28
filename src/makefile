#makefile template
#should reside in the src folder
#      folder
#   -------------
#   |    |      |
#  lib  src   include
#

DIR =../include
CC = g++
#CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =../lib

LIBS=-l newt


#_DEPS = hellomake.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

#_OBJ = hellomake.o hellofunc.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
#	$(CC) -o $@ $^ $(CFLAGS) main.cpp $(LIBS)
	$(CC) -o programe main.cpp $(LIBS)
.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 

