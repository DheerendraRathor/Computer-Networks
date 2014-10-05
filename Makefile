BIN=exe_10

SRCS=*.cpp
INCLUDES=*.h

all: $(BIN)


$(BIN): $(SRCS) $(INCLUDES)
	g++ $(CPPFLAGS) $(SRCS) -o $(BIN) $(LDFLAGS) $(LIBS)

clean:
	rm -f $(BIN)
	rm -f *.o
	rm -f *~
	rm -f *.txt
	
test:
	./$(BIN) <sampleIO/routingTableAndIPaddresses1 >output1.txt
	./$(BIN) <sampleIO/routingTableAndIPaddresses2 >output2.txt
	diff output1.txt sampleIO/longest_prefix_matches1
	diff output2.txt sampleIO/longest_prefix_matches2


