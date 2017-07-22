#pragma once 

#include <mutex>
#include <vector>
#include <sys/types.h>

using namespace std;

#define MB 1024 * 1024

class Commander {

private:
	uint c_thread_count;
	uint c_mem_mb_size; //memsize in bytes
	
	string c_unsorted_file;
	string c_sorted_file;
	
	mutex * c_locker;
	
	uint c_file_size;
public: 
 	

 	Commander (const uint mem_size, const uint max_thread_count, const string unsorted_file, const string sorted_file);
 	void sort ();
 	void sortBlocks ();
 	void mergeSortedBlocks (); 

 	static void readBinaryFile(vector<int32_t> & buffer, const uint bpos, const uint pos, const uint bytes, ifstream & io);
 	static void writeBinaryFile(vector<int32_t> & buffer, const uint bpos, const uint size, const uint pos, ofstream & io);

 	~Commander();
};
