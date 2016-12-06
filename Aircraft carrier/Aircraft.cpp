#include "Aircraft.hpp"

Aircraft::Aircraft() {
  this->type = "";
  this->max_ammo = 0;
  this->base_dammage = 0;
  this->dammage = 0;
  this->ammo_storage = 0;
}

std::string Aircraft::get_type() {
  return this->type;
}

int Aircraft::fight() {
  int temp_ammo = ammo_storage * base_dammage;
  ammo_storage = 0;
  return temp_ammo;
}

void Aircraft::refill(int& in_ammo) {
  if (in_ammo >= max_ammo) {
    ammo_storage = max_ammo;
    in_ammo -= max_ammo;
  }
  else {
    ammo_storage = in_ammo;
    in_ammo = 0;
  }
}

std::string Aircraft::get_status() {
  std::string temp_stat = "Type ";
  temp_stat += this->type;
  temp_stat += ", Ammo: ";
  temp_stat += int_to_string(this->ammo_storage);
  temp_stat += ", Base Damage: ";
  temp_stat += int_to_string(this->base_dammage);
  temp_stat += ", All Damage: ";
  temp_stat += int_to_string(this->base_dammage * this->ammo_storage);
  return temp_stat;
}

int Aircraft::get_dammage() {
  return this->dammage;
}

int Aircraft::get_ammo_storage() {
  return this->ammo_storage;
}

int Aircraft::get_max_ammo() {
  return this->max_ammo;
}

int Aircraft::get_base_dammage() {
  return this->base_dammage;
}
