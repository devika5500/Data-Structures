/*
 * Book.h
 *
 *  Created on: 05-Mar-2018
 *      Author: devikajadhav
 */

#ifndef BOOK_H_
#define BOOK_H_
#include <string>
using namespace std;

class Book
{
   public:

    enum class Category { FICTION, HISTORY, TECHNICAL, NONE };
    
    Book();
    Book(string isbn, string last, string first, string title, Category category);
   ~Book();

    string get_isbn() const;
    string get_last() const;
    string get_first() const;
    string get_title() const;
    Category get_category() const;
    
    friend istream& operator >>(istream& in,Book& obj);
    friend ostream& operator <<(ostream& out,const Book& obj1);
    friend ostream& operator <<(ostream& out,const Book::Category& category);

   private:
   
    string isbn,last,first,title;
    Category category;
};
#endif /* BOOK_H_ */
