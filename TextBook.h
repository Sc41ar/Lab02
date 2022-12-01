#pragma once
#include "Book.h"
class TextBook :
    public Book
{
private:
    int course;
    string theme;
   
public :
    TextBook()
    {
        theme = "физика";
        course = 1;
    }
    void Input() override;
    TextBook operator= (Book b);
    //{

    //}
};

