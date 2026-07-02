#include "ClapTrap.h"
#include <iostream>

static void printSeparator(const std::string& title)
{
    std::cout << "\n==================== " << title << " ====================\n" << std::endl;
}

static void printStatus(const ClapTrap& c)
{
    std::cout << "[Status] " << c.getName()
              << " | HP: " << c.getHitPoints()
              << " | Energy: " << c.getEnergyPoints()
              << " | Attack: " << c.getAttackDamage() << std::endl;
}

int main(void)
{
    /* ============================================================
       1. CONSTRUCTOR & DESTRUCTOR ORDER
       ============================================================ */
    printSeparator("CONSTRUCTOR / DESTRUCTOR ORDER");
    {
        ClapTrap alpha("Alpha");
        ClapTrap beta("Beta");
        // Destructors will fire automatically at end of scope
    }

    /* ============================================================
       2. NORMAL OPERATIONS
       ============================================================ */
    printSeparator("NORMAL ATTACK / DAMAGE / REPAIR");
    ClapTrap clap("Clappy");

    printStatus(clap);          // HP:10 Energy:10 Attack:0
    clap.attack("Skag");        // Energy -> 9
    printStatus(clap);

    clap.takeDamage(3);         // HP -> 7
    printStatus(clap);

    clap.beRepaired(4);         // HP -> 11, Energy -> 8
    printStatus(clap);

    /* ============================================================
       3. ENERGY DEPLETION
       Attack & repair cost 1 energy. After 10 attacks + 1 repair,
       energy should be 0. Further actions must fail.
       ============================================================ */
    printSeparator("ENERGY DEPLETION");
    ClapTrap runner("Runner");
    printStatus(runner);

    // Exhaust all 10 energy points via attacks
    for (int i = 0; i < 10; ++i)
    {
        runner.attack("Target");
    }
    printStatus(runner);        // Energy: 0

    // These must fail: no energy left
    runner.attack("Target");    // fail
    runner.beRepaired(5);       // fail

    /* ============================================================
       4. HP DEPLETION
       Taking lethal damage should set HP to 0.
       With 0 HP, ClapTrap cannot attack or repair.
       ============================================================ */
    printSeparator("HP DEPLETION");
    ClapTrap tank("Tank");
    tank.takeDamage(10);        // HP -> 0
    printStatus(tank);

    tank.attack("Enemy");       // fail: no HP
    tank.beRepaired(5);         // fail: no HP
    tank.takeDamage(5);         // should handle gracefully (already dead)

    /* ============================================================
       5. OVERKILL DAMAGE
       Ensure HP does not underflow into negative values.
       ============================================================ */
    printSeparator("OVERKILL DAMAGE");
    ClapTrap fragile("Fragile");
    fragile.takeDamage(999);    // HP should cap at 0
    printStatus(fragile);

    /* ============================================================
       6. ZERO ATTACK DAMAGE
       Default attack damage is 0. Attack should still cost energy
       and print the message, but cause 0 damage.
       ============================================================ */
    printSeparator("ZERO ATTACK DAMAGE");
    ClapTrap weakling("Weakling");
    weakling.attack("Dummy");   // 0 damage, Energy -> 9
    printStatus(weakling);

    /* ============================================================
       7. MULTIPLE REPAIRS & ENERGY DRAIN
       ============================================================ */
    printSeparator("REPAIR ENERGY DRAIN");
    ClapTrap healer("Healer");
    healer.takeDamage(5);       // HP -> 5
    healer.beRepaired(2);       // HP -> 7,  Energy -> 9
    healer.beRepaired(2);       // HP -> 9,  Energy -> 8
    healer.beRepaired(2);       // HP -> 11, Energy -> 7
    printStatus(healer);

    /* ============================================================
       8. COPY CONSTRUCTOR & ASSIGNMENT
       ============================================================ */
    printSeparator("COPY SEMANTICS");
    ClapTrap original("Original");
    original.takeDamage(2);     // HP -> 8
    printStatus(original);

    ClapTrap copy(original);    // Copy constructor
    printStatus(copy);          // Should mirror original's state

    ClapTrap assigned("Assigned");
    assigned = original;        // Copy assignment
    printStatus(assigned);

    /* ============================================================
       9. DEFAULT CONSTRUCTOR (if you keep it)
       ============================================================ */
    printSeparator("DEFAULT CONSTRUCTOR");
    ClapTrap unnamed;           // Should initialize to default values
    printStatus(unnamed);

    printSeparator("END OF TESTS");
    return 0;
}
