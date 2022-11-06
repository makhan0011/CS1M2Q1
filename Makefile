all: clean test
programtest: tests.cpp Q91.cpp 
	g++ -fsanitize=address --std=c++17 tests.cpp Q91.cpp -o programtest 
test: programtest 
	./programtest
clean:
	rm -f programtest a.out