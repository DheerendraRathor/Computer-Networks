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
	
test: all test1 test2 test3 test4 test5 eval1 eval2 eval3 eval4 eval5 testclean

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
	@echo "Test case 5 running..."
	@./$(BIN) <test/input5 >temp.txt
	@cmp --silent temp.txt test/output5 || echo "test5 failed"

eval1:
	@echo "Evaluation test case 1 running..."
	@./$(BIN) <test/evalinp1 >temp.txt
	@cmp --silent temp.txt test/evalout1 || echo "Evaluation 1 failed"

eval2:
	@echo "Evaluation test case 2 running..."
	@./$(BIN) <test/evalinp2 >temp.txt
	@cmp --silent temp.txt test/evalout2 || echo "Evaluation 2 failed"

eval3:
	@echo "Evaluation test case 3 running..."
	@./$(BIN) <test/evalinp3 >temp.txt
	@cmp --silent temp.txt test/evalout3 || echo "Evaluation 3 failed"

eval4:
	@echo "Evaluation test case 4 running..."
	@./$(BIN) <test/evalinp4 >temp.txt
	@cmp --silent temp.txt test/evalout4 || echo "Evaluation 4 failed"

eval5:
	@echo "Evaluation test case 5 running..."
	@./$(BIN) <test/evalinp5 >temp.txt
	@cmp --silent temp.txt test/evalout5 || echo "Evaluation 5 failed"

eval6:
	@echo "Evaluation test case 6 running..."
	@./$(BIN) <test/evalinp6 >temp.txt
	@cmp --silent temp.txt test/evalout6 || echo "Evaluation 6 failed"

testclean:
	@rm -rf temp.txt

