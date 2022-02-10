CXX=g++
SOURCES=xiApiPlusOcv.cpp
SOURCES+=xiApiPlusOcv.hpp
#SOURCES+=03-Camera-Test/xiAPIplusOpencv/main.cpp
SOURCES+=camera_main.cpp
#SOURCES+=sample_img_test.cpp
OBJECTS=$(SOURCES:.cpp=.o)
PROGRAM=camera_main
PROGRAM+=sample_img_test


all: camera_main sample_img_test

#all: $(PROGRAM)


#Original make for only camera_main

#$(PROGRAM): camera_main.o
#	g++ $(OBJECTS) -o camera_main -L/usr/local/lib -lm3api -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs

#camera_main.o: $(SOURCES) 
#	g++ -c camera_main.cpp -I . -I /usr/local/include/ -g3 -Wall -c -fmessage-length=0

#New make for both camera_main and sample_img_test

camera_main: camera_main.o
	g++ camera_main.cpp -o camera_main -L/usr/local/lib -lm3api -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs

camera_main.o: $(SOURCES) 
	g++ -c camera_main.cpp -I . -I /usr/local/include/ -g3 -Wall -c -fmessage-length=0

sample_img_test: sample_img_test.o
	g++ sample_img_test.cpp -o sample_img_test -L/usr/local/lib -lm3api -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs
	
sample_img_test.o: $(SOURCES)
	g++ -c sample_img_test.cpp -I . -I /usr/local/include/ -g3 -Wall -c -fmessage-length=0


clean:
	rm -f *.o *~ $(PROGRAM) $(OBJECTS)

.PHONY: clean all
