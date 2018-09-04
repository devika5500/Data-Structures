#include <cmath>
#include "Node.h"

/***** Complete this class. *****/
Node::Node() : next(nullptr),previous(nullptr),row(0),col(0)
{
}

Node::Node(Coordinate& obj)
{
	convert_coordinate(obj);
}

Node::Node(City& city)
{
	name = city.get_name();
	state = city.get_state();
	Coordinate CityCoordinates;
	CityCoordinates = city.get_coordinate();
	convert_coordinate(CityCoordinates);
   next = nullptr;
   this->city = city;
}


Node::~Node()
{
   
}

int Node::get_row() const
{
	return row;
}

int Node::get_col() const
{
	return col;
}

string Node::get_name() const
{
	return name;
}

string Node::get_state() const
{
	return state;
}

City Node::get_city() const
{
	return city;
}

void Node::convert_coordinate(const Coordinate& coordinate)
{
    row = round(2*(Coordinate::MAX_LATITUDE - coordinate.get_latitude()));
    col = round(2*(coordinate.get_longitude() - Coordinate::MIN_LONGITUDE));
}


bool Node::operator >(const Node& other)
{
	bool flag;
	if(row>other.row)
	{
		flag = true;
	}
	else if(row == other.row)
	{
		if(col>= other.col)
		{
			flag = true;
		}

	}
	else
	{
	   flag = false;
	}
	return flag;

}


ostream& operator <<(ostream& out,const Node& node)
{
   if(node.name != "")
   {
      out << "*" << node.name <<" "<< node.state;
   }
   else
   {
      out<<"#";
   }
   return out;
}
