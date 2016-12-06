#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include "FunctionTools.hpp"
#include <string>
#include <sstream>

class Aircraft {
  private:
    int dammage;
    int ammo_storage;
  protected:
    std::string type;
    int max_ammo;
    int base_dammage;
  public:
    Aircraft();
    std::string get_type();
    int fight();
    void refill(int&);
    std::string get_status();
    int get_dammage();
    int get_ammo_storage();
    int get_max_ammo();
    int get_base_dammage();
};

#endif // AIRCRAFT_H
