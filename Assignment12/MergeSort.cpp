#include <string>
#include "MergeSort.h"

/**
 * Constructor.
 * @param name the name of the algorithm.
 */
MergeSort::MergeSort(string name) : ListSorter(name) {}

/**
 * Destructor.
 */
MergeSort::~MergeSort() {}

/**
 * Run the mergesort algorithm.
 * @throws an exception if an error occurred.
 */
void MergeSort::run_sort_algorithm()
    throw (string)
{
    // Defensive programming: Make sure we end up
    // with the same size list after sorting.
    int size_before = data.get_size();

    mergesort(data);

    // Check sizes.
    int size_after = data.get_size();
    if (size_before != size_after)
    {
        string message = "***** Size mismatch: before " +
                         to_string(size_before) + ", size after " +
                         to_string(size_after);
        throw message;
    }
}

/**
 * The mergesort algorithm recursively splits and merges data lists.
 * @param list the list of data to sort.
 */
void MergeSort::mergesort(LinkedList& list)
{
    if (list.get_size() > 1)
    {
        LinkedList temp1;  // the first sublist
        LinkedList temp2;  // the second sublist

        list.split(temp1, temp2);  // split the list into two sublists
        move_count += 2;

        mergesort(temp1);  // recursively sort the first sublist
        mergesort(temp2);  // recursively sort the second sublist

        merge(list, temp1, temp2);  // merge the two sublists back together
    }
}

/**
 * Merge two sublists back into a single list.
 * @param list the merged list.
 * @param sublist1 the first sublist.
 * @param sublist2 the second sublist.
 */
void MergeSort::merge(LinkedList& list,
                      LinkedList& sublist1, LinkedList& sublist2)
{
    Node *node1 = sublist1.get_head();
    Node *node2 = sublist2.get_head();

    list.reset();

    // Choose the head node from one sublist to add to the merged list.
    while ((node1 != nullptr) && (node2 != nullptr))
    {
        // Choose form the first sublist.
        if (node1->element.get_value() <= node2->element.get_value())
        {
            list.add(sublist1.remove_head());
            node1 = sublist1.get_head();
        }

        // Choose from the second sublist.
        else
        {
            list.add(sublist2.remove_head());
            node2 = sublist2.get_head();
        }

        move_count++;
        compare_count++;
    }

    // Concatenate the rest of the first sublist to the merged list.
    if (node1 != nullptr)
    {
        list.concatenate(sublist1);
        move_count++;
    }

    // Concatenate the rest of the second sublist to the merged list.
    if (node2 != nullptr)
    {
        list.concatenate(sublist2);
        move_count++;
    }
}

/**
 * Clear the data.
 */
void MergeSort::clear() { data.clear(); }
