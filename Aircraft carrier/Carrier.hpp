#ifndef CARRIER_H
#define CARRIER_H

#include "FunctionTools.hpp"
#include "Exceptions.hpp"
#include "Aircraft.hpp"
#include "F16.hpp"
#include "F35.hpp"
#include <string>
#include <vector>

class Carrier {
  private:
    std::vector<Aircraft*> platform;
    int ammo_storage;
    int hp;
    int total_damage;
    int sum_of_given_damage;
  public:
    Carrier(int, int);
    void add_aircraft(std::string);
    std::string get_status();
    int get_hp();
    void fill_all_aircraft();
    void fight(Carrier&);
    void set_total_damage(int);
};

#endif // CARRIER_H

