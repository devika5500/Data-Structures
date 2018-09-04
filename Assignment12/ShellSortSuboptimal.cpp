#include "ShellSortSuboptimal.h"

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
ShellSortSuboptimal::ShellSortSuboptimal(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
ShellSortSuboptimal::~ShellSortSuboptimal() {}

/**
 * Run the suboptimal shellsort algorithm.
 * @throws an exception if an error occurred.
 */
void ShellSortSuboptimal::run_sort_algorithm() throw (string)
{
    // Halve the diminishing increment h during each pass.
    for (int h = size/2; h >= 1; h /= 2)
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
            if (pass != j) {
                data[j] = tmp;
                move_count++;
            }
        }
    }
}
