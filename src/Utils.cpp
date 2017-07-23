#include "Utils.h"

#include <ctime>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>



void Utils::generateBinaryFile (const std::string file_name, const uint sign_number) {
	ofstream out(file_name, ios::binary | ios::out | ios::in);
	uint buff_size = MAX_BUFFER_SIZE > sign_number ? sign_number : MAX_BUFFER_SIZE;

    std::vector<int32_t> buff(buff_size);
    srand(time(0));
    uint pos = 0;
    do {

    	out.seekp(pos, ios::beg);
    	for (uint i = 0; i < buff_size; i++) {
    		buff[i] =  (i % 2 == 0 ? -1 : 1) * rand() % 25;
	    }

	    out.write(reinterpret_cast<const char*>(&buff[0]), buff_size * sizeof(int32_t));
	    pos += buff_size;

    } while (pos < sign_number);
	
	out.close();
}


void Utils::checkSortedFile (std::string file_name) {
	map<int, int> stat;

	uint buff_size = 1024 * 1024  * 64;
	ifstream in(file_name, ios::binary | ios::ate);
	std::vector<int32_t> buffer(buff_size);
	uint pos = 0;
	bool is_valid = true;
	uint read_bytes = 0;
	do  {
		in.seekg(pos, ios::beg);
		in.read(reinterpret_cast<char*>( & buffer[0] ),  buff_size * sizeof(int32_t));
		read_bytes = in.gcount();
		
		int value = buffer[0];

		for (uint i = 0; i < (read_bytes / sizeof(int32_t)); i++) {
			stat[buffer[i]] += 1;
			if (is_valid && buffer[i] < value) {
				is_valid = false;
	   		}
    	}
    	pos += buff_size * sizeof(int32_t);
	} while(read_bytes == buff_size * sizeof(int32_t));

	if (!is_valid) {
		cout << "File is not sorted" << endl;
	} else {
		cout << "File is sorted" << endl;
	}
	uint count = 0;
	for (std::map<int,int>::iterator it = stat.begin(); it != stat.end(); ++it) {
		cout << "number " << it->first << " : have count " << it->second << endl;
		count += it->second;
	}
	cout << "all number count :" << count << " and in bytes " << count * sizeof(int32_t) << endl;
}

void  Utils::mergeSortVectors(vector<int32_t> * src, vector<int32_t> * buffer, uint spos, uint size) {
    uint i = 0, j = 0, k = 0;

    while (i < spos && j < size - spos)  
       (*buffer)[k++] = (*src)[i] < (*src)[j + spos] ? (*src)[i++] :  (*src)[j++ + spos];

    while (i < spos)  
        (*buffer)[k++] = (*src)[i++];

    while (j < size - spos)    
        (*buffer)[k++] = (*src)[j++ + spos];
}

void Utils::printVectorStat(vector<int32_t> * vec) {
	map<int, int> stat;

	for (uint i = 0; i < vec->size(); i++) {
		stat[(*vec)[i]] += 1;
	}

	for (std::map<int,int>::iterator it = stat.begin(); it != stat.end(); ++it) {
		cout << "number " << it->first << " : have count " << it->second << endl;
	}
}

int compare (const void * one, const void * two)
{
	return *((int*)one) - *((int*)two);   
}

