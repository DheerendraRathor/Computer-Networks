BIN=exe_10

SRCS=*.cpp
INCLUDES=*.h

all: $(BIN)


$(BIN): $(SRCS) $(INCLUDES)
	@g++ $(CPPFLAGS) $(SRCS) -o $(BIN) $(LDFLAGS) $(LIBS)
	@echo "Created target" $(BIN)

clean:
	@rm -f $(BIN)
	@rm -f *.o
	@rm -f *~
	@rm -f *.txt
	@echo "Cleaned files"
	
test: all test1 test2 test3 test4 test5 testclean

test1:
	@echo "Test case 1 running..."
	@./$(BIN) <test/input1 >temp.txt
	@cmp --silent temp.txt test/output1 || echo "test1 failed"
	
test2:
	@echo "Test case 2 running..."
	@./$(BIN) <test/input2 >temp.txt
	@cmp --silent temp.txt test/output2 || echo "test2 failed"
	
test3:
	@echo "Test case 3 running..."
	@./$(BIN) <test/input3 >temp.txt
	@cmp --silent temp.txt test/output3 || echo "test3 failed"

test4:
	@echo "Test case 4 running..."
	@./$(BIN) <test/input4 >temp.txt
	@cmp --silent temp.txt test/output4 || echo "test4 failed" 

test5:
	@echo "Test case 4 running..."
	@./$(BIN) <test/input5 >temp.txt
	@cmp --silent temp.txt test/output5 || echo "test5 failed"

testclean:
	@rm -rf temp.txt

