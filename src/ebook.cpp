#include <iostream>
#include <sqlite3.h>

#include "Book.h"

using namespace std;

int main(){
    Book b;
    b.id = 10;
    
    cout << "books" << endl;
    cout << b.id << endl;
    cout << "HEYO" << endl;

    sqlite3 *db;
    auto const rc = sqlite3_open("test.db", &db);

    if( rc ) {
        cerr << "Can't open database: " << sqlite3_errmsg( db ) << endl;
        return 0;
    } else {
        cout << "Database opened" << endl;
    }

    sqlite3_close( db );
}
