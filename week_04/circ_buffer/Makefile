CXX = g++
CFLAGS = -std=c++11
INCL = ${SHARE}/include

all: test_circ_buffer

test_circ_buffer: test_circ_buffer.cpp
	$(CXX) $(CFLAGS) -I$(INCL) test_circ_buffer.cpp -o test_circ_buffer

test_circ_buffer_without_objects: test_circ_buffer_without_objects.cpp
	$(CXX) $(CFLAGS) test_circ_buffer_without_objects.cpp -o test_circ_buffer_without_objects


clean:
	rm -fv test_circ_buffer test_circ_buffer_without_objects data_filtered*