compile: dir.o
	gcc -o dir.out dir.o

stat.o: dir.c
	gcc -c dir.c

run: dir.out
	./dir.out

clean:
	rm *.out
	rm *.o
	rm *~