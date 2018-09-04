#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include "Book.h"

using namespace std;

enum class StatusCode {OK, DUPLICATE, NOT_FOUND, INVALID_COMMAND};

//adds book data into vector, parameter i is index into vector where data is addes
StatusCode addBook(int &i,istream &input, vector<Book>& catalog );

//removes book data from vector
StatusCode removeBook(istream &input, vector<Book>& catalog, Book& b);

//display the data in the vector
vector<int> showBook(istream &input, vector<Book>& catalog);

//handles invalid commands
StatusCode invalid_cmd(istream &input);

//performs binary search
int find(const string isbn, const vector<Book>& catalog);

const string INPUT_FILE_NAME = "commands.in";

int main()
{
   ifstream input;
   input.open(INPUT_FILE_NAME);
   if (input.fail())
   {
      cout << "Failed to open " << INPUT_FILE_NAME << endl;
      return -1;
   }

   vector<Book> catalog;//book catalog

	char command;
   input >> command;//read the first command

 	while (!input.fail())
 	{
 	 	cout << endl << command << " ";
      int index;
      StatusCode status;
      Book book_obj;
 		
 		switch (command)
      {
        case '+':
                  status = addBook(index,input, catalog);
                  book_obj = catalog[index];
                  cout << "Inserted at index " << index << ": "<< book_obj << endl;
                  break;

        case '-':
                  status = removeBook(input, catalog, book_obj);
                  cout << "Removed " << book_obj << endl;
                  break;
        case '?':
                  {
                     vector<int> matches = showBook(input, catalog);
                     for (int i : matches) 
                     {
                        cout << catalog[i] << endl;
                     }
                     status = StatusCode::OK;
                     break;
                  }

        default:
                  status = invalid_cmd(input);
                  break;
      }
      if (status != StatusCode::OK) 
      {
         
         switch (status)
         {
            case StatusCode::INVALID_COMMAND:
            cout << "*** Invalid command ***" << endl;
            break;

            case StatusCode::NOT_FOUND:
            cout << "*** Book not found ***" << endl;
            break;
            
            case StatusCode::DUPLICATE:
            cout << "*** Duplicate ISDN ***" << endl;
            break;

            default: break;
         }
      }
		input >> command;
	}
   return 0;
}

StatusCode addBook(int& index,istream &input, vector<Book>& catalog)
{
    index = 0;
    Book book;
    input >> book;
    string isbn = book.get_isbn();
   //gives index where element is to be added
    for(int x=0;x<catalog.size();x++)
	 {
		string temp = catalog[x].get_isbn();
		if(isbn>temp)
		{
			index++;
		}
   }	

    if (index >= catalog.size())
    {
        catalog.push_back(book);        
        return StatusCode::OK;
    }
    else if (isbn == catalog[index].get_isbn())
    {
        return StatusCode::DUPLICATE;
    }
    else
    {
        catalog.insert(catalog.begin() + index, book); 
        return StatusCode::OK;
     }
}


StatusCode removeBook(istream &input, vector<Book>& catalog, Book& book)
{
    string isbn;
    input >> isbn;
    int index = find(isbn, catalog);
    
    if (index == -1)//no matching element exists
    {
      book = Book(isbn, "", "", "", Book::Category::NONE);
      return StatusCode::NOT_FOUND;
    }
    else
    {
      book = catalog[index];
      catalog.erase(catalog.begin() + index);
      return StatusCode::OK;
    }
}

vector<int> showBook(istream &input, vector<Book>& catalog)
{
   int size = catalog.size();
    string val;
    getline(input, val);
    vector<int> list;

    if (val == "")
    {
       cout << "All books in the catalog:" << endl;
       for (int i = 0; i < size; i++)
       {
          list.push_back(i);
       }
    }

    else if (val.find("isbn=") != val.npos)
    {
        string isbn = val.substr(val.find("=") + 1);
        cout << "Book with ISBN " << isbn << ":" << endl;
        int index = find(isbn, catalog);
	     if (index != -1) 
	     {
	        list.push_back(index);
	     }
    }

   else if (val.find("author=") != val.npos)
    {
        string last = val.substr(val.find("=") + 1);
        cout << "Books by author " << last << ":" << endl;
        for (int i = 0; i < size; i++)
	     {
	                Book book = catalog[i];
	                if (last == book.get_last()) list.push_back(i);
	     }
    }

    else if (val.find("category=") != val.npos)
    {
        string cat = val.substr(val.find("=") + 1);
        cout << "Books in category " << cat<< ":" << endl;
        Book::Category category;
	     if(cat=="fiction")
	     {
	        category = Book::Category::FICTION;
	     }
	     else if(cat == "history")
	     {
	        category = Book::Category::HISTORY;
	     }
	     else if(cat == "technical")
	     {
	         category = Book::Category::TECHNICAL;
	     }
        else
	     {
	        category = Book::Category::NONE;
	     }
       for (int i = 0; i < size; i++)
	    {
	        Book book = catalog[i];
	        if(category==book.get_category())list.push_back(i);
	     }
      }
      return list;
}

int find(const string isbn, const vector<Book>& catalog)
{
    int low = 0;
    int high = catalog.size();
      
    while (high>= low)
    {
        int mid = (low + high)/2;
        Book book = catalog[mid];

        if (isbn == book.get_isbn())
        {
            return mid;  //element found   
        }
        else if (isbn > book.get_isbn())
        {
           low  = mid + 1;//scan upper half
        }
        else
        {
           high = mid - 1;//scan lower half
        }
     }
      return -1; //element not in list
}

StatusCode invalid_cmd(istream &input)
{
    string line;
    getline(input, line);
    return StatusCode::INVALID_COMMAND;
}
