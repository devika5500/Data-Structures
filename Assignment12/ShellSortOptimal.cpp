#include "ShellSortOptimal.h"

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
ShellSortOptimal::ShellSortOptimal(string name) :VectorSorter(name) {}

/**
 * Destructor.
 */
ShellSortOptimal::~ShellSortOptimal() {}

/**
 * Run the optimal shellsort algorithm.
 * According to Don Knuth:
 * h = 3*i + 1 for i = 0, 1, 2, ... used in reverse.
 * @throws an exception if an error occurred.
 */
void ShellSortOptimal::run_sort_algorithm() throw (string)
{
    // Compute highest h value.
    int h = 1;
    while (h < size) h = 3*h + 1;

    // For each value of h ...
    for (h = (h-1)/3; h >= 1; h = (h-1)/3)
    {
        // Perform an insertion sort with elements that are h apart.
        for (int pass = h; pass < size; pass++)
        {
            Element tmp = data[pass];  // next data element to check
            int j = pass;

            // The next data element drifts into its proper place
            // by comparing elements that are h apart.
            while ((j >= h) && (tmp < data[j-h]))
            {
                data[j] = data[j-h];
                move_count++;
                compare_count++;
                j -= h;
            }

            if (j >= h) compare_count++;

            // Move the next element into its proper place
            // if it isn't already there.
            if (pass != j)
            {
                data[j] = tmp;
                move_count++;
            }
        }
    }
}
