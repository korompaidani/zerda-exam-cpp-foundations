#include <iostream>
#include "Aircraft.hpp"
#include "F16.hpp"
#include "F35.hpp"
#include "Carrier.hpp"

using namespace std;

int main() {

Carrier c1(5000, 5000);
c1.add_aircraft("F16");
c1.add_aircraft("F35");
c1.add_aircraft("F16");
c1.add_aircraft("F35");

Carrier c2(5000, 5000);
c2.add_aircraft("F16");
c2.add_aircraft("F35");

c1.fill_all_aircraft();
c2.fill_all_aircraft();

cout << c1.get_status() << endl;
cout << c2.get_status() << endl;

c1.fight(c2);
cout << c1.get_status() << endl;
cout << c2.get_status() << endl;

cout << "c1 hp = " << c1.get_hp() << endl;
cout << "c2 hp = " << c2.get_hp() << endl;

  return 0;
}

