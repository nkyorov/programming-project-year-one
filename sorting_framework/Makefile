
# code details

EXE_DIR = .
EXE = $(EXE_DIR)/Sort

SRC= arrays.c sort.c main.c

# generic build details

CC=      cc
COPT=    -g
CFLAGS= -lm

# compile to  object code

OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(COPT) -c -o $@ $<

# build executable

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(EXE)

# clean up compilation

clean:
	rm -f $(OBJ) $(EXE)

main.o: main.c
sort.o: sort.c prototypes.h
arrays.o: arrays.c prototypes.h