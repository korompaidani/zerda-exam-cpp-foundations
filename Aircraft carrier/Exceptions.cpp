#include "Exceptions.hpp"

void if_hp_null(int in_hp){
  if (in_hp < 1) {
    std::cout << "It's dead Jim :(" << endl;
  }
}

Exceptions::Exceptions() {
  //ctor
}

const char* Exceptions::what(int in_hp) const throw() {
  if (in_hp > 0) {
    return "ok";
  }
  else {
    return "It's dead Jim :(";
  }
}
