#include <iostream>
#include "DiamondTrap.h"

int main(void) {
    std::cout << "=== Construction ===" << std::endl;
    DiamondTrap dt("GloriousLeader");

    std::cout << "\n=== Actions ===" << std::endl;
    dt.attack("Target");
    dt.takeDamage(20);
    dt.beRepaired(10);
    dt.guardGate();
    dt.highFivesGuys();
    dt.whoAmI();

    std::cout << "\n=== Copy ===" << std::endl;
    DiamondTrap copyDt(dt);
    copyDt.whoAmI();

    std::cout << "\n=== Assignment ===" << std::endl;
    DiamondTrap assigned;
    assigned = dt;
    assigned.whoAmI();

    std::cout << "\n=== Destruction ===" << std::endl;
    return 0;
}
