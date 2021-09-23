CXX=g++
SOURCES=xiApiPlusOcv.cpp
#SOURCES+=03-Camera-Test/xiAPIplusOpencv/main.cpp
SOURCES+=main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
PROGRAM=main


all: $(PROGRAM)

$(PROGRAM): camera_main.o 
	g++ $(OBJECTS) -o camera_main -L/usr/local/lib -lm3api -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs

camera_main.o: $(SOURCES) 
	g++ -c main.cpp -I . -I /usr/local/include/ -g3 -Wall -c -fmessage-length=0
	
clean:
	rm -f *.o *~ $(PROGRAM) $(OBJECTS)

.PHONY: clean all
