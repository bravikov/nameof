TEST = test
TEST_SOURCES = test.cpp

runtest: $(TEST)
	./$(TEST)

$(TEST): $(TEST_SOURCES) ../nameof.h
	g++ -Wall -W -pedantic -std=c++11 -o $(TEST) $(TEST_SOURCES) -lboost_unit_test_framework

clean:
	rm -f $(TEST)
