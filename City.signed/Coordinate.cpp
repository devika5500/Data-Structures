#include "Coordinate.h"
#include <string>
#include <vector>
#include <iostream>
/**
 * Maximum latitude and minimum longitude for this app's input data.
 */
const double Coordinate::MAX_LATITUDE  =   49.373112;
const double Coordinate::MIN_LONGITUDE = -124.769867;

/***** Complete this class. *****/

Coordinate::Coordinate() : latitude(0),longitude(0)
{

}


Coordinate::Coordinate(double latitude_value, double longitude_value):latitude(latitude_value),longitude(longitude_value)
{


}

Coordinate::~Coordinate()
{
   
}
double Coordinate::get_latitude() const
{
	return latitude;
}

double Coordinate::get_longitude() const
{
	return longitude;
}

istream& operator >>(istream& in, Coordinate& coordinate)
{

	string str;
	getline(in,str,',');
	coordinate.latitude = atof(str.c_str());
	getline(in,str,'\n');
	coordinate.longitude = atof(str.c_str());

	return in;

}
