#include <iostream>
#include "Element.h"

using namespace std;

// Static member variables, which are global to the class.
long Element::copy_count;
long Element::destructor_count;

/**
 * Default constructor.
 */
Element::Element() : value(0) {}

/**
 * Constructor.
 * @param val the element's value.
 */
Element::Element(long val) : value(val) {}

/**
 * Copy constructor.
 * @param other the other element to be copied.
 */
Element::Element(const Element& other)
{
    value = other.value;
    copy_count++;
}

/**
 * Destructor.
 */
Element::~Element()
{
    destructor_count++;
}

/**
 * Getter.
 * @return the value.
 */
long Element::get_value() const { return value; }

/**
 * Getter.
 * @return the value of the global copy_count.
 */
long Element::get_copy_count() { return copy_count; }

/**
 * Getter.
 * @return the value of the global destructor_count.
 */
long Element::get_destructor_count() { return destructor_count; }

/**
 * Reset the values of the global counters.
 */
void Element::reset()
{
    copy_count = destructor_count = 0;
}

/**
 * Overloaded == operator.
 * @param elmt1 the first element
 * @param elmt2 the second element
 * @return true if the values of two elements are equal, else false.
 */
bool operator ==(const Element& elmt1, const Element& elmt2)
{
    return elmt1.value == elmt2.value;
}

/**
 * Overloaded < operator.
 * @param elmt1 the first element
 * @param elmt2 the second element
 * @return true if the value the first element is less than
 *              the value of the second element, else false.
 */
bool operator <(const Element& elmt1, const Element& elmt2)
{
    return elmt1.value < elmt2.value;
}

/**
 * Overloaded > operator.
 * @param elmt1 the first element
 * @param elmt2 the second element
 * @return true if the value the first element is greater than
 *              the value of the second element, else false.
 */
bool operator >(const Element& elmt1, const Element& elmt2)
{
    return elmt1.value > elmt2.value;
}

/**
 * Overloaded << operator.
 * @param ostream the output stream.
 * @param elmt the element to output.
 * @return the output stream.
 */
ostream& operator <<(ostream& outs, const Element& elmt)
{
    outs << elmt.get_value();
    return outs;
}
