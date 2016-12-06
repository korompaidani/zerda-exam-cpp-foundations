#include "Carrier.hpp"

Carrier::Carrier(int init_ammo, int init_hp) {
  platform.resize(0, NULL);
  this->ammo_storage = init_ammo;
  this->hp = init_hp;
  this->total_damage = 0;
  this->sum_of_given_damage = 0;
}

void Carrier::add_aircraft(std::string in_type) {
  if (in_type == "F16") {
    platform.push_back(new F16);
  }
  else if(in_type == "F35") {
    platform.push_back(new F35);
  }
}

std::string Carrier::get_status() {
  std::string temp_status = "Aircraft count: ";
  temp_status += int_to_string(this->platform.size());
  temp_status += ", Ammo Storage: ";
  temp_status += int_to_string(this->ammo_storage);
  temp_status += ", Total damage: ";
  temp_status += int_to_string(this->total_damage);
  temp_status += "\nAircrafts:\n";
  for (int i = 0; i < platform.size(); i++) {
     temp_status += platform[i]->get_status();
     temp_status += "\n";
  }
  return temp_status += "\n";
}

int Carrier::get_hp() {
  return this->hp;
}

void Carrier::fill_all_aircraft() {
  for (int i = 0; i < platform.size(); i++) {
    if (platform[i]->get_type() == "F35") {
      platform[i]->refill(ammo_storage);
    }
  }
  for (int i = 0; i < platform.size(); i++) {
    if (platform[i]->get_type() == "F16") {
      platform[i]->refill(ammo_storage);
    }
  }
}

void Carrier::fight(Carrier& c_other) {
  for (int i = 0; i < platform.size(); i++) {
    sum_of_given_damage += platform[i]->get_ammo_storage();
    platform[i]->fight();
  }
  c_other.set_total_damage(sum_of_given_damage);
  sum_of_given_damage = 0;
}

void Carrier::set_total_damage(int in_damage) {
  total_damage += in_damage;
  this->hp -= in_damage;
  if_hp_null(hp);
}

///It should take another carrier as a refrence parameter and fire all the ammo from
///the aircraft to it than substract all the damage from it's health points
