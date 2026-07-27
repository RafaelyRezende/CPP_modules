#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    // ============================================================
    // TEST 1: Abstract class cannot be instantiated
    // ============================================================
    std::cout << "=== TEST 1: Abstract class instantiation ===" << std::endl;
    
    // Animal meta;                      // ❌ COMPILE ERROR: cannot instantiate abstract class
    // Animal* meta = new Animal();     // ❌ COMPILE ERROR: same reason
    
    // But pointers and references are fine:
    Animal* ptr = NULL;                 // ✅ OK: just a pointer
    (void)ptr;                           // Silence unused warning
    
    std::cout << "Animal is abstract — cannot be instantiated directly.\n" << std::endl;


    // ============================================================
    // TEST 2: Runtime polymorphism (same names as ex01)
    // ============================================================
    std::cout << "=== TEST 2: Runtime polymorphism ===" << std::endl;
    
    const Animal* j = new Dog();        // j = Dog (same name as ex01)
    const Animal* i = new Cat();        // i = Cat (same name as ex01)
    
    std::cout << "j->getType(): " << j->getType() << std::endl;
    std::cout << "i->getType(): " << i->getType() << std::endl;
    
    std::cout << "j->makeSound(): ";
    j->makeSound();                      // Output: Woof!
    
    std::cout << "i->makeSound(): ";
    i->makeSound();                      // Output: Meow!
    
    // Virtual destructor ensures proper cleanup:
    delete j;                            // Calls ~Dog() → ~Brain() → ~Animal()
    delete i;                            // Calls ~Cat() → ~Brain() → ~Animal()
    
    std::cout << std::endl;


    // ============================================================
    // TEST 3: Polymorphic array (mixed Dogs and Cats)
    // ============================================================
    std::cout << "=== TEST 3: Polymorphic array ===" << std::endl;
    
    const int size = 4;
    Animal* animals[size];
    
    for (int k = 0; k < size; k++)
    {
        if (k % 2 == 0)
            animals[k] = new Dog();
        else
            animals[k] = new Cat();
    }
    
    std::cout << "--- Making sounds ---" << std::endl;
    for (int k = 0; k < size; k++)
    {
        std::cout << "animals[" << k << "] (" << animals[k]->getType() << "): ";
        animals[k]->makeSound();
    }
    
    std::cout << "--- Deleting array ---" << std::endl;
    for (int k = 0; k < size; k++)
        delete animals[k];               // Virtual destructor = correct cleanup
    
    std::cout << std::endl;


    // ============================================================
    // TEST 4: Deep copy verification
    // ============================================================
    std::cout << "=== TEST 4: Deep copy ===" << std::endl;
    
    Dog original;
    original.getBrain()->setIdea(0, "I want a bone!");
    original.getBrain()->setIdea(1, "Chase the mailman!");
    
    Dog copy = original;                 // Copy constructor
    
    // Modify copy's brain ONLY
    copy.getBrain()->setIdea(0, "I want a blanket!");
    copy.getBrain()->setIdea(1, "Lick ice cream!");
    
    std::cout << "Original idea[0]: " << original.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy idea[0]:     " << copy.getBrain()->getIdea(0) << std::endl;
    
    std::cout << "Original idea[1]: " << original.getBrain()->getIdea(1) << std::endl;
    std::cout << "Copy idea[1]:     " << copy.getBrain()->getIdea(1) << std::endl;

    // If deep copy worked, original is unchanged:
    if (original.getBrain()->getIdea(0) == "I want a bone!")
        std::cout << "✅ Deep copy successful — independent Brains!" << std::endl;
    else
        std::cout << "❌ Shallow copy detected — shared Brain!" << std::endl;
    
    std::cout << std::endl;


    // ============================================================
    // TEST 5: Assignment operator (deep copy)
    // ============================================================
    std::cout << "=== TEST 5: Assignment operator ===" << std::endl;
    
    Dog assigned;
    assigned.getBrain()->setIdea(0, "Old idea");
    
    assigned = original;                 // Assignment operator
    
    assigned.getBrain()->setIdea(0, "New assigned idea");
    
    std::cout << "Original idea[0]: " << original.getBrain()->getIdea(0) << std::endl;
    std::cout << "Assigned idea[0]: " << assigned.getBrain()->getIdea(0) << std::endl;
    
    if (original.getBrain()->getIdea(0) == "I want a bone!")
        std::cout << "✅ Assignment deep copy works!" << std::endl;
    else
        std::cout << "❌ Assignment shallow copy!" << std::endl;
    
    std::cout << std::endl;


    // ============================================================
    // TEST 6: Self-assignment safety
    // ============================================================
    std::cout << "=== TEST 6: Self-assignment ===" << std::endl;
    
    Dog self;
    self.getBrain()->setIdea(0, "Self idea");
    self = self;                         // Should not crash or leak
    
    std::cout << "Self idea[0]: " << self.getBrain()->getIdea(0) << std::endl;
    std::cout << "✅ Self-assignment handled safely!" << std::endl;

    return 0;
}
