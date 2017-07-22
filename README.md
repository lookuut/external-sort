# external-sort

compile 
g++ -Wall src/main.cpp src/Utils.cpp src/Commander.cpp src/SortThread.cpp  -o exec

./exec {max memory in MB} {max thread count} {unsorted binary file} {sorted finary file name}

