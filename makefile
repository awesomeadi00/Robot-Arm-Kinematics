robotarm: main.o Point.o Segment.o Robot.o pbPlots.o supportLib.o
	g++ main.o Point.o Segment.o Robot.o pbPlots.o supportLib.o -o robotarm
main.o: main.cpp
	g++ -c main.cpp
Point.o: Point.cpp Point.h
	g++ -c Point.cpp
Segment.o: Segment.cpp Segment.h
	g++ -c Segment.cpp
Robot.o: Robot.cpp Robot.h
	g++ -c Robot.cpp
pbPlots.o: pbPlots.cpp pbPlots.hpp
	g++ -c pbPlots.cpp
supportLib.o: supportLib.cpp supportLib.hpp
	g++ -c supportLib.cpp
clean: 
	rm main.o Point.o Segment.o Robot.o pbPlots.o supportLib.o