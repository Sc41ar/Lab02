#pragma once
#include "Book.h"
class TextBook :
    protected Book
{
private:
    int course;
    string theme;
    TextBook()
    {
        theme = "������";
        course = 1;
    }
public :
    void Input() override;
    TextBook operator= (Book b);
    //{

    //}
};

