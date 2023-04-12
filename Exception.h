#include<exception>


class myexception:public exception
{ 

    virtual const char* what() const throw()
    {
      return "Invalid input! Enter again: ";
    }
    
};