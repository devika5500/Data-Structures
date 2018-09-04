#include "Node.h"
#include "Element.h"

/**
 * Default constructor.
 */
Node::Node() : next(nullptr) {}

/**
 * Constructor.
 * @param elmt the element contained in this node.
 */
Node::Node(const Element elmt) : element(elmt), next(nullptr) {}

/**
 * Destructor.
 */
Node::~Node() {};
