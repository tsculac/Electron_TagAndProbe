OBJS = plotter.o readInput.o run.o

CXXFLAGS = -g -I. -m64 $(shell root-config --cflags)
LDFLAGS = $(shell root-config --libs)
CXX = g++

run: ${OBJS}
	${CXX} ${LDFLAGS} ${CXXFLAGS} ${OBJS} -o run
	
################################
plotter.o: plotter.cpp
	${CXX} -c ${CXXFLAGS} $^
readInput: readInput.cpp
	${CXX} -c ${CXXFLAGS} $^
run.o: run.cpp 
	${CXX} -c ${CXXFLAGS} run.cpp
################################

# ==========================================
clean:
	\rm *.o run