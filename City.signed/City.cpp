#include "City.h"

City::City(): name(""), state("")
{
	Coordinate temp;
	coordinate = temp;
}

City::City(string name, string state, Coordinate coordinate):name(name), state(state), coordinate(coordinate)
{ 
   
}

City::~City()
{
   
}

string City::get_name() const
{
	return name;
}

string City::get_state() const
{
	return state;
}

Coordinate City::get_coordinate() const
{
	return coordinate;
}

istream& operator >>(istream& in, City& city)
{
   string str;
	getline(in, city.name, ',');
	getline(in, city.state, ',');
	getline(in, str, ',');
	double latitude_val=atof(str.c_str());
	getline(in, str);
	double longitude_val=atof(str.c_str());
	Coordinate cd(latitude_val, longitude_val);
	city.coordinate =  cd;
	return in;
}


