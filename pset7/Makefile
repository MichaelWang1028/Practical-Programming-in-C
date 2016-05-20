prob1.o: prob1.c
	gcc -c prob1.c -o prob1.o
libprob1.a: prob1.o
	ar -rcs libprob1.a prob1.o prob1.o
prob1d: prob1d.c libprob1.a
	gcc -g -O0 -Wall -Wextra prob1d.c -I. -L. -lprob1 -lsqlite3 -o database.o
