#include "Worker.hpp"
#include "Shovel_t.hpp"
#include "Shovel.hpp"
#include "Hammer.hpp"
#include "Workshop.hpp"

int main() {
    Worker james("james", 1, 2, 3, 0,0);
    Worker mike("mike", 1, 2, 3, 0,0);
    Shovel_t *shovel = new Shovel_t();
    Shovel *shovel_c = new Shovel(0);
    Hammer *hammer = new Hammer(0);
    Workshop *workshop1 = new Workshop();
    Workshop *workshop2 = new Workshop();

    james.equip_shovel(shovel);
    james.unequip_shovel();

    james.equip_tool(shovel_c);
    james.work();
    james.unequip_tool();

    james.equip_tool(hammer);
    james.work();
    
    workshop1->addWorker(&james);
    workshop1->addWorker(&mike);

    workshop1->excuteWorkDay();
    workshop2->addWorker(&james);
    james.unequip_tool();

    delete shovel_c;
    delete hammer;
    delete shovel;
    delete workshop1;
    delete workshop2;
    return 0;
}