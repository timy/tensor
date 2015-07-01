CC		=	g++
SRC		=	tensor.cc main.cc
OBJ		=	$(SRC:%.cc=%.o)
EXE		=	test

CFLAGS	+=	-std=c++11 -g
LFLAGS	+=

%.o : %.cc
	$(CC) $< $(CFLAGS) -c -o $@

all : $(EXE)

$(EXE) : $(OBJ)
	$(CC) $(OBJ) $(LFLAGS) -o $@

clean:
	$(RM)
	$(RM) $(OBJ)
	$(RM) *~
