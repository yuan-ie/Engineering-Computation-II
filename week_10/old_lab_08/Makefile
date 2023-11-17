CXX=g++
CXXFLAGS=-std=c++11

debug: CXXFLAGS += -g
debug: all

timing_example: timing_example.cpp
	$(CXX) $(CXXFLAGS) timing_example.cpp -o timing_example

bubble.o: bubble.cpp bubble.h	
	$(CXX) $(CXXFLAGS) -c bubble.cpp

heap.o: heap.cpp heap.h
	$(CXX) $(CXXFLAGS) -c heap.cpp

RNG.o: RNG.cpp RNG.h
	$(CXX) $(CXXFLAGS) -c RNG.cpp

merge.o: merge.cpp merge.h
	$(CXX) $(CXXFLAGS) -c merge.cpp

lab_08.o: lab_08.cpp
	$(CXX) $(CXXFLAGS) -c lab_08.cpp

lab_08: lab_08.o bubble.o heap.o RNG.o merge.o
	$(CXX) $(CXXFLAGS) lab_08.o heap.o bubble.o merge.o RNG.o -o lab_08

all: lab_08

clean:
	@find . ! -name submit.py -type f -executable -exec rm {} \;
	@rm -f *.o
