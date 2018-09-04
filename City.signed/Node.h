/*
 * Node.h
 *
 *  Created on: 21-Mar-2018
 *      Author: devikajadhav
 */

#ifndef NODE_H_
#define NODE_H_

#include "City.h"
#include "Coordinate.h"

/**
 * A node of a linked list.
 */
class Node
{
public:

    /***** Complete this class. *****/

	Node();							
	Node(Coordinate& obj);	
	Node(City& city);
	~Node();
    Node *next;
    Node *previous; 


    int get_row() const;
    int get_col() const;
    string get_name() const;
    string get_state() const;
    City get_city() const;
    /**
     * Overloaded > operator to compare two nodes.
     */
    bool operator >(const Node& other);
    


    /**
     * Overloaded stream output insertion operator
     * to output a node to the output stream.
     * @param outs the output stream.
     * @param node the node to output.
     * @return the output stream.
     */
    friend ostream& operator <<(ostream& out, const Node& node);

private:
    string name;   
    string state;  
    int row;       
    int col;       
    City city;
        /**
         * Convert a coordinate to a row and a column.
         * @param coordinate the coordinate to convert.
         */
        void convert_coordinate(const Coordinate& coordinate);
    };


#endif /* NODE_H_ */
