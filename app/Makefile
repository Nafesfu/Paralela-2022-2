CXX = g++
CXXFLAGS = -g3 -Wall -std=c++14
MKDIR = mkdir -p

LIBS = -lm

directorios:
	$(MKDIR) build dist

main.o: directorios main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o build/main.o
	$(CXX) $(CXXFLAGS) -c Utils.cpp -o build/utils.o
	$(CXX) $(CXXFLAGS) -c Monomio.cpp -o build/monomio.o

all: clean main.o
	$(CXX) $(CXXFLAGS) -o dist/programa \
	build/main.o build/utils.o build/monomio.o \
	$(LIBS)
	rm -fr build

clean:
	rm -fr *.o a.out core programa dist build

.DEFAULT_GOAL := all
