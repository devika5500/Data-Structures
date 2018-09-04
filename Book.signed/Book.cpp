#include "Book.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

Book::Book() : isbn(" "),last(" "),first(" "),title(" "),category(Category::NONE)
{
}

Book::Book(string isbn, string last, string first, string title, Category category) : isbn(isbn),last(last),first(first),title(title),category(category)
{
}

Book::~Book()
{
}

string Book::get_isbn() const
{
	return isbn;
}

string Book::get_last() const
{
	return last;
}

string Book::get_first() const
{
	return first;
}

string Book::get_title() const
{
	return title;
}

Book::Category Book::get_category() const
{
	return category;
}

istream& operator >>(istream& in, Book& obj)
{
   getline(in,obj.isbn,',');
   obj.isbn.erase(0,1);
   getline(in,obj.last,',');
   getline(in,obj.first,',');
   getline(in,obj.title,',');
   string str;
   getline(in,str);

   if(str=="fiction")
   {
	   obj.category = Book::Category::FICTION;
   }
   else if(str=="technical")
   {
	   obj.category = Book::Category::TECHNICAL;
   }
   else if(str=="history")
   {
	   obj.category = Book::Category::HISTORY;
   }
   else
   {  
	   obj.category = Book::Category::NONE;
   }
 return in;
}

ostream& operator <<(ostream& out,const Book& obj1)
{
   out << "Book{ISBN=" << obj1.isbn << ", last=" << obj1.last << ", first="<< obj1.first << ", title=" << obj1.title << ", category=" << obj1.category << "}";
	return out;
}

ostream& operator <<(ostream& out,const Book::Category& category)
{
   if(category == Book::Category::FICTION) 
   {
      out<<"fiction";
   }
   else if(category == Book::Category::HISTORY) 
   {
   out<<"history";
   }
   else if(category == Book::Category::TECHNICAL)
   {
      out<<"technical";
   }
   else 
   {
      out<<"none";
   }
	
}



