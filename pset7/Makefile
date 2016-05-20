prob1.o: prob1.c
	gcc -c prob1.c -o prob1.o
libprob1.a: prob1.o
	ar -rcs libprob1.a prob1.o prob1.o
prob1d_static: prob1d.c
	gcc -g -O0 -Wall -Wextra prob1d.c -I. -L. -lprob1 -lsqlite3 -o database.o
prob1_dynamic.o: prob1.c
	gcc -fPIC -c prob1.c -o prob1_dynamic.o
libprob1.so: prob1_dynamic.o
	gcc -shared prob1_dynamic.o -o libprob1.so
prob1d_dynamic: prob1d.c
	gcc -g -O0 -Wall -Wextra prob1d.c -I. -L. -lprob1 -lsqlite3 -o database.o
