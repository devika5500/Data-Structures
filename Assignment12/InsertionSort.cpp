#include "InsertionSort.h"

/**
 * Constructor.
 * @param name the name of the algorithm.
 */
InsertionSort::InsertionSort(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
InsertionSort::~InsertionSort() {}

/**
 * Run the insertion sort algorithm.
 * @throws an exception if an error occurred.
 */
void InsertionSort::run_sort_algorithm() throw (string)
{
    // During each pass ...
    for (int pass = 0; pass < size-1; pass++)
    {
        int i = pass + 1;
        Element tmp = data[i];  // the next data element to check
        int j = i;

        // ... the next data element drifts into
        // its proper place in the sorted portion
        // by comparing adjacent elements.
        while ((j > 0) && (tmp < data[j-1]))
        {
            data[j] = data[j-1];
            move_count++;
            compare_count++;
            j--;
        }

        if (j > 0) compare_count++;

        // Move the next element into its proper place
        // if it isn't already there.
        if (i != j)
        {
            data[j] = tmp;
            move_count++;
        }
    }
}
