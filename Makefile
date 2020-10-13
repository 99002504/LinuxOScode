SRC = src/factorial.c\
src/flip.c\
src/isPalindrome.c\
src/isPrime.c\
src/reset.c\
src/set.c\
src/strcomp.c\
src/strconcat.c\
src/strcopy.c\
src/strlen.c\
src/test.c\
src/vsum.c\


test.c

INC= -Iinc

PROJECT_NAME = stringutility.o

$(PROJECT_NAME): $(SRC)
	gcc $(SRC) $(INC) -o $(PROJECT_NAME)

run:$(PROJECT_NAME)
	./${PROJECT_NAME}