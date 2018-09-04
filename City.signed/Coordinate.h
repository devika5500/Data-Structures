/*
 * Coordinate.h
 *
 *  Created on: 21-Mar-2018
 *      Author: devikajadhav
 */

#ifndef COORDINATE_H_
#define COORDINATE_H_

#include <iostream>
#include <string>
using namespace std;

/**
 * A geographic coordinate.
 */
class Coordinate
{
public:

    /***** Commplete this class. *****/
	Coordinate();
	Coordinate(double latitude_val, double longitute_val);
	~Coordinate();
	
	double get_latitude() const;
	double get_longitude() const;
    /**
     * Overloaded input stream extraction operator
     * to read a coordinate from an input stream.
     * @param ins the input stream.
     * @param coordinate the coordinate to read.
     * @return the input stream.
     */
    friend istream& operator >>(istream& ins, Coordinate& coordinate);


    // Constants for this app's input data.
    static const double MAX_LATITUDE;
    static const double MIN_LONGITUDE;

private:
    double latitude;
    double longitude;
};



#endif /* COORDINATE_H_ */
