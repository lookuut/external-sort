# external-sort

compile 
g++ -Wall -std=c++0x -lpthread  src/main.cpp src/Utils.cpp src/Commander.cpp src/SortThread.cpp -o ex
./ex {max memory in MB} {max thread count} {unsorted binary file} {sorted finary file name}

