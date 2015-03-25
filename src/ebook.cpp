#include <iostream>
#include <string>

#include "hiberlite.h"
#include "models/Book.h"

using namespace std;

int main(){
    hiberlite::Database db;
    db.open("database.name.ok.db");
    db.registerBeanClass<Book>();


    auto book = db.createBean<Book>();
    cout << endl << "Enter a book title: " << endl;
    string bookTitle;
    cin >> bookTitle;
    book->title = bookTitle;

    cout << "Book saved: ( " << book.get_id()
     << " ) " << book->title;  

    auto books = db.getAllBeans<Book>();
    cout << books.size() << " Books stored: " << endl;
    for ( auto b : books){
        cout << b.get_id() << " " << b->title << endl;
    }
}
