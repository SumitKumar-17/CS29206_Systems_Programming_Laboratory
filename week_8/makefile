CC = gcc
CFLAGS = -Wall 
GPROF= -pg 
GPROF_EXTRA=  -q -Z -b
RM = rm -f
FILE_NAME_1= happy_algo1.c
FILE_NAME_2= happy_algo2.c
FILE_NAME_3= happy_algo3.c
FILE_NAME_4= happy_algo4.c
FILE_NAME_5= fib_algo_1.c
FILE_NAME_6= question_5.c
FILE_NAME_7= question_4.c

run: 
	$(CC) $(CFLAGS) $(GPROF)  $(FILE_NAME_7) 
	./a.out
	gprof $(GPROF_EXTRA) ./a.out gmon.out  > $(FILE_NAME_7)_gprof_output.txt

clean :
	$(RM) a.out
	$(RM) gmon.out
