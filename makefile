# Makefile

# the C++ compiler
CXX     = g++
CXXVERSION = $(shell g++ --version | grep ^g++ | sed 's/^.* //g')

# options to pass to the compiler
CXXFLAGS = -O0 -g3 -std=c++14

#ifeq "$(CXXVERSION)" "4.6.3"
#	CXXFLAGS += -std=c++0x
#else
#	CXXFLAGS += -std=c++11
#endif

All: all
all: main ModPolyTesterMain

main: main.cpp IntMod.h Poly.h
	$(CXX) $(CXXFLAGS) main.cpp -o main

deepclean: 
	rm -f *~ *.o *.gch main *.exe *.stackdump ModPolyTesterMain

clean:
	-rm -f *~ *.o *.gch *.stackdump

