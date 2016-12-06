#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>
#include <exception>

using namespace std;

void if_hp_null(int);

class Exceptions {
  public:
    Exceptions();
    const char* what(int) const throw();
};

#endif // EXCEPTIONS_H
