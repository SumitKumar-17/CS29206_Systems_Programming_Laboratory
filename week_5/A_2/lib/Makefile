all: order1/soln1.o order2/soln2.o order3/soln3.o
	ar rcs librecrel.a order1/soln1.o order2/soln2.o order3/soln3.o


clean:
	cd order1 && make clean
	cd order2 && make clean
	cd order3 && make clean

distclean:
	rm -f librecrel.a