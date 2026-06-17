#include <iostream>
#include "ScavTrap.h"

int main(void) {
    std::cout << "=== Construction ===" << std::endl;
    ScavTrap st("GloriousLeader");

    std::cout << "\n=== Actions ===" << std::endl;
    st.attack("Target");
    st.takeDamage(20);
    st.beRepaired(10);
    st.guardGate();

    std::cout << "\n=== Assignment ===" << std::endl;
    ScavTrap assigned;
    assigned = st;

    std::cout << "\n=== Destruction ===" << std::endl;
    return 0;
}
