$(CC) = gcc

cal: main.o cal_mean.o cal_sub.o
	$(CC) main.o cal_mean.o cal_sub.o -o cal

main.o: main.c cal_mean.h
	$(CC) -c main.c

cal_mean.o: cal_mean.c cal_mean.h
	$(CC) -c cal_mean.c

cal_sub.o: cal_sub.c cal_mean.h
	$(CC) -c cal_sub.c

clean:
	rm -f *.o cal