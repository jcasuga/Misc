carnival: driver.o patron.o
	g++ -o carnival driver.o patron.o
driver.o: driver.cpp
	g++ -c driver.cpp
patron.o: patron.cpp patron.h
	g++ -c patron.cpp
clean: rm *.o amusementPark