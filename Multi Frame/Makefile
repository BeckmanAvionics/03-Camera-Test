CXX=g++
SOURCES=multiframe.cpp
# SOURCES+=xiApiPlusOcv.cpp
OBJECTS=$(SOURCES:.cpp=.o)
PROGRAM=multiframe


all: $(PROGRAM)

$(PROGRAM): multiframe.o 
	g++ $(OBJECTS) -o multiframe -L/usr/local/lib -lm3api -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs

multiframe.o: $(SOURCES) 
	g++ -c multiframe.cpp -I . -I /usr/local/include/ -g3 -Wall -c -fmessage-length=0
	
clean:
	rm -f *.o *~ $(PROGRAM) $(OBJECTS)

.PHONY clean