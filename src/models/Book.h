#ifndef BOOK_H
#define BOOK_H

#include <string>

#include "hiberlite.h"

class Book
{
    friend class hiberlite::access;
    template<class Archive>
    void hibernate(Archive & ar)
    {
        ar & HIBERLITE_NVP(title);
    }

    public:
        std::string title;
};

HIBERLITE_EXPORT_CLASS(Book)
#endif
