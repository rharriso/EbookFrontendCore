#include <iostream>
#include "hiberlite.h"
#include "models/Book.h"

using namespace std;

int main(){
    Book b;
    b.id = 10;

    hiberlite::Database db;
    db.open("database.name.ok.db");
}
