#include <string>
#include <stdio.h> 
#include <stdlib.h>   
#include <iostream>
#include <fstream>

using namespace std;

#include "Commander.h"
#include "Utils.h"


int main(int argc, char ** argv) {
	
	if (argc <= 4) {
		cout << "Need more params first param is memory size in MB, second param is max thread count, third param is unsorted binary file and fourth param is sorted file" << endl;
		return 0;
	}
	
	uint mem_size = atoi(argv[1]);
	uint max_thread_count = atoi(argv[2]);
	string unsorted_file = string(argv[3]);
	string sorted_file = string(argv[4]);

	if (mem_size == 0) {
		cout << "Memory size can't be zero";
		return 0;
	}
	
	if (max_thread_count == 0) {
		cout << "Max thread count can't be zero";
		return 0;
	}

	try {
		//f.generateBinaryFile("unsorted.bin", 16000001);
		//f.checkSortedFile("unsorted.bin");
		
		Commander c(mem_size, max_thread_count, unsorted_file, sorted_file);
		c.sort();
		
		Utils f = Utils();
		f.checkSortedFile("sorted.bin");
		
	} catch (std::exception & exc) {
		cout << exc.what() << endl;
	}
	
	return 0;
}

