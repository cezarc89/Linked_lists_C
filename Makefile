SRC = link.c
OBJ = link.o
PROJ = link

$(PROJ) : $(OBJ)
	gcc $(OBJ) -o $(PROJ)

$(OBJ) : $(SRC)

clean:
	rm $(OBJ) $(PROJ)
