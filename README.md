# External Sort implementation in C++

**External sorting** is a technique used to efficiently sort large datasets that don't fit entirely into the computer's memory (RAM). It involves dividing the data into smaller chunks that can be sorted in memory, and then merging these sorted chunks to produce the final sorted output. One commonly used algorithm for external sorting is the Merge Sort algorithm. Here's how it works:

## Merge Sort Algorithm for External Sorting:

1. Divide into Chunks (Runs): The initial step involves dividing the large dataset into smaller chunks that can fit into memory. These smaller chunks are often called "runs". Each run is sorted individually using an internal sorting algorithm, typically a quicksort or heapsort.

2. Sort Runs: Each run is loaded into memory, sorted using an internal sorting algorithm, and then written back to external storage. This step is performed until all runs are sorted.

3. Merge Runs: In this step, the sorted runs are merged together to produce larger sorted runs. This is done by comparing the smallest elements from each run and selecting the smallest element to be placed in the final sorted output. As elements are selected and moved to the output, the space becomes available in memory to load more elements from external storage.

4. Repeat Merging: The merging step continues until all the runs are merged into a single sorted output. This process involves multiple iterations of merging and continues until there's only one run left, which is the fully sorted dataset.

The key advantage of merge sort in the context of external sorting is that it minimizes the amount of data loaded into memory at any given time, and it works well with sequential access patterns.


## compile 
g++ -Wall -std=c++0x -lpthread  src/main.cpp src/Utils.cpp src/Commander.cpp src/SortThread.cpp -o ex
./ex {max memory in MB} {max thread count} {unsorted binary file} {sorted finary file name}

