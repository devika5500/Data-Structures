#ifndef DATA_H_
#define DATA_H_

#include <iostream>
using namespace std;

/**
 * The class for the data elements that will be sorted.
 */
class Element
{
public:
    Element();
    Element(long val);
    Element(const Element& other);
    virtual ~Element();

    long get_value() const;

    // Access and reset the values of the static member variables.
    static long get_copy_count();
    static long get_destructor_count();
    static void reset();

    friend bool operator ==(const Element& elmt1, const Element& elmt2);
    friend bool operator < (const Element& elmt1, const Element& elmt2);
    friend bool operator > (const Element& elmt1, const Element& elmt2);

    friend ostream& operator <<(ostream& outs, const Element& elmt);

private:
    long value;

    // Static member variables, which are global to the class.
    // These variables exist independently from any Element objects.
    static long copy_count;
    static long destructor_count;
};

#endif /* DATA_H_ */
