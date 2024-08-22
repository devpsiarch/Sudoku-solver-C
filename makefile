cc = gcc
cflages = -lncurses -I$(IDIR)

IDIR = ./include/
SRCDIR = ./src/

SOURCES = $(SRCDIR)*.c

all: sudoku run clean

sudoku:
	$(cc) $(SOURCES) $(cflages) -o $@
run:
	./sudoku

clean:
	rm sudoku
reset:
	rm solution/solved.txt
