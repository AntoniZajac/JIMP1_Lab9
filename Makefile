a.out: main.o mat_io.o gauss.o backsubst.o
	$(CC) $^

main.o: main.c
mat_io.o: mat_io.c
gauss.o: gauss.c
backsubst.o: backsubst.c
