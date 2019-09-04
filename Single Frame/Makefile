CXX=g++
SOURCES=sample.cpp
SOURCES+=xiApiPlusOcv.cpp
OBJECTS=$(SOURCES:.cpp=.o)
PROGRAM=sample


all: $(PROGRAM)

$(PROGRAM): sample.o 
	g++ $(OBJECTS) -o sample -L/usr/local/lib -lm3api -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs

xiApiPlusOcv.o: sample.cpp 
	g++ -c sample.cpp -I . -I /usr/local/include/ -g3 -Wall -c -fmessage-length=0
	
clean:
	rm -f *.o *~ $(PROGRAM) $(OBJECTS)






