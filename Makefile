main: funkcijos.o
	g++ -o prog Vector.cpp funkcijos.o
funkcijos:
	g++ -c funkcijos.cpp
clean:
	del *.o prog.exe