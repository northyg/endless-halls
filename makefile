CXX = g++
CXXFLAGS = -std=c++0x
#CXXFLAGS += -g
CXXFLAGS += -I.

OBJS = main.o space.o room.o teleportRoom.o altarRoom.o orbRoom.o board.o orbItem.o game.o player.o

SRCS = main.cpp space.cpp teleportRoom.cpp altarRoom.cpp orbRoom.cpp board.cpp orbItem.cpp game.cpp player.cpp

HEADERS = space.hpp teleportRoom.hpp altarRoom.hpp orbRoom.hpp board.hpp orbItem.hpp game.hpp player.hpp

#target: dependencies
#	rule to build

finalProject: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o finalProject
	
${OBJS}: ${SRCS}
		${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
		
clean: 
	rm *.o finalProject
	
	
	
	
