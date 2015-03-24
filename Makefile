
f_universe.o: f_universe.cpp
		g++ -c f_universe.cpp -o f_universe.o

f_processing.o: f_processing.cpp
		g++ -c f_processing.cpp	-o f_processing.o

default: f_processing.o f_universe.o
	g++ f_processing.o f_universe.o u_sim.cpp -o usim.o

clean:
	rm *.o *~
