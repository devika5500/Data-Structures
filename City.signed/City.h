/*
 * City.h
 *
 *  Created on: 21-Mar-2018
 *      Author: devikajadhav
 */

#ifndef CITY_H_
#define CITY_H_

#include <iostream>
#include <string>

#include "Coordinate.h"

using namespace std;

/**
 * City data.
 */
class City
{
public:

    /***** Complete this class. *****/
		City();
      City(string name, string state, Coordinate coordinate);
		~City();

		string get_name() const;
      string get_state() const;
      Coordinate get_coordinate() const;

    /**
     * Overloaded input stream operator to read a city
     * from an input stream.
     * @param ins the input stream.
     * @param city the city to read.
     * @return the input stream.
     */
    friend istream& operator >>(istream& ins, City& city);

    
private:
    string name;
    string state;
    Coordinate coordinate;
};


#endif /* CITY_H_ */
