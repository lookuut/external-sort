#pragma once

#include <string>
#include <sys/types.h>

using namespace std;

#define MAX_BUFFER_SIZE 64 * 1024 * 1024

class Utils {
public :
	Utils () {}
	void generateBinaryFile (const std::string file_name, const uint sign_number);
	void checkSortedFile (std::string file_name);
};

int compare (const void * one, const void * two);