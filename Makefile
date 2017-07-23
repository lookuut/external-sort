CC=g++
CFLAGS=-Wall -std=c++0x 

sort:
	$(CC) $(CFLAGS) -lpthread  src/main.cpp src/Utils.cpp src/Commander.cpp src/SortThread.cpp -o sort.out
checker:
	$(CC) $(CFLAGS) src/BinaryChecker.cpp src/Utils.cpp  -o binary_file_checker.out
generator: 
	$(CC) $(CFLAGS) src/BinaryGenerator.cpp src/Utils.cpp  -o binary_file_generator.out
clean: 
	rm -rf sort binary_file_checker binary_file_generator
